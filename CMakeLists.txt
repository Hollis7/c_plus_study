cmake_minimum_required(VERSION 3.10)  # 最低 CMake 版本要求
project(C_PLUS_STUDY)                    # 项目名称

# 设置 C++ 标准（例如 C++11/14/17/20）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(exercise1_20           # 目标名称（可执行文件名）
    src/ch1/exercise1_20.cpp          # 源文件路径
)

# 设置头文件搜索路径
target_include_directories(exercise1_20
    PRIVATE                           # 私有头文件（仅当前目标可用）
        ${CMAKE_CURRENT_SOURCE_DIR}/include/mylib
)

# 可选：设置输出目录（默认在 build/ 下）
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)