#include "joints.h"

//Definitions for PARENT CLASS Joint
Joint::Joint () {
    name = "Unnamed Joint";
    symbol = '|';
    origin = {0,0,0};
    endeffector = {0,0,0};
}

void Joint::GetRelativePos() {
    printf("Got Relative Position");
}

Joint::~Joint() {
    printf("Destructed\n");
}

//Definitions for SUBCLASS Prismatic_Joint

Prismatic_Joint::Prismatic_Joint(std::string n, char c, std::vector<float> o, float r) {
    name = n;
    symbol = c;
    origin = o;
    range = r;
    progress = 0.0f;
    endeffector = {0,0,0};
}

Prismatic_Joint::Prismatic_Joint(std::string n, char c, std::vector<float> o, float r, float p) {
    name = n;
    symbol = c;
    origin = o;
    range = r;
    progress = p;
    endeffector = {0,0,0};
}

void Prismatic_Joint::GetRelativePos() {
    for (auto i : endeffector) {
        printf("%f", i);
    }
}

Prismatic_Joint::~Prismatic_Joint() {
    printf("Destructed\n");
}
