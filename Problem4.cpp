/* 
Problem 4 

You are making a game like Teamfight Tactics (TFT) in which all characters spawn in a circle looking at each other.
How do you compute the coordinates to position all characters in the circle? What if the number of players changes 
(i.e. sometimes it's 4, sometimes it's 10)?

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <string>

struct Character {
    std::string name;
    double xCoordinate;
    double yCoordinate;
    double facingDirection;
};

struct Circle {
    double xCenter;
    double yCenter;
    double radius;
};

int main()
{
    Circle arena{0, 0, 10};
    std::vector<Character> heroes;
    int numberOfCharacters = 10;
    constexpr double fullCircleDegrees = 360.0; 
    constexpr double pi = std::numbers::pi;
    constexpr double halfTurnDegrees = 180.0;
    double spacing = fullCircleDegrees / numberOfCharacters;
    for (int i = 0; i < numberOfCharacters; i++) {
        double standingAngle = i * spacing;
        double angleInRadians = standingAngle * (pi/ halfTurnDegrees);
        double xCoordinate = std::cos(angleInRadians) * arena.radius;
        double yCoordinate = std::sin(angleInRadians) * arena.radius;
        double facingDirection = std::fmod((standingAngle + halfTurnDegrees), fullCircleDegrees);
        heroes.emplace_back("hero " + std::to_string( i + 1), xCoordinate, yCoordinate, facingDirection);
    }

    for (Character h : heroes)
    {
        std::cout << h.name << '\n'
            << h.xCoordinate << '\n'
            << h.yCoordinate << '\n'
            << h.facingDirection << '\n';
    }

}
