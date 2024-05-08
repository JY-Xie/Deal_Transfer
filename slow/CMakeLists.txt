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

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(csv-parser)
add_executable(Transfer main.cpp Csv.hpp make_index.cpp make_index.hpp trans.cpp trans.hpp)


find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

# 尝试静态链接线程库
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static")

target_link_libraries(Transfer PRIVATE Threads::Threads csv)