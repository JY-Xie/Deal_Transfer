#include "csv.hpp"
#include "make_index.hpp"
#include "my_utils.hpp"
#include "read_tran.hpp"
#include "thread"
#include "thread_deal.hpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::string bus_path = R"(N:\XieJiYe\matching\allbusUTF8withmetrostopSorted.csv)";
    std::string metro_path = R"(N:\XieJiYe\matching\allmetroUTF8StationCodedSorted.csv)";

//    std::string bus_path = R"(\\YJJNAS\Nas2Server\XieJiYe\matching\allbusUTF8withmetrostopSorted.csv)";
//    std::string metro_path = R"(\\YJJNAS\Nas2Server\XieJiYe\matching\allmetroUTF8StationCodedSorted.csv)";

    std::vector<const char*> bus_headers = {"idx", "CARDNO", "CONSUMEDATE", "LONGITUDE", "LATITUDE", "NEARBYMETROSTOP"};
    std::vector<const char*> metro_headers = {"idx", "CARDNO", "DESTSTOP", "DESTDATE"};

    std::string bus_type = "bus";
    std::string metro_type = "metro";

    Make_bus_idx makeBusIdx(bus_path, bus_type, bus_headers);
    std::vector<Make_bus_idx::Busrawdata> bus_data = makeBusIdx.csv2vector();

    Make_metro_idx makeMetroIdx(metro_path, metro_type, metro_headers);
    std::vector<Make_metro_idx::Metrorawdata> metro_data = makeMetroIdx.csv2vector();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() / 1000 << " s" << std::endl;


