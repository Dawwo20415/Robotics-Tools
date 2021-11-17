#ifndef MATRIX_CLASS
#define MATRIC_CLASS

#include <iostream>
#include <array>
#include <list>
#include "vector3.cpp"

template <int N>
class Matrix {

    private:
        std::array<Vector3,N> *matrix;

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

#endif
