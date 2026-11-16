/*
                            Problem 1: 
Your hero is looking forward. On the right side of the screen there's another character. 
You want to forcefully rotate your hero to face the other character. 
How do you determine the angle of rotation between the two characters? 

*/

#include <iostream>
#include <cmath>
#include <numbers>

struct heroPosition {
    double xPosition;
    double yPosition;    
};

struct VectorDirection {
    double xDirection;
    double yDirection;
};


int main()
{
    heroPosition hero1{ -6, 4};
    heroPosition hero2{ 4, 3 };
    VectorDirection firstHeroDirection{ 0,1 };
    VectorDirection fromHero1ToHero2{ hero2.xPosition - hero1.xPosition, hero2.yPosition - hero1.yPosition };
    double magnitude = std::sqrt(fromHero1ToHero2.xDirection * fromHero1ToHero2.xDirection 
                                + fromHero1ToHero2.yDirection * fromHero1ToHero2.yDirection);
    if (magnitude > 0) {
        VectorDirection normalizedDirection = { fromHero1ToHero2.xDirection / magnitude, fromHero1ToHero2.yDirection / magnitude };
        double directionMagnitude = std::sqrt(normalizedDirection.xDirection * normalizedDirection.xDirection
                                   + normalizedDirection.yDirection * normalizedDirection.yDirection);
    }

    double heroFacingAngle = std::atan2(firstHeroDirection.yDirection, firstHeroDirection.xDirection);
    double targetAngle = std::atan2(fromHero1ToHero2.yDirection, fromHero1ToHero2.xDirection);
    double rotationAngle = heroFacingAngle - targetAngle;
    constexpr double halfRotationDegrees = 180.0;
    constexpr double pi = std::numbers::pi;
    double rotationDegrees = rotationAngle * (halfRotationDegrees / pi);
    std::cout << rotationDegrees;

}
