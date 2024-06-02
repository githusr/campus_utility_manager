#include "system/user_data_manager.h"
#include "tui/interaction.h"
#include "utility/utility_type.h"
#include <iostream>

auto UserDataManager::searchDataByAdmin(const std::string &id) const
{
    return std::find_if(vdata.begin(), vdata.end(),
                        [&](const std::shared_ptr<User> &data) { return data->getId() == id; });
}

void UserDataManager::searchDataByUser(const std::string &id, const std::string &name) const
{
    auto it = std::find_if(vdata.begin(), vdata.end(),
                           [&](const auto &data) { return data->getId() == id && data->getName() == name; });
    if (it == vdata.end()) {
        outputError("用户不存在");
    } else {
        (*it)->showTitleForUserInfo();
        (*it)->showUserInfo(std::cout);
    }
}

bool UserDataManager::isUserExist(const std::string &id) const
{
    return searchDataByAdmin(id) != vdata.end();
}

void UserDataManager::addUser(std::shared_ptr<User> data)
{
    std::cin >> *data;
    if (isUserExist(data->getId())) {
        outputError("用户已存在");
        return;
    }
    vdata.emplace_back(std::move(data));
}

void UserDataManager::addData(UserType user_type)
{
    std::string id;
    std::cin >> id;
    if (!isUserExist(id)) {
        outputError("用户不存在");
        return;
    }
    std::string utility_type;
    std::cin >> utility_type;
    if (utility_type == "water") {
        (*searchDataByAdmin(id))->addUtilityDataFromUser(user_type, WATER);
    } else if (utility_type == "electricity") {
        (*searchDataByAdmin(id))->addUtilityDataFromUser(user_type, ELECTRICITY);
    } else if (utility_type == "gas") {
        (*searchDataByAdmin(id))->addUtilityDataFromUser(user_type, GAS);
    } else {
        outputError("未知的水电气类型");
        return;
    }
}

void UserDataManager::removeUser()
{
    std::string id;
    std::cin >> id;
    if (!isUserExist(id)) {
        outputError("用户不存在");
        return;
    }
    vdata.erase(searchDataByAdmin(id));
}

void UserDataManager::pay(const std::string &id, const std::string &utility_type)
{
    if (!isUserExist(id)) {
        outputError("用户不存在");
        return;
    }
    if (utility_type == "water") {
        (*searchDataByAdmin(id))->pay(WATER);
    } else if (utility_type == "electricity") {
        (*searchDataByAdmin(id))->pay(ELECTRICITY);
    } else if (utility_type == "gas") {
        (*searchDataByAdmin(id))->pay(GAS);
    } else {
        outputError("未知的水电气类型");
        return;
    }
}

void UserDataManager::readFromFile(UserType user_type)
{
    std::ifstream file(input_filename);
    if (!file.is_open()) {
        outputError("文件打开失败");
    }
    while (!file.eof()) {
        std::string str;
        file >> str;
        if (!isUserExist(str)) {
            outputError("用户不存在, 请先添加用户");
            break;
        } else {
            auto it = searchDataByAdmin(str);
            file >> str;
            if (str == "water") {
                (*it)->addUtilityDataFromFile(user_type, WATER, file);
            } else if (str == "electricity") {
                (*it)->addUtilityDataFromFile(user_type, ELECTRICITY, file);
            } else if (str == "gas") {
                (*it)->addUtilityDataFromFile(user_type, GAS, file);
            } else {
                outputError("未知的水电气类型");
                break;
            }
        }
        file.close();
    }
}

void UserDataManager::saveToFile() const
{
    std::ofstream file(output_filename);
    if (!file.is_open()) {
        outputError("文件打开失败");
    }
    for (const auto &data : vdata) {
        data->showUserInfo(file);
    }
    file.close();
}

void UserDataManager::saveHistoryToFile() const
{
    std::ofstream file(output_filename);
    if (!file.is_open()) {
        outputError("文件打开失败");
    }
    for (const auto &data : vdata) {
        file << *data << std::endl;
        data->showHistory(file);
    }
    file.close();
}

void UserDataManager::outputData() const
{
    bool is_first = true;
    for (const auto &data : vdata) {
        if (is_first) {
            data->showTitleForUserInfo();
            is_first = false;
        }
        data->showUserInfo(std::cout);
    }
}

void UserDataManager::outputHistory() const
{
    bool is_first = true;
    for (const auto &data : vdata) {
        if (is_first) {
            data->showTitleForHistory();
            is_first = false;
        }
        std::cout << *data << std::endl;
        data->showHistory(std::cout);
    }
}

void UserDataManager::sortDataById()
{
    std::sort(vdata.begin(), vdata.end(),
              [](const auto &data_1, const auto &data_2) { return data_1->getId() < data_2->getId(); });
}

void UserDataManager::sortDataByName()
{
    std::sort(vdata.begin(), vdata.end(),
              [](const auto &data_1, const auto &data_2) { return data_1->getName() < data_2->getName(); });
}

void UserDataManager::sortDataByWaterFee()
{
    std::sort(vdata.begin(), vdata.end(), [&](const auto &data_1, const auto &data_2) {
        return data_1->getUtilityData(WATER) < data_2->getUtilityData(WATER);
    });
}

void UserDataManager::sortDataByElectricityFee()
{
    std::sort(vdata.begin(), vdata.end(), [&](const auto &data_1, const auto &data_2) {
        return data_1->getUtilityData(ELECTRICITY) < data_2->getUtilityData(ELECTRICITY);
    });
}

void UserDataManager::sortDataByGasFee()
{
    std::sort(vdata.begin(), vdata.end(), [&](const auto &data_1, const auto &data_2) {
        return data_1->getUtilityData(GAS) < data_2->getUtilityData(GAS);
    });
}

void UserDataManager::reverseData() { std::reverse(vdata.begin(), vdata.end()); }

UserDataManager::UserDataManager(std::string input_filename, std::string output_filename)
    : input_filename(std::move(input_filename)), output_filename(std::move(output_filename))
{
}