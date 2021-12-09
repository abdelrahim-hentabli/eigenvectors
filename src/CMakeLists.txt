CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

SET(CMAKE_CXX_STANDARD 11)

project (eigenvectors)

ADD_EXECUTABLE(eigenvectors
  main.cpp
  )

ADD_EXECUTABLE(test
  tests/test.cpp
  )
