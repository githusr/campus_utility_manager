#ifndef USER_DATA_MANAGER_H
#define USER_DATA_MANAGER_H

#include "user/user_type.h"
#include "utility/utility_type.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename T> class UserDataManager
{
public:

    void addUser(const std::string &id, const std::string &name, const int &grade);
    void addData(T data);
    bool searchData(const std::string &id, const std::string &name);
    void removeUser(const std::string &id);
    auto isUserExist(const std::string &id) const;

    void readFromFile();
    void saveToFile() const;

    void inputData();
    void outputData() const;

    void sortDataById();
    void sortDataByName();
    void sortDataByFee(const auto &utility_type);
    void reverseData();

private:
    std::vector<std::unique_ptr<T>> vdata;
};

template <typename T> void addUser(const std::string &id, const std::string &name, const int &grade)
{
    UserDataManager<T>::searchData(id, name);
}

template <typename T> void UserDataManager<T>::addData(T data) { vdata.push_emplace(data); }

template <typename T> bool UserDataManager<T>::searchData(const std::string &id, const std::string &name)
{
    for (const auto &data : vdata) {
        if (data->getId() == id || data->getName() == name) {
            std::cout << *data;
            return true;
        }
    }
    throw std::runtime_error("未找到该用户");
    return false;
}

template <typename T> void UserDataManager<T>::removeUser(const std::string &id)
{
    for (auto it = vdata.begin(); it != vdata.end(); ++it) {
        if ((*it)->getId() == id) {
            vdata.erase(it);
            break;
        }
    }
    std::find_if(vdata.begin(), vdata.end(), [&](const auto &data) {
        return data->getId() == id;
    })
}

template <typename T> void UserDataManager<T>::readFromFile()
{
    const char *filename = "../data/input.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("文件打开失败");
    }
    while (!file.eof()) {
        T data;
        file >> data;
        if (file.fail()) {
            throw std::runtime_error("读取出错");
            break;
        }
        vdata.push_emplace(data);
    }
    file.close();
}

template <typename T> void UserDataManager<T>::saveToFile() const
{
    const char *filename = "../data/output.txt";
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("文件打开失败");
    }
    for (const auto &data : vdata) {
        file << *data;
    }
    file.close();
}

template <typename T> void UserDataManager<T>::inputData()
{
    T data;
    while (std::cin >> data) {
        vdata.push_emplace(data);
    }
}

template <typename T> void UserDataManager<T>::outputData() const
{
    for (const auto &data : vdata) {
        std::cout << *data;
    }
}

template <typename T> void UserDataManager<T>::sortDataById()
{
    std::sort(vdata.begin(), vdata.end(),
              [](const T &data_1, const T &data_2) { return data_1->getId() < data_2->getId(); });
}

template <typename T> void UserDataManager<T>::sortDataByName()
{
    std::sort(vdata.begin(), vdata.end(),
              [](const T &data_1, const T &data_2) { return data_1->getName() < data_2->getName(); });
}

template <typename T> void UserDataManager<T>::sortDataByFee(const auto &utility_type)
{
    std::sort(vdata.begin(), vdata.end(), [&](const T &data_1, const T &data_2) {
        return data_1->getUtilityData(utility_type) < data_2->getUtilityData(utility_type);
    });
}

template <typename T> void UserDataManager<T>::reverseData() { std::reverse(vdata.begin(), vdata.end()); }

#endif