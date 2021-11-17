#include "vector3.h"
#include <iostream>

//Constructors
Vector3::Vector3() {
    printf("Created no arguments\n");
    v = new std::vector<float>({0,0,0});
}

Vector3::Vector3(float x, float y, float z) {
    printf("Created floats\n");
    v = new std::vector<float>({x,y,z});
}

Vector3::Vector3(const Vector3 &vec) {
    printf("Created Copy Constructor\n");
    v = vec.v;
}

//Destructor
Vector3::~Vector3() { printf("Destructed\n"); }

//Functions
std::vector<float> Vector3::Get() { return *v; }

void Vector3::Print() {
    std::cout << "[x:" << (*v)[0] << 
                 "|y:" << (*v)[1] << 
                 "|z:" << (*v)[2] << "]";
}

void Vector3::Println() {
    std::cout << "[x:" << (*v)[0] << 
                 "|y:" << (*v)[1] << 
                 "|z:" << (*v)[2] << "]" << std::endl;
}

float Vector3::GetX() { return (*v)[0]; }

float Vector3::GetY() { return (*v)[1]; }

float Vector3::GetZ() { return (*v)[2]; }

//Operators

Vector3 Vector3::operator+(const Vector3& vec) {
    Vector3 tmp;
    for (int i = 0; i < 3; i++) {
        (*tmp.v)[i] = (*v)[i] + (*vec.v)[i];
    }
    return tmp;
}

Vector3 Vector3::operator-(const Vector3& vec) {
    Vector3 tmp;
    for (int i = 0; i < 3; i++) {
        (*tmp.v)[i] = (*v)[i] - (*vec.v)[i];
    }
    return tmp;
}

/*
Vector3 Vector3::operator=(const Vector3& vec) {
    return vec;
}*/

Vector3 Vector3::operator*(float val) {
    Vector3 tmp;
    for (int i = 0; i < 3; i++) {
        (*tmp.v)[i] = (*v)[i] * val;
    }
    return tmp;
}

Vector3 Vector3::operator*(const Vector3& vec) {
    Vector3 tmp;
        (*tmp.v)[0] = (*v)[1] * (*vec.v)[2] - (*v)[2] * (*vec.v)[1];
        (*tmp.v)[1] = (*v)[2] * (*vec.v)[0] - (*v)[0] * (*vec.v)[2];
        (*tmp.v)[2] = (*v)[0] * (*vec.v)[1] - (*v)[1] * (*vec.v)[0];
    return tmp;
}

float Vector3::DotProduct(Vector3 vec) { return (*v)[0]*(*vec.v)[0] + (*v)[1]*(*vec.v)[1] + (*v)[2]*(*vec.v)[2]; }

//Statics

Vector3 Vector3::UnitVector() {
    return Vector3(1.0f, 1.0f, 1.0f);
}

Vector3 Vector3::NullVector() {
    return Vector3(0.0f, 0.0f, 0.0f);
}