cmake_minimum_required(VERSION 3.15)
project(maCli)

# 1. 全局设置，会被所有子项目（包括spdlog）继承
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -march=x86-64 -fpermissive -w -O2 -D_GLIBCXX_USE_CXX11_ABI=0")
add_compile_options(-fPIC)
set(CMAKE_BUILD_TYPE Debug)

# 2. 将 spdlog 作为子项目添加，它会使用上面的编译设置
#    确保你已经将 spdlog 源码放在 'third_party/spdlog' 目录下
add_subdirectory(third/spdlog)

# 3. 添加其他子项目和设置
add_subdirectory(OpenXLSX)
find_package(SQLite3 REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/c++
        ${CMAKE_CURRENT_BINARY_DIR}
)

link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/linux
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/eqapilib
        ${CMAKE_CURRENT_SOURCE_DIR}/third
)

# 4. 定义可执行文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/macli TRADE_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src MAIN_LIST)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/EventQueue QUE_LIST)

add_executable(maCli
        src/main.cpp
        ${QUE_LIST}
        ${TRADE_LIST}
        src/strategies/position.cpp
        src/macli/MyFuncs.cpp
        src/macli/database.cpp
        src/macli/database.h
        src/macli/logger.cpp
        src/macli/logger.h
        src/strategies/strategy_template.cpp
        src/strategies/strategy_template.h
        src/strategies/strategy_non_linear.cpp
        src/strategies/strategy_non_linear.h
        src/macli/global.cpp
        src/macli/global.h
        src/market/MarketDataManager.cpp  # 添加这一行
        src/market/MarketDataManager.h   # 添加这一行
)

# 5. 链接库
file(GLOB SO_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/*.so")
list(REMOVE_ITEM SO_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/linux/libcrypto.so")

target_link_libraries(maCli PRIVATE
        # 链接由 add_subdirectory 创建的 spdlog 目标
        spdlog::spdlog
        OpenXLSX::OpenXLSX
        SQLite::SQLite3
        xsdk
        ${SO_LIBS}
        pthread
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/eqapilib/librqapi.so
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/eqapilib/libIce++11.so.3.6.4
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/eqapilib/libIceUtil++11.so.3.6.4
        ${CMAKE_CURRENT_SOURCE_DIR}/third/libcrypto.so.1.0.2k
    )

# 把运行时需要的所有目录都写死到 RPATH 里
set_target_properties(maCli PROPERTIES
        # 构建阶段：绝对路径，确保从 build 目录直接运行
        BUILD_RPATH "/mnt/d/git_project/eqapi_macli/Lnx64;/mnt/d/git_project/eqapi_macli/Lnx64/maClient;/mnt/d/git_project/eqapi_macli/lib/linux;/mnt/d/git_project/eqapi_macli/third"
        # 安装阶段：绝对路径，确保安装后也能找到库
        INSTALL_RPATH "/mnt/d/git_project/eqapi_macli/Lnx64;/mnt/d/git_project/eqapi_macli/Lnx64/maClient;/mnt/d/git_project/eqapi_macli/lib/linux;/mnt/d/git_project/eqapi_macli/third"
)

# 7. 安装目标
install(TARGETS maCli DESTINATION bin)
