//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

using namespace std;

void Func1(int (&&other)[5]) {
    std::cout << "0:" << std::to_string(other[0])
              << " 1:" << std::to_string(other[1])
              << " 2:" << std::to_string(other[2])
              << " 3:" << std::to_string(other[3])
              << " 4:" << std::to_string(other[4])
              << std::endl;
}

void Func2(int (&&other)[2][2]) {
    std::cout << "0:" << std::to_string(other[0][0])
              << " 1:" << std::to_string(other[0][1])
              << " 2:" << std::to_string(other[1][0])
              << " 3:" << std::to_string(other[1][1])
              << std::endl;
}

int main()
{
    Func2({{1,2},{3,4}});

    Matrix<3,3> c({{1.0f, 2.0f, 3.0f},
                   {4.0f, 5.0f, 6.0f},
                   {7.0f, 8.0f, 9.0f}});
    c.Println();

    std::cin.get();
}





