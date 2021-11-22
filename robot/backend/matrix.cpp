#include "matrix.h"

//Constructors
template <int N>
Matrix<N>::Matrix() {
    index = counter;
    counter++;
    matrix = new std::array<Vector3,N>{{Vector3::NullVector(), Vector3::NullVector(), Vector3::NullVector()}};
}

template <int N>
Matrix<N>::Matrix(std::array<Vector3,N> &mtx) {
    index = counter;
    counter++;
    matrix = mtx;
}

template <int N>
Matrix<N>::Matrix(std::list<Vector3> lst) {
    index = counter;
    counter++;
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
    delete matrix;
    counter--;
    printf("Destructed Matrix %d\n", index);   
}