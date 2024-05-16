//
// Created by XieJiYe on 2024/5/9.
//
#include "my_utils.hpp"

namespace My_utils{
    double haversineDistance(double lat1, double lon1, double lat2, double lon2){
        double R = 6371000;

        lat1 = lat1 * M_PI / 180.0;
        lon1 = lon1 * M_PI / 180.0;
        lat2 = lat2 * M_PI / 180.0;
        lon2 = lon2 * M_PI / 180.0;

        double deltaLat = lat2 - lat1;
        double deltaLon = lon2 - lon1;

        double a = std::sin(deltaLat / 2) * std::sin(deltaLat / 2) +
                   std::cos(lat1) * std::cos(lat2) *
                   std::sin(deltaLon / 2) * std::sin(deltaLon / 2);
        double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

        return R * c;
    }

    std::chrono::system_clock::time_point string_to_time(const std::string& time_str) {
        std::istringstream ss(time_str);
        std::tm tm = {};
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        if (ss.fail()) {
            // Handle error, e.g. by throwing an exception
            return std::chrono::system_clock::from_time_t(0);
        }
        return std::chrono::system_clock::from_time_t(std::mktime(&tm));
    }

    long calc_time_span(std::chrono::system_clock::time_point before_time, std::chrono::system_clock::time_point after_time){

        auto duration = std::chrono::duration_cast<std::chrono::seconds>(after_time - before_time);
        return duration.count();
    }
}