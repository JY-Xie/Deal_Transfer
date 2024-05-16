//
// Created by XieJiYe on 2024/5/9.
//

#ifndef TRANSFER_MY_UTILS_HPP
#define TRANSFER_MY_UTILS_HPP
#include "cmath"
#include <iomanip>
#include "chrono"

namespace My_utils {
    double haversineDistance(double lat1, double lon1, double lat2, double lon2);

    std::chrono::system_clock::time_point string_to_time(const std::string& time_str);

    long calc_time_span(std::chrono::system_clock::time_point before_time, std::chrono::system_clock::time_point after_time);
}



#endif //TRANSFER_MY_UTILS_HPP
