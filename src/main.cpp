#include <iostream>
#include "qr_iteration.hpp"
#include "matrix.hpp"

int main(){
  int n;
  std::cout<<"nxn matrix:";
  std::cin>>n;
  std::cout<<n<<'\n';
  int a;
  Matrix<float>A(nullptr, n,n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      std::cin>>a;
      A.at(i,j) = a; 
    }
  }
  std::cout<<"A = \n";
  std::cout<<A<<"\n\n";
  Matrix<float>B = qr_iteration(A);
  std::cout<<"eigenvalues: [";
  for(int i= 0; i < n; i++){
    std::cout<<B.at(i,i);
    if(i < n-1){
      std::cout<<", ";
    }
  }
  std::cout<<"]\n";
  return 0;
}
