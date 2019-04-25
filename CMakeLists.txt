
cmake_minimum_required(VERSION 3.9)

project(UPower CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (UPowerSource 
    src/UPowerDevice.cpp
    src/UPowerDeviceManager.cpp
    include/UPowerDeviceManager.h
    )

set(UPowerInclude
    include/UPowerDevice.h
    include/UPowerDeviceManager.h
)

# Find the Qt5Core library
find_package(Qt5Core CONFIG REQUIRED)

add_library(UPower STATIC ${UPowerSource})
set_property(TARGET UPower PROPERTY CXX_STANDARD 17)
set_target_properties(UPower PROPERTIES PUBLIC_HEADER "${UPowerInclude}")

add_subdirectory(QDbusFreedesktopProperty)
target_link_libraries(UPower QDbusFreedesktopProperty)

target_include_directories(UPower PUBLIC include/)

qt5_use_modules(UPower Core)

install(TARGETS UPower
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        PUBLIC_HEADER DESTINATION include/UPower
        )
