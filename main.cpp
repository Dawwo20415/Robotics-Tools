//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

using namespace std;

int main()
{
    std::cout << "---- First Declaration ----" << std::endl;
    Matrix<5,5> c({{1.0f,-2.0f,0.0f,0.0f,0.0f},{-2.0f,-1.0f,3.0f,0.0f,0.0f},{0.0f,3.0f,0.0f,-1.0f,0.0f},{0.0f,0.0f,-1.0f,1.0f,4.0f},{0.0f,0.0f,2.0f,4.0f,3.0f}});

    c.Println();
    std::cout << "The previous matrix is Symmetric? " << std::to_string(c.isSymmetric()) << std::endl;

    return 1;

}