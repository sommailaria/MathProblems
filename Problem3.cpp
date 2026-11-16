/* Problem 3
You cast an Air Bubble spell which spawns a bubble of air in front of you.
You then shoot a fireball. The fireball hits the bubble, ignites it
and deals lots of damage.
How do you detect the fireball hit the air bubble?
What math equation will tell you if a hit occurred?


*/

#include <iostream>
#include <cmath>
#include <numbers>

struct Circle {

    double xPosition;
    double yPosition;
    double radius;
};


int main()
{
    Circle airBubble{ 9, 4, 5 };
    Circle fireBall{ 3, 4, 2};
    double horizontalDifference = airBubble.xPosition - fireBall.xPosition;
    double verticalDifference = airBubble.yPosition - fireBall.yPosition; 
    double distanceOfCenters = std::sqrt(horizontalDifference * horizontalDifference + verticalDifference * verticalDifference);
    if (distanceOfCenters <= airBubble.radius + fireBall.radius)
    {
        std::cout << "Collision detected! \n";
    }
    else
    {
        std::cout << "No collision detected \n";
    }

}
