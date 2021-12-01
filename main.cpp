//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

using namespace std;

int main()
{
    /*
    std::cout << "---- First Declaration ----" << std::endl;
    Matrix<3,3> c({{1.0f, 2.0f, 3.0f},
                   {4.0f, 5.0f, 6.0f},
                   {7.0f, 8.0f, 9.0f}});
                   
    Matrix<3,3> l({{1.0f, 2.0f, 3.0f},
                   {4.0f, 5.0f, 6.0f},
                   {7.0f, 8.0f, 9.0f}});
    c.Println();
    l.Println();

    std::cout << "---- After operator ----" << std::endl;


    c.Println();
    l.Println();
    */

    VectorN<3> vec3 ({1.0f,2.0f,3.0f});

    for (int i = 0; i < 3; i++) {
        std::cout << std::to_string(vec3.GetN(i)) << std::endl;
    }

    std::vector<float> *vec = new std::vector<float>();



    std::cin.get();
}





