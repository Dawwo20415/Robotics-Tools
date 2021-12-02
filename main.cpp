//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

using namespace std;

int main()
{/*
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

    c = c + l;
*/
    /*VectorN<3> v = {{1,2,3}};
    std::cout << v << std::endl;*/

    VectorN<3> vec1({1.0f,2.0f,3.0f});
    VectorN<3> vec2({1.1f,1.2f,1.3f});
    VectorN<3> vec3;

    std::cout << "Declaration --------" << std::endl;

    vec1.Println();
    vec2.Println();
    vec3.Println();

    std::cout << "Operation #1 --------" << std::endl;

    vec3 = vec1 - vec2;

    vec1.Println();
    vec2.Println();
    vec3.Println();

    std::cout << "Operation #2 --------" << std::endl;

    vec3 = {0.5f,0.5f,0.5f};

    vec1.Println();
    vec2.Println();
    vec3.Println();

    std::cout << "Operation #3 --------" << std::endl;

    vec2 = {0.6f,0.6f,0.6f};

    vec1.Println();
    vec2.Println();
    vec3.Println();

    std::cout << "Operation #4 --------" << std::endl;

    vec1 = {0.7f,0.7f,0.7f};

    vec1.Println();
    vec2.Println();
    vec3.Println();

    return 1;


    /*Matrix<2,2> m({{1,2}, {3,4}});
    std::cout << m << std::endl;*/

}