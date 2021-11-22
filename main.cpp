//launch code g++:
//g++ main.cpp -o main.out && ./main.out

#include <iostream>
#include <memory>

#include "./robot/robot.cpp"
#include "./robot/backend/matrix.cpp"

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

    /*
    Vector3 vec1(1.0f, 5.5f, 2.7f);
    Vector3 vec2(7.5f, 8.1f, 1.0f);
    Vector3 vec3 = vec2 * vec1;
    vec3.Println();
    float tmp = vec1.DotProduct(vec2);
    printf("%f\n", tmp);
    */

    //Matrix<3,3> mat;
    float tmp[3] = {1.1f,1.2f,1.3f};
    float tmp2[3] = {1.4f,1.5f,1.6f};
    VectorN<3> vec1(tmp);
    VectorN<3> vec2(tmp2);
    vec1.Println();
    vec2.Println();
    VectorN<5> vec3;
    vec3.Println();
    VectorN<3> vec4 = vec1 * vec2;
    vec4.Println();
    printf("%f\n", vec1.DotProduct(vec2));

    vec4 = vec1 * VectorN<3>::NullVector();
    vec4.Println();
    vec4 = vec1 - VectorN<3>::UnitVector();
    vec4.Println();

    vec4 = vec1 * 1.5f;
    vec4.Println();

    VectorN<5> vec5(vec3);
    vec5.Println();

    return 0;
}



