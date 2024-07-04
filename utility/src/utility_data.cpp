#include "utility/utility_data.h"
#include "utility/rate.h"
#include <fstream>
#include <iostream>
#include <string>

std::istream &operator>>(std::istream &is, UtilityData &utility_data)
{
    std::string meter_read_date;
    double meter_read;

    is >> meter_read_date >> meter_read;

    utility_data.utility_data.emplace_back(meter_read_date, meter_read);

    return is;
}

std::ostream &operator<<(std::ostream &os, const UtilityData &utility_data)
{
    for (const auto &data : utility_data.utility_data) {
        os << data.first << " " << data.second << std::endl;
    }

    return os;
}

bool UtilityData::operator<(const UtilityData &utility_data) const
{
    return this->fee_to_pay < utility_data.fee_to_pay;
}

void UtilityData::addFromUser(Rate rate)
{
    std::cout << "请输入抄表日期和抄表度数（用空格分隔）:" << std::endl;
    std::cin >> *this;
    updateFeeData(rate);
}

void UtilityData::addFromFile(const Rate &rate, std::ifstream &file_name)
{
    file_name >> *this;
    updateFeeData(rate);
}

void UtilityData::pay()
{
    for (auto it = fee_data.rbegin(); it != fee_data.rend(); ++it) {
        if (!it->second) {
            it->second = true;
        } else {
            break;
        }
    }
    fee_to_pay = 0;
}

static Rate rate(0, 0);

UtilityData::UtilityData() : fee_to_pay(0) {}

void UtilityData::setFeeData(const Rate &rate)
{
    auto size = utility_data.size();
    if (size >= 2) {
        double last_meter_read = utility_data[size - 2].second;
        double current_meter_read = utility_data[size - 1].second;
        double fee = (current_meter_read - last_meter_read) * rate.getUnitPrice();
        if (fee < rate.getFreeQuota()) {
            fee_data.emplace_back(0, false);
        } else {
            fee -= rate.getFreeQuota();
            fee_data.emplace_back(fee, false);
        }
    }
}

void UtilityData::calculateFeeToPay()
{
    fee_to_pay = 0;
    for (auto it = fee_data.rbegin(); it != fee_data.rend(); ++it) {
        if (!it->second) {
            fee_to_pay += it->first;
        } else {
            break;
        }
    }
}

void UtilityData::updateFeeData(const Rate &rate)
{
    setFeeData(rate);
    calculateFeeToPay();
}

double UtilityData::getFeeToPay() const { return fee_to_pay; }
