#include "vector3.h"
#include <iostream>

#pragma region Constructors
//Default Constructor
template <size_t N>
VectorN<N>::VectorN() {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            index = counter;
            counter++;
            printf("Created no arguments Vector%ld index: %d\n", N, index);
            float tmp[N];
            v = new std::vector<float>(N, 0.0f);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }   
}

//Copy Constructor
template <size_t N>
VectorN<N>::VectorN(const VectorN<N> &vec) {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            this->index = counter;
            counter++;
            printf("Created Copy Constructor Vector%ld index: %d from vector: %d\n", N, this->index, vec.index);
            this->v = new std::vector<float>(*(vec.v));
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }    
}

//Copy Vector Constructor
template <size_t N>
VectorN<N>::VectorN(const std::vector<float> &other) {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            this->index = counter;
            counter++;
            printf("Created Copy Vector Constructor Vector%ld index: %d\n", N, this->index);
            this->v = new std::vector<float>(other);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }
}

//Move Vector Constructor
template <size_t N>
VectorN<N>::VectorN(std::vector<float> &&other) noexcept{
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            this->index = counter;
            counter++;
            printf("Created Move Vector Constructor Vector%ld index: %d\n", N, this->index);
            if (this->v != &other) {
                delete this->v;
                this->v = &other;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }
}

//Move constructor
template <size_t N>
VectorN<N>::VectorN(VectorN<N>&& other) noexcept {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            this->index = counter;
            counter++;
            printf("Created Move Constructor Vector%ld index: %d from Vector: %d\n", N, this->index, other.index);
            if (this != &other) {
                delete v;

                this->v = other.v;
                other.v = nullptr;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }
}

//Float Array Copy constructor
template <size_t N>
VectorN<N>::VectorN(const float (&other)[N]) {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            index = counter;
            counter++;
            printf("Created Float Array Copy Vector%ld index: %d\n", N, index);
            v = new std::vector<float>(other, other + N);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    }
}

//Float Array Move constructor
template <size_t N>
VectorN<N>::VectorN(float (&&other)[N]) noexcept {
    try {
        if (N <= 0) {
            throw std::invalid_argument("VectorN of unmanageable size ");
        } else {
            index = counter;
            counter++;
            printf("Created Float Array Move Vector%ld index: %d\n", N, index);
            v = new std::vector<float>(other, other + N);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit;
    } 
}

#pragma endregion

#pragma region Destructors
//Destructor
template <size_t N>
VectorN<N>::~VectorN() { printf("Destructed Vector3 %d\n", index); }

#pragma endregion

#pragma region Functions
template <size_t N>
std::vector<float>& VectorN<N>::Get() { 
    std::cout << "Used NOT CONST" << std::endl;
    return *v; 
}

template <size_t N>
const std::vector<float>& VectorN<N>::Get() const { 
    std::cout << "Used CONST" << std::endl;
    return *v; 
}

template <size_t N>
void VectorN<N>::Print() {
    std::string tmp;
    tmp += "[";
    for (int i = 0; i < N; i++) {
        tmp += std::to_string(i) + ":" + std::to_string((*v)[i]) + "|";
    }
    tmp += "]";
    std::cout << tmp;
}

template <size_t N>
void VectorN<N>::Println() {
    std::string tmp;
    tmp += "[";
    for (int i = 0; i < N; i++) {
        tmp += "|" + std::to_string(i) + ":" + std::to_string((*v)[i]);
    }
    tmp += "|]\n";
    std::cout << tmp;
}

#pragma endregion

#pragma region Operators

//Copy Assignment operator
template<size_t N>
VectorN<N>& VectorN<N>::operator=(const VectorN<N>& other) {
    printf("Vector N Used copy assignment operator = on i:%d for i:%d\n",this->index, other.index);
    this->v = other.v;
    return *this;
}

//Move Assignment operator
template<size_t N>
VectorN<N>& VectorN<N>::operator=(VectorN<N>&& other) noexcept {
    printf("VectorN Used move operator = on i:%d for i:%d\n",this->index, other.index);
    if (this != &other) {
        delete v;
        this->v = other.v;
        other.v = nullptr;
    }
    return *this;
}

//Copy Assignment operator with float array
template<size_t N>
VectorN<N>& VectorN<N>::operator=(const float (&other)[N]) {
    printf("Vector N Used copy float assignment operator = on i:%d",this->index);
    delete v;
    this->v = new std::vector<float>(other, other + N);
    return *this;
}

//Move assignment operator with float array
template<size_t N>
VectorN<N>& VectorN<N>::operator=(float (&&other)[N]) noexcept {
    //I don't actually know if this is the correct way to implement this move but I am not familiar enough with std::vector
    //And when I tried to do something else it didn't compile so eh;
    printf("VectorN Used float move operator = on i:%d\n",this->index);
    delete v;
    v = new std::vector<float>(other, other + N);
    return *this;
}

//Selection operators
template <size_t N>
float& VectorN<N>::operator[](int _i) {
    return (*v)[_i];
}

template <size_t N>
const float& VectorN<N>::operator[](int _i) const {
    return (*v)[_i];
}

template <size_t N>
//Addition operator
VectorN<N>& VectorN<N>::operator+=(const VectorN<N>& _other) {
    std::cout << "VectorN operator +=" << std::endl;
    for (int i = 0; i < N; i++) {
        (*(this->v))[i] += _other[i];
    }
    return *this;
}

//Subtraction operator
template <size_t N>
VectorN<N>& VectorN<N>::operator-=(const VectorN<N>& _other) {
    std::cout << "VectorN operator -=" << std::endl;
    for (int i = 0; i < N; i++) {
        (*(this->v))[i] -= _other[i];
    }
    return *this;
}

//Cross Product operator
template <size_t N>
VectorN<N>& VectorN<N>::operator*=(const VectorN<N>& _other) {
    if (N == 3) {
        float tmp[3];
        tmp[0] = ( (*this)[1] * _other[2] ) - ( (*this)[2] * _other[1] );
        tmp[1] = ( (*this)[2] * _other[0] ) - ( (*this)[0] * _other[2] );
        tmp[2] = ( (*this)[0] * _other[1] ) - ( (*this)[1] * _other[0] ); 
        (*this)[0] = tmp[0];
        (*this)[1] = tmp[1]; 
        (*this)[2] = tmp[2];    
        return *this;
    } else {
        return *this;
    } 
}

//Scalar Product operator
template <size_t N>
VectorN<N>& VectorN<N>::operator*=(const float& _value) {
    for (int i = 0; i < N; i++) {
        (*(this->v))[i] *= _value;
    }
    return *this;
}

//Dot Product operator
template <size_t N>
float VectorN<N>::DotProduct(const VectorN<N>& vec) { 
    float tmp = 0.0f;
    for (int i = 0; i < N; i++) {
        tmp += (*v)[i]*(*vec.v)[i];
    }
    return tmp;
}

#pragma endregion

#pragma region Statics
template <size_t N>
VectorN<N> VectorN<N>::UnitVector() {
    float tmp[N];
    for (int i = 0; i < N; i++) {
        tmp[i] = 1.0f;
    }
    return VectorN<N>(tmp);
}

template <size_t N>
VectorN<N> VectorN<N>::NullVector() {
    return VectorN<N>();
}

//Output stream operator
template<size_t T>
std::ostream& operator<<(std::ostream& os, const VectorN<T>& _v){
    os << "[";
    for (int i = 0; i < T; i++) {
        os << std::to_string(i) + ":" + std::to_string((*(_v.v))[i]) + "|";
    }
    os << "]";
    return os;
}

#pragma endregion