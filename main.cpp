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
    Func1({1,3,5,6,8});
    Func2({{1,2},{3,4}});

    Matrix<3,3> m;
    m.Println();
    Matrix<3,3> c(m);
    c.Println();
    c.AddX(2.0f);
    m.Println();
    c.Println();

    std::cin.get();
}





