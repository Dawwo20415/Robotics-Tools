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

    VectorN<3> v1(c.GetColumn(0));
    VectorN<3> v2(c.GetRow(0));


    v1.Println();
    v2.Println();

    std::cout << "---- After operator ----" << std::endl;


    return 1;

}