#include "Loup.hpp"

Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->name = "Loup";
    this->living = 1;
}

Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->name = "Loup";
    this->living = 1;
}

void Loup::deplace(int maxX, int maxY)
{
    int prevX = this->getX();
    int prevY = this->getY();
    do
    {
        this->x = getRand(0, maxX - 1);

    } while (prevX == this->x);

    do
    {
        this->y = getRand(0, maxY - 1);

    } while (prevY == this->y);
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