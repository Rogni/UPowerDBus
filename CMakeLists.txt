
cmake_minimum_required(VERSION 3.9)

project(UPower CXX)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set (UPowerSource 
    src/UPowerDevice.cpp
    src/UPowerDeviceManager.cpp
    )
    
set(UPowerInclude
    include/UPowerDevice.h
    include/UPowerDeviceManager.h
)

include_directories(include/)

# Find the Qt5Core library
find_package(Qt5Core CONFIG REQUIRED)

add_library(UPower ${UPowerSource})
set_property(TARGET UPower PROPERTY CXX_STANDARD 17)
set_target_properties(UPower PROPERTIES PUBLIC_HEADER "${UPowerInclude}")

add_subdirectory(QDbusFreedesktopProperty)
target_link_libraries(UPower QDbusFreedesktopProperty)

target_include_directories(UPower PUBLIC include/)

target_link_libraries(UPower Qt5::Core)

install(TARGETS UPower
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )
