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

    auto searchDataByAdmin(const std::string &id) const;
    auto searchDataByUser(const std::string &id, const std::string &name) const;
    auto isUserExist(const std::string &id) const;
    void addUser();
    void addData();
    void removeUser();

    void readFromFile();
    void saveToFile() const;

    void inputData();
    void outputData() const;
    void outputHistory() const;

    void sortDataById();
    void sortDataByName();
    void sortDataByFee(const auto &utility_type);
    void reverseData();

public:
    UserDataManager(std::string input_filename, std::string output_filename);

private:
    std::vector<std::shared_ptr<T>> vdata;
    std::string input_filename;
    std::string output_filename;
};

template<typename T> auto UserDataManager<T>::searchDataByAdmin(const std::string &id) const
{
    return std::find_if(vdata.begin(), vdata.end(), [&](const auto &data) {
        return data->getId() == id;
    });
}

template<typename T> auto UserDataManager<T>::searchDataByUser(const std::string &id, const std::string &name) const
{
    return std::find_if(vdata.begin(), vdata.end(), [&](const auto &data) {
        return data->getId() == id && data->getName() == name;
    });
}

template<typename T> auto UserDataManager<T>::isUserExist(const std::string &id) const
{
    return searchDataByAdmin(id) != vdata.end();
}

template <typename T> void UserDataManager<T>::addUser()
{
    T data;
    std::cin >> data;
    if (isUserExist(data->getId())) {
        throw std::runtime_error("用户已存在");
        return;
    }
    vdata.emplace_back(std::make_shared<T>(std::move(data)));
}

template <typename T> void UserDataManager<T>::addData()
{
    std::string id;
    std::cin >> id;
    if (!isUserExist(id)) {
        throw std::runtime_error("用户不存在");
        return;
    }
    searchDataByAdmin(id)->addFromUser();
}

template <typename T> void UserDataManager<T>::removeUser()
{
    std::string id;
    std::cin >> id;
    if (!isUserExist(id)) {
        throw std::runtime_error("用户不存在");
        return;
    }
    vdata.erase(searchDataByAdmin(id));
}

template <typename T> void UserDataManager<T>::readFromFile()
{
    std::ifstream file(input_filename);
    if (!file.is_open()) {
        throw std::runtime_error("文件打开失败");
    }
    while (!file.eof()) {
        std::string str;
        file >> str;
        if (!isUserExist(str)) {
            throw std::runtime_error("用户不存在, 请先添加用户");
            break;
        } else {
            auto it = searchDataByAdmin(str);
            file >> str;
            if (str == "water") {
                it->addFromFile(WATER, file);
            } else if (str == "electricity") {
                it->addFromFile(ELECTRICITY, file);
            } else if (str == "gas") {
                it->addFromFile(GAS, file);
            } else {
                throw std::runtime_error("未知的水电气类型");
                break;
            }
        }
        file.close();
    }
}

template <typename T> void UserDataManager<T>::saveToFile() const
{
    std::ofstream file(output_filename);
    if (!file.is_open()) {
        throw std::runtime_error("文件打开失败");
    }
    T::showTitleForHistory();
    for (const auto &data : vdata) {
        file << *data << std::endl;
        data->showHistory(file);
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

template <typename T> void UserDataManager<T>::outputHistory() const
{
    T::showTitleForHistory();
    for (const auto &data : vdata) {
        std::cout << *data << std::endl;
        data->showHistory(std::cout);
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

template <typename T>
UserDataManager<T>::UserDataManager(std::string input_filename, std::string output_filename)
    : input_filename(std::move(input_filename)), output_filename(std::move(output_filename))
{
}

#endif