//    std::string trans_path = R"(\\YJJNAS\Nas2Server\\matching\transfer data\metro_bus_user_pair_trips_idx_part50001.csv)";
//    std::string trans_path = R"(N:\XieJiYe\matching\transfer data\metro_bus_user_pair_trips_idx_part50001.csv)";
//
//    std::vector<std::string> trans_col = {"BUSCARDNO", "BUSDATAIDX", "METROCARDNO", "METRODATAIDX"};
//    read_tran readTran(trans_path, trans_col);
//    int re_out = readTran.transfer_details_statistics(bus_data, metro_data);
//
//    std::vector<std::string> file_names = {"metro_bus_user_pair_trips_idx_last.csv", "metro_bus_user_pair_trips_idx_part100002.csv", "metro_bus_user_pair_trips_idx_part1000020.csv", "metro_bus_user_pair_trips_idx_part1050021.csv", "metro_bus_user_pair_trips_idx_part1100022.csv", "metro_bus_user_pair_trips_idx_part1150023.csv", "metro_bus_user_pair_trips_idx_part1200024.csv", "metro_bus_user_pair_trips_idx_part1250025.csv", "metro_bus_user_pair_trips_idx_part1300026.csv", "metro_bus_user_pair_trips_idx_part1350027.csv", "metro_bus_user_pair_trips_idx_part1400028.csv", "metro_bus_user_pair_trips_idx_part1450029.csv", "metro_bus_user_pair_trips_idx_part150003.csv", "metro_bus_user_pair_trips_idx_part1500030.csv", "metro_bus_user_pair_trips_idx_part1550031.csv", "metro_bus_user_pair_trips_idx_part1600032.csv", "metro_bus_user_pair_trips_idx_part1650033.csv", "metro_bus_user_pair_trips_idx_part1700034.csv", "metro_bus_user_pair_trips_idx_part1750035.csv", "metro_bus_user_pair_trips_idx_part1800036.csv", "metro_bus_user_pair_trips_idx_part1850037.csv", "metro_bus_user_pair_trips_idx_part1900038.csv", "metro_bus_user_pair_trips_idx_part1950039.csv", "metro_bus_user_pair_trips_idx_part200004.csv", "metro_bus_user_pair_trips_idx_part2000040.csv", "metro_bus_user_pair_trips_idx_part2050041.csv", "metro_bus_user_pair_trips_idx_part2100042.csv", "metro_bus_user_pair_trips_idx_part2150043.csv", "metro_bus_user_pair_trips_idx_part2200044.csv", "metro_bus_user_pair_trips_idx_part2250045.csv", "metro_bus_user_pair_trips_idx_part2300046.csv", "metro_bus_user_pair_trips_idx_part2350047.csv", "metro_bus_user_pair_trips_idx_part2400048.csv", "metro_bus_user_pair_trips_idx_part2450049.csv", "metro_bus_user_pair_trips_idx_part250005.csv", "metro_bus_user_pair_trips_idx_part2500050.csv", "metro_bus_user_pair_trips_idx_part2550051.csv", "metro_bus_user_pair_trips_idx_part2600052.csv", "metro_bus_user_pair_trips_idx_part2650053.csv", "metro_bus_user_pair_trips_idx_part2700054.csv", "metro_bus_user_pair_trips_idx_part2750055.csv", "metro_bus_user_pair_trips_idx_part2800056.csv", "metro_bus_user_pair_trips_idx_part2850057.csv", "metro_bus_user_pair_trips_idx_part2900058.csv", "metro_bus_user_pair_trips_idx_part2950060.csv", "metro_bus_user_pair_trips_idx_part300006.csv", "metro_bus_user_pair_trips_idx_part3000061.csv", "metro_bus_user_pair_trips_idx_part3050062.csv", "metro_bus_user_pair_trips_idx_part3100063.csv", "metro_bus_user_pair_trips_idx_part3150064.csv", "metro_bus_user_pair_trips_idx_part3200065.csv", "metro_bus_user_pair_trips_idx_part3250066.csv", "metro_bus_user_pair_trips_idx_part3300067.csv", "metro_bus_user_pair_trips_idx_part3350068.csv", "metro_bus_user_pair_trips_idx_part3400069.csv", "metro_bus_user_pair_trips_idx_part3450070.csv", "metro_bus_user_pair_trips_idx_part350007.csv", "metro_bus_user_pair_trips_idx_part3500071.csv", "metro_bus_user_pair_trips_idx_part3550072.csv", "metro_bus_user_pair_trips_idx_part3600073.csv", "metro_bus_user_pair_trips_idx_part3650074.csv", "metro_bus_user_pair_trips_idx_part3700075.csv", "metro_bus_user_pair_trips_idx_part3750076.csv", "metro_bus_user_pair_trips_idx_part3800077.csv", "metro_bus_user_pair_trips_idx_part3850078.csv", "metro_bus_user_pair_trips_idx_part3900079.csv", "metro_bus_user_pair_trips_idx_part3950080.csv", "metro_bus_user_pair_trips_idx_part400008.csv", "metro_bus_user_pair_trips_idx_part4000081.csv", "metro_bus_user_pair_trips_idx_part4050082.csv", "metro_bus_user_pair_trips_idx_part4100083.csv", "metro_bus_user_pair_trips_idx_part4150084.csv", "metro_bus_user_pair_trips_idx_part4200085.csv", "metro_bus_user_pair_trips_idx_part4250086.csv", "metro_bus_user_pair_trips_idx_part4300087.csv", "metro_bus_user_pair_trips_idx_part4350088.csv", "metro_bus_user_pair_trips_idx_part4400089.csv", "metro_bus_user_pair_trips_idx_part4450090.csv", "metro_bus_user_pair_trips_idx_part450009.csv", "metro_bus_user_pair_trips_idx_part4500091.csv", "metro_bus_user_pair_trips_idx_part4550092.csv", "metro_bus_user_pair_trips_idx_part4600093.csv", "metro_bus_user_pair_trips_idx_part4650094.csv", "metro_bus_user_pair_trips_idx_part4700095.csv", "metro_bus_user_pair_trips_idx_part4750096.csv", "metro_bus_user_pair_trips_idx_part4800097.csv", "metro_bus_user_pair_trips_idx_part4850098.csv", "metro_bus_user_pair_trips_idx_part4900099.csv", "metro_bus_user_pair_trips_idx_part4950100.csv", "metro_bus_user_pair_trips_idx_part50001.csv", "metro_bus_user_pair_trips_idx_part500010.csv", "metro_bus_user_pair_trips_idx_part5000101.csv", "metro_bus_user_pair_trips_idx_part550011.csv", "metro_bus_user_pair_trips_idx_part600012.csv", "metro_bus_user_pair_trips_idx_part650013.csv", "metro_bus_user_pair_trips_idx_part700014.csv", "metro_bus_user_pair_trips_idx_part750015.csv", "metro_bus_user_pair_trips_idx_part800016.csv", "metro_bus_user_pair_trips_idx_part850017.csv", "metro_bus_user_pair_trips_idx_part900018.csv", "metro_bus_user_pair_trips_idx_part950019.csv"};
//    std::thread t1();
//    std::thread t2();








    return re_out;

}