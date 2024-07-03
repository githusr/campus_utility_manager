#pragma once

#include "user/user.h"
#include <memory>
#include <string>
#include <vector>

class UserDataManager
{
public:
    void searchDataByUser(const std::string &id, const std::string &name) const;

    void addUser(std::shared_ptr<User> data);
    void addData(UserType user_type);
    void removeUser();

    void pay(const std::string &id, const std::string &utility_type);

    void readFromFile(UserType user_type);
    void saveToFile() const;
    void saveHistoryToFile() const;

    void outputData() const;
    void outputHistory() const;

    void sortDataById();
    void sortDataByName();
    void sortDataByWaterFee();
    void sortDataByElectricityFee();
    void sortDataByGasFee();
    void reverseData();

public:
    UserDataManager(std::string input_filename, std::string output_filename);

private:
    std::vector<std::shared_ptr<User>> vdata;
    std::string input_filename;
    std::string output_filename;

private:
    auto searchDataByAdmin(const std::string &id) const;
    bool isUserExist(const std::string &id) const;
};
