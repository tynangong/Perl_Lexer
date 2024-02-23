cmake_minimum_required(VERSION 3.16.0)

project(LexerProject VERSION 0.1.0)

# C++標準の設定
#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True) ## C++11であることを指定して、C++11以外のコンパイラを使うとエラーにする

include_directories(${PROJECT_SOURCE_DIR}/include)

set(LEXER_PROJECT_SRC src/Lexer.cpp)

# add_subdirectory(src)

add_executable(LexerProject ${LEXER_PROJECT_SRC} main.cpp src/Scanner.cpp src/Token.cpp)

# # 开启测试
# enable_testing()

# # 添加测试目录
# add_subdirectory(test)
