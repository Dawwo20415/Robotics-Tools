#include "matrix.h"

//Constructors
template <int N>
Matrix<N>::Matrix() {
    matrix = new std::array<Vector3,N>{{Vector3::NullVector(), Vector3::NullVector(), Vector3::NullVector()}};
}

template <int N>
Matrix<N>::Matrix(std::array<Vector3,N> &mtx) {
    matrix = mtx;
}

template <int N>
Matrix<N>::Matrix(std::list<Vector3> lst) {
    std::array<Vector3,N> tmp;
    if (lst.size() == N) {
        int j = 0;
        for (auto i : lst) {
            tmp[j] = i;
            j++;
        }
    } else {
        tmp = {Vector3::NullVector(), Vector3::NullVector(), Vector3::NullVector()};
    }
    matrix = tmp;
}

template <int N>
Matrix<N>::~Matrix() {
    printf("Matrix destructed \n");
}