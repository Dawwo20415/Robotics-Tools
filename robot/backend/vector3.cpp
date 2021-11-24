#include "vector3.h"
#include <iostream>

#pragma region Constructors
template <int N>
VectorN<N>::VectorN() {
    index = counter;
    counter++;
    printf("Created no arguments Vector%d index: %d\n", N, index);
    float tmp[N];
    v = new std::vector<float>(N, 0.0f);
}

template <int N>
VectorN<N>::VectorN(float arr[]) {
    index = counter;
    counter++;
    printf("Created floats Vector%d index: %d\n", N, index);
    v = new std::vector<float>(arr, arr + N);
}

template <int N>
VectorN<N>::VectorN(const VectorN<N> &vec) {
    this->index = counter;
    counter++;
    printf("Created Copy Constructor Vector%d index: %d\n", N, this->index);
    this->v = vec.v;
}

#pragma endregion

#pragma region Destructors
//Destructor
template <int N>
VectorN<N>::~VectorN() { printf("Destructed Vector3 %d\n", index); }

#pragma endregion

#pragma region Functions
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

template <int N>
float VectorN<N>::GetN(int index) {
    return (*v)[index];
}

#pragma endregion

#pragma region Operators
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


template<int N>
VectorN<N>& VectorN<N>::operator=(const VectorN<N>& vec) {
    printf("Used operator = on i:%d for i:%d\n",this->index, vec.index);
    this->v = vec.v;
    return *this;
}

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

#pragma endregion

#pragma region Statics
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

template <int N>
const VectorN<N>& VectorN<N>::UnitVectorPtr() {
    float tmp[N];
    for (int i = 0; i < N; i++) {
        tmp[i] = 1.0f;
    }
    return std::move(new VectorN<N>(tmp));
}

template <int N>
const VectorN<N>& VectorN<N>::NullVectorPtr() {
    return std::move(new VectorN<N>());
}

#pragma endregion