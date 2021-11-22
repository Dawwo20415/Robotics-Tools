#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <iostream>
#include <array>
#include <list>
#include "vector3.cpp"

template <int N>
class Matrix {

    private:
        std::array<Vector3,N> *matrix;
        static int counter;
        int index;

    public:
        //Constructors
        Matrix();
        Matrix(std::array<Vector3,N> &mtx);
        Matrix(std::list<Vector3> lst);
        //Destructors
        ~Matrix();
        //Functions
        //Statics


};

template <>
int Matrix<3>::counter = 0;

#endif
