cmake_minimum_required(VERSION 3.10) # 最低 CMake 版本要求
project(C_PLUS_STUDY) # 项目名称

# 设置 C++ 标准（例如 C++11/14/17/20）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置调试编译选项（Debug 模式）
set(CMAKE_BUILD_TYPE Debug) # 启用调试符号

# 定义头文件路径和输出目录
set(MYLIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/mylib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 集中管理目标名称
set(EXECUTABLE_TARGETS exercise2_5 )

# 批量添加可执行文件
foreach(target ${EXECUTABLE_TARGETS})
    add_executable(${target} src/ch2/${target}.cpp)
    target_include_directories(${target} PRIVATE ${MYLIB_INCLUDE_DIR})
    target_compile_options(${target} PRIVATE -g -O0)
endforeach()
