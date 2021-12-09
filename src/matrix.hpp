#ifndef MATRIX_HPP
#define MATRIX_HPP

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
      delete[] row_major;
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
    
    bool operator==(const Matrix<T>& rhs){
      if(n != rhs.n || m != rhs.m){
        return false;
      }
      else{
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
            if(!equality(row_major[i*n+j], rhs.row_major[i*n+j])){
              return false;
            }
          }
        }
      }
      return true;
    }

  private:
    T* row_major;
    int n;
    int m;
};


#endif //MATRIX_HPP