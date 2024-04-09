cmake_minimum_required(VERSION 3.23)
project(Transfer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Transfer main.cpp Csv.hpp sqlite3.h sqlite3.c)
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
target_link_libraries(Transfer PRIVATE Threads::Threads)
