#ifndef BASIC_FUNCTIONS_TESTS
#define BASIC_FUNCTIONS_TESTS

#include "../basic_functions.hpp"

TEST(TEST_BASIC_FUNCTIONS, equality){
    EXPECT_TRUE(equality(1.0,1.0));
    EXPECT_TRUE(equality(-100.0,-100.0));
    EXPECT_TRUE(equality( (1.0/3.0)*3.0, 1.0));
    EXPECT_FALSE(equality(1.01,1.0));
    EXPECT_FALSE(equality(-99.99,-100.0));
    EXPECT_FALSE(equality( (1.0/3.0)*3.01, 1.0));   
}


#endif