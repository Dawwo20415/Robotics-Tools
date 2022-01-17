
#include <iostream>
#include "classes/robot_structure/robot.h"

int main()
{

    std::vector<Joint> components ({ {RevoluteJoint(Link({0,1,0}))},
                                     {RevoluteJoint(Link({0,1,0}))} });

    std::vector<Transform> actions ({ {Transform({0,0,0},{M_PI / 2, 0, 0})},
                                      {Transform({0,0,0},{M_PI / 2, 0, 0})} });

    Robot bot(components, actions, {0,1,0});

    bot.getEndEffector().println();

    return 1;
}