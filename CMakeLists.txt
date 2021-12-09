CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

SET(CMAKE_CXX_STANDARD 11)

project (eigenvectors)

add_subdirectory(./src ../bin)

add_subdirectory(googletest)

TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
