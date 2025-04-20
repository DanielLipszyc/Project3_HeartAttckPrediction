cmake_minimum_required(VERSION 3.27)
project(Project3_HeartAttckPrediction)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project3_HeartAttckPrediction
        main.cpp
        PatientObject.cpp
        PatientObject.h
        MergeSort.cpp
        MergeSort.h
        RadixSort.cpp
        RadixSort.h
)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics system window REQUIRED)

include_directories(C:/SFML/SFML-2.5.1/include)
include_directories(./resources/images)
target_link_libraries(Project3_HeartAttckPrediction sfml-window sfml-system sfml-graphics)
