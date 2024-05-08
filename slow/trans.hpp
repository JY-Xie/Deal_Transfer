//
// Created by XieJiYe on 2024/4/10.
//

#ifndef TRANSFER_TRANS_HPP
#define TRANSFER_TRANS_HPP
#pragma once
#include "string"
#include "vector"
#include "make_index.hpp"


class Trans {
public:
    std::string file_path;
    std::vector<std::string> columns;

    Trans(std::string &file_path, std::vector<std::string> &columns);

//    std::vector<Make_metro_idx::Metrorawdata> &metro_data
    int transfer_details_statistics(std::vector<Make_bus_idx::Busrawdata> &bus_data, std::vector<Make_metro_idx::Metrorawdata> &metro_data); // 注意原子操作
};


#endif //TRANSFER_TRANS_HPP
