cmake_minimum_required(VERSION 3.8)

set(This Tests)

set(SOURCES
    DungeonTest.cpp
)

add_executable(${This} ${SOURCES})

target_link_libraries(${This} PUBLIC
     gtest_main
     STATIC   
   
)

add_test(
    NAME ${This}
    COMMAND ${This}
)