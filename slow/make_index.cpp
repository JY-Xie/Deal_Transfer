//
// Created by XieJiYe on 2024/4/9.
//
#include <sstream>
#include <iomanip>
#include "make_index.hpp"
#include "iostream"
#include "Csv.hpp"


namespace My_utils{
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
}


Make_bus_idx::Make_bus_idx(std::string &file_path, std::string &data_type, std::vector<const char*> &column_name) {
    this->file_path = file_path;
    this->dataset_type = data_type;
    this->column_name = column_name;
    std::cout << "Start processing " << data_type << std::endl;
}


std::vector<Make_bus_idx::Busrawdata> Make_bus_idx::csv2vector() {
    io::CSVReader<bus_csv_number> in(this->file_path);
    in.read_header(
            io::ignore_extra_column,
            this->column_name[0],
            this->column_name[1],
            this->column_name[2],
            this->column_name[3],
            this->column_name[4],
            this->column_name[5]
    );
    std::vector<Make_bus_idx::Busrawdata> bus_data;
    Make_bus_idx::Busrawdata busrawdata;
    int csv_index;
    std::string csv_time;
    while(in.read_row(
            csv_index,
            busrawdata.cardno,
            csv_time,
            busrawdata.longitude,
            busrawdata.latitude,
            busrawdata.nearbymetrostop)
            ){
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
    io::CSVReader<metro_csv_number> in(this->file_path);
    in.read_header(
            io::ignore_extra_column,
            this->column_name[0],
            this->column_name[1],
            this->column_name[2],
            this->column_name[3]
    );

    std::vector<Make_metro_idx::Metrorawdata> metro_data;
    Make_metro_idx::Metrorawdata metrorawdata;
    int csv_index;
    std::string csv_time;
    while(in.read_row(
            csv_index,
            metrorawdata.cardno,
            metrorawdata.deststop,
            csv_time)
            ){
        metrorawdata.destdate = My_utils::string_to_time(csv_time);
        metro_data.push_back(metrorawdata);
    }
    std::cout << "End processing " << this->dataset_type << std::endl;
    return metro_data;
}