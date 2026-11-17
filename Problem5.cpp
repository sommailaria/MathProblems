/* Problem 5
You cast a fireball against me. I cast a frostball against you.
They both collide mid air and a frostfire ball shoots parallel to both of
their trajectories. How do we compute the direction of the frostfire ball?
*/

#include <iostream>
#include <cmath>

struct Circle {
    double xPosition;
    double yPosition;
    double radius;
    double xDirection;
    double yDirection;
};

int main()
{
    Circle fireball{ 0, 10, 2, 0, -1 };
    Circle frostball{ 0, 0, 2, 0, 1 };

    double initialDistance = std::sqrt((frostball.xPosition - fireball.xPosition) * (frostball.xPosition - fireball.xPosition) 
                             + (frostball.yPosition - fireball.yPosition) * (frostball.yPosition - fireball.yPosition));

    double contactDistance = frostball.radius + fireball.radius;

    double totalGap = initialDistance - contactDistance;

    double ballTravelDistance = totalGap / 2;

    // New position formula: New Position = Starting Position + Direction * Distance

    fireball.yPosition = fireball.yPosition + (fireball.yDirection * ballTravelDistance);
    frostball.yPosition = frostball.yPosition + (frostball.yDirection * ballTravelDistance);

    // Calculating highest point and lowest point 

    double collisionY = fireball.yPosition - fireball.radius;
    double frostballHighestY = frostball.yPosition + frostball.radius;

    Circle frostFireBall{ fireball.xPosition, collisionY, 2, 0, 1 };

    std::cout << frostFireBall.xPosition << '\n' << frostFireBall.yPosition << '\n'
        << frostFireBall.radius << '\n' << frostFireBall.xDirection << '\n'
        << frostFireBall.yDirection << '\n';
       
}
