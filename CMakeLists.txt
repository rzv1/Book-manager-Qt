cmake_minimum_required(VERSION 3.31)
project(Book_manager_Qt)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets Core Gui REQUIRED)

add_executable(app main.cpp
        domain.cpp
        domain.h
        AbstractModel.h
        Observer.h
        repo.cpp
        rentalcart.cpp
        rentalcart.h
        repo.h
        service.cpp
        service.h
        DTO.h
        tests.cpp
        tests.h
        gui.h
)
target_link_libraries(app PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui)