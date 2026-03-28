cmake_minimum_required(VERSION 3.10)
project(Shop_Wizard)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shop_Wizard main.cpp
        item.h
        electronics.h
        grocery.h
        inventory.h
        electronics.cpp
        grocery.cpp
        inventory.cpp
        exceptions.h
        command_ui.h
        command_ui.cpp)

configure_file(inventory.csv ${CMAKE_CURRENT_BINARY_DIR}/inventory.csv COPYONLY)
configure_file(inventoryDup.csv ${CMAKE_CURRENT_BINARY_DIR}/inventoryDup.csv COPYONLY)
configure_file(inventoryNeg.csv ${CMAKE_CURRENT_BINARY_DIR}/inventoryNeg.csv COPYONLY)
configure_file(inventoryAAA.csv ${CMAKE_CURRENT_BINARY_DIR}/inventoryAAA.csv COPYONLY)
configure_file(inventoryAAA.csv ${CMAKE_CURRENT_BINARY_DIR}/inventoryLarge.csv COPYONLY)
configure_file(inventoryAAA.csv ${CMAKE_CURRENT_BINARY_DIR}/inventorySmall.csv COPYONLY)
configure_file(inventoryAAA.csv ${CMAKE_CURRENT_BINARY_DIR}/inventoryVal.csv COPYONLY)