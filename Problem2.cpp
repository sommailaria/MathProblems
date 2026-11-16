/* 
* Problem 2: 
You are driving a car in a racing game. 
You make a wrong turn and the game displays "You are going the wrong way, turn back" on your HUD. 
How does the game know that the direction is wrong?
*/

#include <iostream>
#include <cmath>
#include <numbers>

struct carDirection {
    double xDirection;
    double yDirection;
};

struct trackDirection {
    double xDirection;
    double yDirection;
};

int main()
{
    carDirection car{ -1,0 };
    trackDirection track{ 1, 0 };
    double carAngle = std::atan2(car.yDirection, car.xDirection);
    double trackAngle = std::atan2(track.yDirection, track.xDirection);
    double orientationAngleDifference = carAngle - trackAngle;
    constexpr double halfRotationDegrees = 180;
    constexpr double pi = std::numbers::pi;
    double angleDegrees = orientationAngleDifference * (halfRotationDegrees / pi);
    if (angleDegrees > 180)
    {
        angleDegrees -= 360;
    }
    else if (angleDegrees < -180)
    {
        angleDegrees += 360;
    }
    std::cout << "angleDegrees is: " << angleDegrees << '\n';
    if (std::abs(angleDegrees) >90)
    {
        std::cout << "You are going the wrong way, turn back \n";
    }
    else
    {
    std::cout << "Keep going! \n";
    }
    
   
}
