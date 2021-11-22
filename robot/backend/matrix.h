#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include <array>
#include <list>
#include <iterator>
#include "vector3.cpp"

template <int N, int M>
class Matrix {

    private:
        std::array<VectorN<M>,N> *matrix;
        static int counter;
        int index;

    public:
        //Constructors
        Matrix();
        Matrix(std::array<VectorN<M>,N> &mtx);
        Matrix(std::list<VectorN<M>> lst);
        //Destructors
        ~Matrix();
        //Functions
        //Statics


};

template <>
int Matrix<3,3>::counter = 0;

#endif
