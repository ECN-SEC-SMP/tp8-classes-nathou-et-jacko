#include "Pierre.hpp"

Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY)
{
}

Pierre::Pierre(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
}

void Pierre::deplace(int maxX, int maxY)
{
    this->x = this->x;
    this->y = this->y;
}

void Pierre::setAttaque() {
    this->typeAttaque = AttackType::ROCK;
}