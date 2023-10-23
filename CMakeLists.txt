cmake_minimum_required(VERSION 3.26)
project(jdp C)

set(CMAKE_C_STANDARD 11)

add_executable(jdp
        main.c
        menu.c
        menu.h
        carte.c
        carte.h)



#cmake_minimum_required(VERSION 3.17)
#project(jdp C)

#set(CMAKE_CXX_STANDARD 14)

#set(CURSES_LIBRARY "\\\\wsl.localhost\\Ubuntu-22.04\\usr\\lib\\x86_64-linux-gnu/libncurses.so")
#set(CURSES_INCLUDE_PATH "\\wsl.localhost/Ubuntu-22.04/usr/lib/x86_64-linux-gnu/include")

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})

#add_executable(jdp
#        main.c
#        menu.c
#        menu.h)

#target_link_libraries(jdp ${CURSES_LIBRARIES})