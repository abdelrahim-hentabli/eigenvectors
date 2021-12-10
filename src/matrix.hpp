#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <utility>
#include <iostream>
#include <cmath>
#include "basic_functions.hpp"


template <class T>
class Matrix{
  public:
    Matrix(){
      n = 1;
      m = 1;
      row_major = new T[1];
      row_major[0] = T(0);
    }
    
    Matrix(const Matrix<T>& rhs){
      n = rhs.n;
      m = rhs.m;
      row_major = new T[n*m];
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          row_major[i*m+j]= rhs.row_major[i*m+j];
        }
      }
    }

    Matrix<T>& operator =(const Matrix<T>& rhs){
      if(row_major != nullptr){
        delete[] row_major;
      }
      n = rhs.n;
      m = rhs.m;
      row_major = new T[n*m];
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          row_major[i*m+j]= rhs.row_major[i*m+j];
        }
      }
    }

    Matrix(T* row_majorical, int n_t, int m_t){
      if(row_majorical==nullptr){
        n = n_t;
        m = m_t;
        row_major = new T[n*m];
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            row_major[i*m+j]= T(0);
          }
        }
      }
      else{
        n = n_t;
        m = m_t;
        row_major = new T[n_t*m_t];
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            row_major[i*m+j]= row_majorical[i*m+j];
          }
        }
      }
    }
    ~Matrix(){
      if(row_major != nullptr){
        delete[] row_major;
      }
    }
    T& at(int i){
      assert(row_major != nullptr);
      assert(i < n * m);
      return row_major[i];
    }
    T& at(int i, int j){
      assert(row_major != nullptr);
      assert(i < n && j < m);
      return row_major[i*m + j];
    }
    
    bool isSquare(){
      return n==m;
    }

    bool isDiagonal(){
      if(n!=m){
        return false;
      }
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if(i != j && !equality(row_major[i*m+j], T(0.0))){
            return false;
          }
        }
      }
      return true;
    }

    bool operator ==(const Matrix<T>& rhs) const{
      if(n != rhs.n || m != rhs.m){
        return false;
      }
      else{
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(!equality(row_major[i*m+j], rhs.row_major[i*m+j])){
              return false;
            }
          }
        }
      }
      return true;
    }

    bool operator !=(const Matrix<T>& rhs) const{
      if(n != rhs.n || m != rhs.m){
        return true;
      }
      else{
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(!equality(row_major[i*m+j], rhs.row_major[i*m+j])){
              return true;
            }
          }
        }
      }
      return false;
    }
  
    template <class U>
    friend std::ostream& operator <<(std::ostream& out, const Matrix<U>& rhs){
      for(int i = 0; i < rhs.n; i++){
        out <<"| ";
        for(int j = 0; j < rhs.m; j++){
          out<<rhs.row_major[i*rhs.m+j];
          if(j < rhs.m-1){
            out<<", ";
          }
        }
        out <<" |\n";
      }
      return out;
    }

    std::pair<Matrix<T>, Matrix<T> > lu_factorize(){
      Matrix<T> L(nullptr, n, m);
      Matrix<T> U(nullptr, n, m);
      Matrix<T> A(row_major, n, m);
      for(int k = 0; k < n; k++){
        if(equality(A.at(k,k),T(0))){
          std::cout<<"Encountered Zero pivot, returning\n";
          return std::pair<Matrix<T>, Matrix<T> >(L,U);
        }
        for(int i = 0; i < n; i++){
          L.at(i,k) = (A.at(i,k)/A.at(k,k));
          U.at(k,i) = A.at(k,i);
        }
        for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
            A.at(i,j) -= (L.at(i,k)*U.at(k,j)); 
          }
        }
      }
      return std::pair<Matrix<T>, Matrix<T> >(L,U);
    }

    T col_norm(int column){
      T sum = T(0.0);
      for(int i = 0; i < n; i++){
        sum += at(i,column) * at(i, column);
      }
      return sqrt(sum);
    }

    T dot(int col1, int col2){ //dot product of two columns
      T sum = T(0);
      for(int i = 0; i < n; i++){
        sum += (at(i,col1)*at(i,col2));
      }
      return sum;
    }

    std::pair<Matrix<T>, Matrix<T> > gram_schmidt(){
      Matrix<T> Q(row_major, n, m);
      Matrix<T> R(nullptr, n, m);
      T norm;
      T dotVal;
      for(int c = 0; c < m; c++){
        for(int k = c-1; k >= 0; k--){
          R.at(k,c) = Q.dot(c,k);
        }
        for(int k = c-1; k >=0; k--){
          for(int i = 0; i < n; i++){
            Q.at(i,c) = Q.at(i,c) - (R.at(k,c) * Q.at(i,k));
          }
        }
        R.at(c,c) = Q.col_norm(c);
        for(int i = 0; i < n; i++){
          Q.at(i,c) /= R.at(c,c);
        }
      }
      return std::pair<Matrix<T>, Matrix<T> >(Q, R);
    }
    
  private:
    T* row_major;
    int n;
    int m;
};


#endif //MATRIX_HPP