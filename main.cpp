#include <iostream>
#include "string"
#include "Csv.hpp"
#include <unordered_map>
#include "vector"
#include "sqlite3.h"
#include <chrono>


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::string metro_path = R"(D:\mycodes\PythonProjects\SmallThesis\raw data\sampledmetroUTF8.csv)";
    io::CSVReader<5> in(metro_path);
    in.read_header(io::ignore_extra_column, "CARDNO","ORGSTOP","DESTSTOP","ORGDATE","DESTDATE");



    std::vector<std::string> a;
    std::vector<short int> b;
    std::vector<short int> c;
    std::vector<std::string> d;
    std::vector<std::string> e;

    std::string cardno;
    short int orgstop;
    short int deststop;
    std::string orgdate;
    std::string destdate;

    while(in.read_row(cardno, orgstop, deststop, orgdate, destdate)){
        a.push_back(cardno);
        b.push_back(orgstop);
        c.push_back(deststop);
        d.push_back(orgdate);
        e.push_back(destdate);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() / 1000 << " s" << std::endl;

    auto loop_start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i <= 10000000; ++i) {
        std::string aaa = a[i];
        short int bbb = b[i];
        short int ccc = c[i];
        std::string ddd = d[i];
        std::string eee = e[i];
    }
    auto loop_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> loop_elapsed = loop_end - loop_start;
    std::cout << "For loop Execution time: " << loop_elapsed.count() / 1000 << " s" << std::endl;
    return 0;

}
