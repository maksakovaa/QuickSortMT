cmake_minimum_required(VERSION 3.5.0)
project(qsmt VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)
add_executable(qsmt main.cpp quickSort.cpp thPool.cpp reqHandler.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
