#ifndef QR_ITERATION_HPP
#define QR_ITERATION_HPP

#include "matrix.hpp"


template <class T>
Matrix<T> qr_iteration(Matrix<T> A){
    Matrix<T> temp = A;
    int i = 0;
    std::pair<Matrix<T>, Matrix<T> > QR;
    while(i < 100 && !temp.isTriangular()){
        QR = temp.gram_schmidt();
        temp = QR.first.transpose() * temp * QR.first;
        i++;
    }
    return temp;
}


#endif //QR_ITERATION_HPP