cmake_minimum_required(VERSION 3.9)

project(http-client-test)

add_subdirectory(app-factory)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} http-client-test.cpp)
target_link_libraries(${PROJECT_NAME} http-client app-factory)
