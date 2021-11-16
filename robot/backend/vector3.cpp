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
Vector3::~Vector3() {printf("Destructed\n");}

//Functions
std::vector<float> Vector3::Get() {return *v;}

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

float Vector3::GetX() {return (*v)[0];}

float Vector3::GetY() {return (*v)[1];}

float Vector3::GetZ() {return (*v)[2];}

//Operators

Vector3 Vector3::operator+(const Vector3& vec) {
    for (int i = 0; i < 3; i++) {
        (*v)[i] += vec.v[i];
    }
}
