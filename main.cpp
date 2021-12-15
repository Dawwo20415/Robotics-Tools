//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.h"
#include "./robot/backend/matrix.cpp"

using namespace std;

int main()
{
    std::cout << "---- First Declaration ----" << std::endl;
    Matrix<5,5> c({{1.0f,-2.0f,0.0f,0.0f,0.0f},{-2.0f,-1.0f,3.0f,0.0f,0.0f},{0.0f,3.0f,0.0f,-1.0f,0.0f},{0.0f,0.0f,-1.0f,1.0f,4.0f},{0.0f,0.0f,2.0f,4.0f,3.0f}});
    Matrix<3,3> dd({{1.0f,2.0f, 0.0f},{3.0f,4.0f, 0.0f}, {3.0f,4.0f, 0.0f}});

    std::cout << " --------------------------------------" << std::endl;

    /*
    try {
        std::cout << "Determinante : " << dd.Determinante() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    */

    Matrix<2,2> sub;
    sub = dd.Submatrix(0,0);

    dd.Println();
    sub.Println();

    sub *= 2.0f;

    dd.Println();
    sub.Println();

    std::cout << "Determinante matrice sub = " << sub.Determinant() << std::endl;
    
    //std::cout << " ---------- Determinante matrice 5x5: " << dd.Determinante() << std::endl;
    std::cout << " --------------------------------------" << std::endl;

    return 1;

}