//launch code g++:
//clear && g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

using namespace std;

int main()
{
    VectorN<3> vecMoved(VectorN<3>::NullVector());
    vecMoved.Println();
    vecMoved = VectorN<3>::UnitVector() * 1.1f;
    vecMoved.Println();
    //vecMoved = VectorN<3>::UnitVector() * 2.0f;


    std::cin.get();
}



