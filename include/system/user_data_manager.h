#ifndef USER_DATA_MANAGER_H
#define USER_DATA_MANAGER_H

#include "user/user_type.h"
#include "utility/utility_type.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

template <typename T> class UserDataManager
{
public:
    UserDataManager(UserType user_type);

    void addData(T data);
    void removeUser(const char *id);

    void readFromFile();
    void saveToFile() const;

    void inputData();
    void outputData() const;

    void sortDataById();
    void sortDataByName();
    void sortDataByFee(UtilityType utility_type);

protected:
    std::vector<std::unique_ptr<T>> vdata;
    UserType user_type;
};

template <typename T> UserDataManager<T>::UserDataManager(UserType user_type) : user_type(user_type) {}

template <typename T> void UserDataManager<T>::addData(T data) { vdata.push_emplace(data); }

template <typename T> void UserDataManager<T>::removeUser(const char *id)
{
    for (auto it = vdata.begin(); it != vdata.end(); ++it) {
        if ((*it)->getId() == id) {
            vdata.erase(it);
            break;
        }
    }
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

template <typename T> void UserDataManager<T>::sortDataByFee(UtilityType utility_type)
{
    std::sort(vdata.begin(), vdata.end(), [&](const T &data_1, const T &data_2) {
        return data_1->utility[utility_type] < data_2->utility[utility_type];
    });
}

#endif