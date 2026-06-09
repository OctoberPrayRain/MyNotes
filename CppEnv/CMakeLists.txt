cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

# 添加可执行文件
add_executable(main src/main.cpp)
