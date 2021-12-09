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
    float b[12];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            b[i*4+j]= i*4+j;
        }
    }
    Matrix<float> B(b,3,4);
    for(int i = 0; i < 12; i++){
        EXPECT_EQ(i, B.at(i));
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            EXPECT_EQ(i*4+j, B.at(i,j));
        }
    }
    float c[110];
    int n = 10;
    int m = 11;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c[i*m+j]= i*m+j;
        }
    }
    Matrix<float> C(c,n,m);
    for(int i = 0; i < n*m; i++){
        EXPECT_EQ(i, C.at(i));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            EXPECT_EQ(i*m+j, C.at(i,j));
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