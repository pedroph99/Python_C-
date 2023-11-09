cmake_minimum_required(VERSION 3.10)
project(ProjetoBase "CXX")
message("${PROJECT_NAME} TESTANDO MENSAGEM")
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(
    ProjetoBase
    src/call_python.cpp)
target_link_libraries(ProjetoBase ${PYTHON_LIBRARIES})