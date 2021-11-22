#include "vector3.h"
#include <iostream>

//Constructors
template <int N>
VectorN<N>::VectorN() {
    printf("Created no arguments\n");
    index = counter;
    counter++;
    float tmp[N];
    v = new std::vector<float>(N, 0.0f);
}

template <int N>
VectorN<N>::VectorN(float arr[]) {
    printf("Created floats\n");
    index = counter;
    counter++;
    v = new std::vector<float>(arr, arr + N);
}

template <int N>
VectorN<N>::VectorN(const VectorN<N> &vec) {
    printf("Created Copy Constructor\n");
    index = counter;
    counter++;
    v = vec.v;
}

//Destructor
template <int N>
VectorN<N>::~VectorN() { printf("Destructed Vector3 %d\n", index); counter--; }

//Functions
template <int N>
std::vector<float> VectorN<N>::Get() { return *v; }

template <int N>
void VectorN<N>::Print() {
    std::string tmp;
    tmp += "[";
    for (int i = 0; i < N; i++) {
        tmp += std::to_string(i) + ":" + std::to_string((*v)[i]) + "|";
    }
    tmp += "]";
    std::cout << tmp;
}

template <int N>
void VectorN<N>::Println() {
    std::string tmp;
    tmp += "[";
    for (int i = 0; i < N; i++) {
        tmp += "|" + std::to_string(i) + ":" + std::to_string((*v)[i]);
    }
    tmp += "|]\n";
    std::cout << tmp;
}

template <int N> float VectorN<N>::GetX() { return (*v)[0]; }

template <int N> float VectorN<N>::GetY() { return (*v)[1]; }

template <int N> float VectorN<N>::GetZ() { return (*v)[2]; }

//Operators

template <int N>
VectorN<N> VectorN<N>::operator+(const VectorN<N>& vec) {
    VectorN<N> tmp;
    for (int i = 0; i < N; i++) {
        (*tmp.v)[i] = (*v)[i] + (*vec.v)[i];
    }
    return tmp;
}

template <int N>
VectorN<N> VectorN<N>::operator-(const VectorN<N>& vec) {
    VectorN<N> tmp;
    for (int i = 0; i < N; i++) {
        (*tmp.v)[i] = (*v)[i] - (*vec.v)[i];
    }
    return tmp;
}

/*
Vector3 Vector3::operator=(const Vector3& vec) {
    return vec;
}*/

template <int N>
VectorN<N> VectorN<N>::operator*(float val) {
    VectorN<N> tmp;
    for (int i = 0; i < N; i++) {
        (*tmp.v)[i] = (*v)[i] * val;
    }
    return tmp;
}

template <int N>
VectorN<N> VectorN<N>::operator*(const VectorN<N>& vec) {
    if (N == 3) {
        VectorN<N> tmp;
        (*tmp.v)[0] = (*v)[1] * (*vec.v)[2] - (*v)[2] * (*vec.v)[1];
        (*tmp.v)[1] = (*v)[2] * (*vec.v)[0] - (*v)[0] * (*vec.v)[2];
        (*tmp.v)[2] = (*v)[0] * (*vec.v)[1] - (*v)[1] * (*vec.v)[0];
        return tmp;
    } else {
        return VectorN<N>::NullVector();
    }
    
}

template <int N>
float VectorN<N>::DotProduct(VectorN<N> vec) { 
    float tmp = 0.0f;
    for (int i = 0; i < N; i++) {
        tmp += (*v)[i]*(*vec.v)[i];
    }
    return tmp;
}

//Statics

template <int N>
VectorN<N> VectorN<N>::UnitVector() {
    float tmp[N];
    for (int i = 0; i < N; i++) {
        tmp[i] = 1.0f;
    }
    return VectorN<N>(tmp);
}

template <int N>
VectorN<N> VectorN<N>::NullVector() {
    return VectorN<N>();
}