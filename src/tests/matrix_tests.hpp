#ifndef MATRIX_TESTS_HPP
#define MATRIX_TESTS_HPP

#include "../matrix.hpp"

TEST(TEST_MATRIX, at){
    float a[9];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i*3+j]= i*3+j;
        }
    }
    Matrix<float> A(a,3,3);
    for(int i = 0; i < 9; i++){
        EXPECT_EQ(i, A.at(i));
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            EXPECT_EQ(i*3+j, A.at(i,j));
        }
    }
}

/* [[ 1  -1   0]
 *  [-1   2   1]
 *  [ 0   1   1]]
 *  eigenvalues = 3, 1 ,0
 *  eigenvectors = (-1, 2, 1), (1, 0, 1), (-1, -1, 1)
 */

#endif //MATRIX_TESTS_HPP