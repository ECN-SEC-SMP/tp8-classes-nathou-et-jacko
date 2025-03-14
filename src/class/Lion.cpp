#include "Lion.hpp"

/**
 * @brief Construct a new Lion object
 *
 * @param x length value of the board
 * @param y height value of the board
 */
Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->name = NAME_LION;
    this->living = 1;
}

/**
 * @brief Construct a new Lion object
 *
 * @param x length value of the board
 * @param y heught value of the board
 * @param a X position  of the lion
 * @param b Y position of the lion
 */
Lion::Lion(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->name = NAME_LION;
    this->living = 1;
}

/**
 * @brief Destroy the Lion object
 *
 */
Lion::~Lion()
{
}

/**
 * @brief Set the new position of the lion
 *
 * @param x new X position
 * @param y new Y position
 */
void Lion::deplace(int maxX, int maxY)
{
    int newX = this->getX() + ((bool)(getRand(0, 1)) ? 1 : -1);
    int newY = this->getY() + ((bool)(getRand(0, 1)) ? 1 : -1);

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

/**
 * @brief Define the attack of the lion
 *
 */
void Lion::setAttaque()
{
    if (getRand(0, 1))
    {
        this->typeAttaque = AttackType::PAPER;
    }
    else
    {
        this->typeAttaque = AttackType::CISOR;
    }
}