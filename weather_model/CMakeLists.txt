cmake_minimum_required(VERSION 3.0)
project(CAR_EYE)
set(CMAKE_CXX_STANDARD 11)
set(weather CurlModel.cpp weatherApi.cpp HTTP.cpp)
FIND_PACKAGE(OpenCV REQUIRED)
add_library(weather SHARED ${weather})
target_link_libraries(weather ${OpenCV_LIBS} curl)