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
    Matrix<3,3> c({{1.0f, 2.0f, 3.0f},
                   {4.0f, 5.0f, 6.0f},
                   {7.0f, 8.0f, 9.0f}});
                   
    c.Println();

    Matrix<3,3> l(c);

    l.Println();

    l(0,0) = 9.9f;

    c.Println();
    l.Println();

    

    std::cout << "---- After operator ----" << std::endl;

    l = c * 2.2f;

    c.Println();
    l.Println();

    std::cout << "---- After Modification c ----" << std::endl;

    l(1,1) = 1.0f;

    c.Println();
    l.Println();

    std::cout << "---- After Modification l ----" << std::endl;

    c(1,1) = 0.0f;

    c.Println();
    l.Println();

    return 1;

}