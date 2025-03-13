#include "Lion.hpp"

Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->name = NAME_LION;
    this->living = 1;
}

Lion::Lion(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->name = NAME_LION;
    this->living = 1;
}

Lion::~Lion() {
    
}

void Lion::deplace(int maxX, int maxY)
{
    int newX = this->getX() + (bool)(getRand(0, 1) ? 1 : -1);
    int newY = this->getY() + (bool)(getRand(0, 1) ? 1 : -1);

    // Check position of X
    if (newX == maxX)
    {
        newX = newX - maxX;
    }
    else if (newX == -1)
    {
        newX = newX + maxX;
    }

    // Check position of Y
    if (newY == maxY)
    {
        newY = newY - maxY;
    }
    else if (newY == -1)
    {
        newY = newY + maxY;
    }

    this->x = newX;
    this->y = newY;
}

void Lion::setAttaque()
{
    if (getRand(0, 1)) {
        this->typeAttaque = AttackType::PAPER;
    } else {
        this->typeAttaque = AttackType::CISOR;
    }    
}