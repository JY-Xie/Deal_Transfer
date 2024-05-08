//
// Created by XieJiYe on 2024/5/8.
//
#pragma once
#ifndef TRANSFER_READ_TRAN_HPP
#define TRANSFER_READ_TRAN_HPP
#include "string"
#include "vector"
#include "make_index.hpp"

class read_tran {
    std::string file_path;
    std::vector<std::string> columns;

    read_tran(std::string &file_path, std::vector<std::string> &columns);

    //  std::vector<Make_metro_idx::Metrorawdata> &metro_data
    int transfer_details_statistics(std::vector<Make_bus_idx::Busrawdata> &bus_data, std::vector<Make_metro_idx::Metrorawdata> &metro_data);
};


#endif //TRANSFER_READ_TRAN_HPP
