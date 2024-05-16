//
// Created by XieJiYe on 2024/4/9.
//
#include <sstream>
#include <iomanip>
#include "make_index.hpp"
#include "iostream"
#include "csv.hpp"
#include "my_utils.hpp"

Make_bus_idx::Make_bus_idx(std::string &file_path, std::string &data_type, std::vector<const char*> &column_name) {
    this->file_path = file_path;
    this->dataset_type = data_type;
    this->column_name = column_name;
    std::cout << "Start processing " << data_type << std::endl;
}


std::vector<Make_bus_idx::Busrawdata> Make_bus_idx::csv2vector() {
    csv::CSVReader reader(this->file_path);
    std::vector<Make_bus_idx::Busrawdata> bus_data;
    Make_bus_idx::Busrawdata busrawdata;
    std::string csv_time;
    for (auto &row: reader) {
        busrawdata.cardno = row[this->column_name[1]].get<std::string>();
        csv_time = row[this->column_name[2]].get<std::string>();
        busrawdata.longitude = row[this->column_name[3]].get<double>();
        busrawdata.latitude = row[this->column_name[4]].get<double>();
        busrawdata.nearbymetrostop = row[this->column_name[5]].get<int>();

        busrawdata.consumedate = My_utils::string_to_time(csv_time);
        bus_data.push_back(busrawdata);
    }

    std::cout << "End processing " << this->dataset_type << std::endl;
    return bus_data;
}


Make_metro_idx::Make_metro_idx(std::string &file_path, std::string &data_type, std::vector<const char*> &column_name) {
    this->file_path = file_path;
    this->dataset_type = data_type;
    this->column_name = column_name;
    std::cout << "Start processing " << data_type << std::endl;
}


std::vector<Make_metro_idx::Metrorawdata> Make_metro_idx::csv2vector() {
    csv::CSVReader reader(this->file_path);
    std::vector<Make_metro_idx::Metrorawdata> metro_data;
    Make_metro_idx::Metrorawdata metrorawdata;
    std::string csv_time;
    for (auto &row: reader) {
        metrorawdata.cardno = row[this->column_name[1]].get<std::string>();
        metrorawdata.deststop = row[this->column_name[2]].get<int>();
        csv_time = row[this->column_name[3]].get<std::string>();
        metrorawdata.destdate = My_utils::string_to_time(csv_time);
        metro_data.push_back(metrorawdata);
    }

    std::cout << "End processing " << this->dataset_type << std::endl;
    return metro_data;
}