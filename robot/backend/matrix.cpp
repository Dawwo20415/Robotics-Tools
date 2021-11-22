#include "matrix.h"

//Constructors
template <int N, int M>
Matrix<N,M>::Matrix() {
    index = counter;
    counter++;
    matrix = new std::array<VectorN<M>,N>{{VectorN<M>::NullVector(), VectorN<M>::NullVector(), VectorN<M>::NullVector()}};
}

template <int N, int M>
Matrix<N,M>::Matrix(std::array<VectorN<M>,N> &mtx) {
    index = counter;
    counter++;
    matrix = mtx;
}

template <int N, int M>
Matrix<N,M>::Matrix(std::list<VectorN<M>> lst) {
    index = counter;
    counter++;
    std::array<VectorN<M>,N> tmp;
    if (lst.size() == N) {
        int j = 0;
        for (auto i : lst) {
            tmp[j] = i;
            j++;
        }
    } else {
        tmp = {VectorN<M>::NullVector(), VectorN<M>::NullVector(), VectorN<M>::NullVector()};
    }
    matrix = tmp;
}

template <int N, int M>
Matrix<N,M>::~Matrix() {
    delete matrix;
    counter--;
    printf("Destructed Matrix %d\n", index);   
}