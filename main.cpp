//launch code g++:
//g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/vector3.cpp"

using namespace std;

int main()
{
    /*
    Prismatic_Joint j1 ("Prismatic 1", 'p', {0,0,0}, 5.0f, 1.0f);
    Robot rob("Robot2", {j1});
    rob.prnt();
    rob.func1(3);
    rob.prnt();
    */

    /*
    std::unique_ptr<Vector3> vec1 (new Vector3());
    vec1->Println();
    std::unique_ptr<Vector3> vec2 (new Vector3(1.0f, 5.5f, 2.7f));
    vec2->Println();
    std::unique_ptr<Vector3> vec4 (new Vector3(*vec2));
    vec4->Println();
    Vector3 vec5;
    vec5.Println();
    std::unique_ptr<Vector3> vec6 (new Vector3(vec5));
    vec6->Println();
    Vector3 vec7;
    vec7.Println();
    Vector3 vec8 = Vector3();
    */

    std::unique_ptr<Vector3> vec1 (new Vector3(1.0f, 5.5f, 2.7f));
    std::unique_ptr<Vector3> vec2 (new Vector3(1.0f, 5.5f, 2.7f)); 
    Vector3 vec3 = vec1 + vec2;  

    return 0;
}



