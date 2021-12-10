#include <iostream>
#include "qr_iteration.hpp"
#include "matrix.hpp"

int main(){
  Matrix<float>A(nullptr, 3,3);
  A.at(0,0) = 1; A.at(0,1) = -1; A.at(0,2) = 0;
  A.at(1,0) = -1; A.at(1,1) = 2; A.at(1,2) = 1;
  A.at(2,0) = 0; A.at(2,1) = -1; A.at(2,2) = 1;
  std::cout<<qr_iteration(A);
  return 0;
}
