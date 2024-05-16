//
// Created by XieJiYe on 2024/5/8.
//
#pragma once
#ifndef TRANSFER_READ_TRAN_HPP
#define TRANSFER_READ_TRAN_HPP
#include "string"
#include "vector"
#include "make_index.hpp"
#include <map>

class read_tran {
public:
    std::string file_path;
    std::vector<std::string> columns;

    std::map<int, std::vector<double>> metro_station_info;

    //  std::vector<Make_metro_idx::Metrorawdata> &metro_data
    int transfer_details_statistics(std::vector<Make_bus_idx::Busrawdata> &bus_data, std::vector<Make_metro_idx::Metrorawdata> &metro_data);

public:
    read_tran(std::string &file_path, std::vector<std::string> &columns);
};


#endif //TRANSFER_READ_TRAN_HPP
