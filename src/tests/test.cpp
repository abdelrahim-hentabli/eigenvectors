#include "gtest/gtest.h"
#include "basic_functions_tests.hpp"
#include "matrix_tests.hpp"

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
