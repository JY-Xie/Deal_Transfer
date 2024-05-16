#cmake_minimum_required(VERSION 3.23)
#project(Transfer)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(Transfer main.cpp Csv.hpp make_index.cpp make_index.hpp)
#find_package(Threads REQUIRED)
#set(THREADS_PREFER_PTHREAD_FLAG ON)
#target_link_libraries(Transfer PRIVATE Threads::Threads)

cmake_minimum_required(VERSION 3.23)
project(Transfer)

set(CMAKE_CXX_STANDARD 17)
add_executable(Transfer main.cpp make_index.hpp make_index.cpp read_tran.cpp read_tran.hpp csv.hpp my_utils.hpp my_utils.cpp thread_deal.hpp)


find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# 尝试静态链接线程库
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")

target_link_libraries(Transfer gcov)