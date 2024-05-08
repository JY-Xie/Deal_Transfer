//
// Created by XieJiYe on 2024/4/10.
//

#include "trans.hpp"
#include "Csv.hpp"
#include "iostream"


Trans::Trans(std::string &file_path, std::vector<std::string> &columns) {
    this->file_path = file_path;
    this->columns = columns;
}

int Trans::transfer_details_statistics(std::vector<Make_bus_idx::Busrawdata> &bus_data, std::vector<Make_metro_idx::Metrorawdata> &metro_data) {
    io::CSVReader<4> in(this->file_path);
    in.read_header(
            io::ignore_extra_column,
            this->columns[0],
            this->columns[1],
            this->columns[2],
            this->columns[3]
    );

    std::string bus_cardno;
    std::string metro_cardno;
    unsigned int bus_idx;
    unsigned int metro_idx;



    std::string in_loop_bus_cardno;
    unsigned int in_loop_bus_idx;

    while(in.read_row(
            bus_cardno,
            bus_idx,
            metro_cardno,
            metro_idx
            )
            ){
        // do something

        if (in_loop_bus_cardno != bus_cardno){  //遇到新的用户
            in_loop_bus_cardno = bus_cardno;
            in_loop_bus_idx = bus_idx;

        } else {
            if (in_loop_bus_idx != bus_idx){  //同一用户的 第二(n)次出行 出现

            } else {  //还是原来的一次出行没变

            }

        }







        // 需要统计的指标
        // 取出索引对应的bus数据和metro数据，在每个bus用户对应的作用域内进行统计
        Make_bus_idx::Busrawdata bus_user_this_action = bus_data[bus_idx];
        Make_metro_idx::Metrorawdata metro_user_this_action = metro_data[metro_idx];
        std::cout << "||" << bus_cardno << "||" << "||" << bus_idx << "||" << "||" << metro_cardno << "||" << "||" << metro_idx << "||" << std::endl;
        std::cout << "+++" << bus_user_this_action.cardno << "+++" << std::endl;

        // 计算相似性指标


        }
    return 0;
}
