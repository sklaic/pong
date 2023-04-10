cmake_minimum_required(VERSION 3.10)
project(pong)
#for Linux distros without SDL2_ttf cmake script
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${pong_SOURCE_DIR}/cmake")

add_executable(pong
    src/main.cpp
    src/display.cpp
    src/game.cpp
    src/gameObject.cpp
    src/ball.cpp
    src/input.cpp
)

add_custom_target(copy_res
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_MODULE_PATH}/CopyResources.cmake
)
add_dependencies(pong copy_res)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_include_directories(pong
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(pong
    PUBLIC ${SDL2_LIBRARIES}
    PUBLIC ${SDL2_TTF_LIBRARIES}
)