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

TEST(TEST_MATRIX, equality){
    float a[110];
    int n = 10;
    int m = 11;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i*m+j]= i*m+j;
        }
    }
    Matrix<float> A_1(a,n,m);
    Matrix<float> A_2(a,n,m);
    EXPECT_EQ(A_1,A_2);
    A_2.at(1) /= 3.0;
    A_2.at(1) *= 3.0;
    EXPECT_EQ(A_1,A_2);
    A_2.at(109) = 109;
    EXPECT_EQ(A_1,A_2);
    A_2.at(109) = 108.9999999;
    EXPECT_EQ(A_1,A_2);
    A_2.at(109) = 108.99;
    EXPECT_NE(A_1,A_2);
    
    
}

TEST(TEST_MATRIX, isDiagonal){
    float a[4];
    int n = 2;
    int m = 2;
    a[0] = 1; a[1] = 0; a[2] = 0; a[3] = 1;
    Matrix<float> A(a,n,m);
    EXPECT_TRUE(A.isDiagonal());
    A.at(0,1) = .0000000001;
    A.at(1,0) = .00000000001;
    EXPECT_TRUE(A.isDiagonal());
    Matrix<float> B(a,4,1);
    EXPECT_FALSE(B.isDiagonal());
    float c[1000];
    n = 10;
    m = 10;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(i == j){
                c[i*m+j] = i;
            } 
            else{
                c[i*m+j] = 0;
            }
        }
    }
    Matrix<float> C(c,n,m);
    EXPECT_TRUE(C.isDiagonal());
    C.at(9,8)=.001;
    EXPECT_FALSE(C.isDiagonal());
}

/* [[ 1  -1   0]
 *  [-1   2   1]
 *  [ 0   1   1]]
 *  eigenvalues = 3, 1 ,0
 *  eigenvectors = (-1, 2, 1), (1, 0, 1), (-1, -1, 1)
 */

#endif //MATRIX_TESTS_HPP