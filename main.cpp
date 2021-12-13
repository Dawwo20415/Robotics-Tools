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
    Matrix<3,4> c({{1.0f,2.0f,3.0f,4.0f},{1.0f,2.0f,3.0f,4.0f},{1.0f,2.0f,3.0f,4.0f}});
    Matrix<5,3> l({{1.0f,2.0f,3.0f},{1.0f,2.0f,3.0f},{1.0f,2.0f,3.0f},{1.0f,2.0f,3.0f},{1.0f,2.0f,3.0f}});
    Matrix<4,3> f;

    c.Println();
    l.Println();
    f.Println();

    std::cout << "Operation --------------------" << std::endl;

    f = c.Traslate();
                   
    c.Println();
    l.Println();
    f.Println();

    return 1;

}