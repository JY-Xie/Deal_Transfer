//
// Created by XieJiYe on 2024/5/8.
//

#include "read_tran.hpp"
#include "csv-parser/include/csv.hpp"


read_tran::read_tran(std::string &file_path, std::vector <std::string> &columns) {
    this->file_path = file_path;
    this->columns = columns;
}

int read_tran::transfer_details_statistics(
        std::vector<Make_bus_idx::Busrawdata> &bus_data,
        std::vector<Make_metro_idx::Metrorawdata> &metro_data
        ) {
    csv::CSVReader reader(this->file_path);

    std::string bus_cardno;
    std::string metro_cardno;
    unsigned int bus_idx;
    unsigned int metro_idx;

    for (auto &row: reader) {
        bus_cardno = row[this->columns[0]].get<std::string>();
        bus_idx = row[this->columns[1]].get<unsigned int>();
        metro_cardno = row[this->columns[2]].get<std::string>();
        metro_idx = row[this->columns[3]].get<unsigned int>();


        // 计算指标
        

    }
    return 0;
}
