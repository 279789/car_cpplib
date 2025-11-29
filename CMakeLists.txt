cmake_minimum_required(VERSION 3.14)
project(car_cpplib VERSION 1.0.0 LANGUAGES CXX)

add_library(car_cpplib STATIC
    src/Car_Bike-Program.cpp
)

# Public include directory
 target_include_directories(car_cpplib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set properties for easy FetchContent usage
set_target_properties(car_cpplib PROPERTIES
    EXPORT_NAME car_cpplib
)

# Optionally, export the target for FetchContent
include(CMakePackageConfigHelpers)
install(TARGETS car_cpplib EXPORT car_cpplibTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT car_cpplibTargets
    FILE car_cpplibTargets.cmake
    NAMESPACE car_cpplib::
    DESTINATION lib/cmake/car_cpplib
)
