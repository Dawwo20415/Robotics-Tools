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
    //Matrix<5,5> c({{1.0f,-2.0f,0.0f,0.0f,0.0f},{-2.0f,-1.0f,3.0f,0.0f,0.0f},{0.0f,3.0f,0.0f,-1.0f,0.0f},{0.0f,0.0f,-1.0f,1.0f,4.0f},{0.0f,0.0f,2.0f,4.0f,3.0f}});
    Matrix<3,3> dd({{1.0f,2.0f, 0.0f},{3.0f,4.0f, 0.0f}, {3.0f,4.0f, 0.0f}});

    std::cout << " --------------------------------------" << std::endl;
    Matrix<2,2> ddd;
    ddd = dd.Submatrix(0,0);

    std::cout << "Determinante : " << ddd.Determinante() << std::endl;
    
    //std::cout << " ---------- Determinante matrice 5x5: " << dd.Determinante() << std::endl;
    std::cout << " --------------------------------------" << std::endl;

    return 1;

}