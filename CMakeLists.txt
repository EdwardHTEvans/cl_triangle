cmake_minimum_required(VERSION 3.20)
project(cl_triangle)
add_executable(${PROJECT_NAME} 
    src/main.c
    src/triangle.c
)
target_link_libraries(${PROJECT_NAME} m)