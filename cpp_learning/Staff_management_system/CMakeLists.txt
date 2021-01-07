cmake_minimum_required(VERSION 3.16)
project(Staff_management_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Staff_management_system main.cpp workerManager.cpp workerManager.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)