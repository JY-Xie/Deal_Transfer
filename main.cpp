#include "csv-parser/include/csv.hpp"
#include "make_index.hpp"

int main() {
    auto start = std::chrono::high_resolution_clock::now();
//    std::string bus_path = R"(N:\XieJiYe\matching\allbusUTF8withmetrostopSorted.csv)";
//    std::string metro_path = R"(N:\XieJiYe\matching\allmetroUTF8StationCodedSorted.csv)";

    std::string bus_path = R"(\\YJJNAS\Nas2Server\XieJiYe\matching\allbusUTF8withmetrostopSorted.csv)";
    std::string metro_path = R"(\\YJJNAS\Nas2Server\XieJiYe\matching\allmetroUTF8StationCodedSorted.csv)";

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

//    std::string trans_path = R"(N:\XieJiYe\matching\transfer data\metro_bus_user_pair_trips_idx_part50001.csv)";
//    std::vector<std::string> trans_col = {"BUSCARDNO", "BUSDATAIDX", "METROCARDNO", "METRODATAIDX"};
//    Trans trans(trans_path, trans_col);
//    int a = trans.transfer_details_statistics(bus_data, metro_data);
//
//    std::cout << "Process finish! " << std::endl;
//    // 等待用户输入，这里使用了std::cin.get()来实现
//    std::cin.get();
//    return a;

}