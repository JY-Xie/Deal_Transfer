//
// Created by XieJiYe on 2024/4/9.
//

#ifndef TRANSFER_MAKE_INDEX_HPP
#define TRANSFER_MAKE_INDEX_HPP
#pragma once
#include "string"
#include "vector"
#include "chrono"


class Make_bus_idx {
public:
    Make_bus_idx(std::string &file_path, std::string &data_type, std::vector<const char*> &column_name);

    std::string file_path;
    std::string dataset_type;
    std::vector<const char*> column_name;
    struct Busrawdata{
        std::string cardno;
        std::chrono::system_clock::time_point consumedate;
        double longitude;
        double latitude;
        int nearbymetrostop;
    };

    std::vector<Busrawdata> csv2vector();
};


class Make_metro_idx {
public:
    Make_metro_idx(std::string &file_path, std::string &data_type, std::vector<const char*> &column_name);
    std::string file_path;
    std::string dataset_type;
    std::vector<const char*> column_name;
    struct Metrorawdata{
        std::string cardno;
        int deststop;
        std::chrono::system_clock::time_point destdate;
    };

    std::vector<Metrorawdata> csv2vector();
};
#endif