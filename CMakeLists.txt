cmake_minimum_required(VERSION 3.27)
project(allojbsV2)

set(CMAKE_CXX_STANDARD 17)

add_executable(allojbsV2 main.cpp
        User.cpp
        User.h
        Candidate.cpp
        Candidate.h
        Employer.cpp
        Employer.h
        Jobs.cpp
        Jobs.h
)
