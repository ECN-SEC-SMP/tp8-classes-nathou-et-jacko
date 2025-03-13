#include "Loup.hpp"

Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
}

Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
}

void Loup::deplace(int maxX, int maxY)
{
    this->x = getRand(0, maxX - 1);
    this->y = getRand(0, maxY - 1);
}

void Loup::setAttaque()
{

    int type = getRand(0, 2);
    if (type == 0)
    {
        this->typeAttaque = AttackType::PAPER;
    }
    else if (type == 1)
    {
        this->typeAttaque = AttackType::CISOR;
    }
    else
    {
        this->typeAttaque = AttackType::ROCK;
    }
}