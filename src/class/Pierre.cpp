#include "Pierre.hpp"

/**
 * @brief Construct a new Pierre object
 *
 * @param x length value of the board
 * @param y height value of the board
 */
Pierre::Pierre(int x, int y) : Animal(x, y)
{
    this->name = NAME_PIERRE;
    this->living = 0;
}

/**
 * @brief Construct a new Pierre object
 *
 * @param x Length value of the board
 * @param y height value of the board
 * @param a position X of the Pierre
 * @param b position Y of the Pierre
 */
Pierre::Pierre(int x, int y, int a, int b) : Animal(x, y, a, b)
{
    this->name = NAME_PIERRE;
    this->living = 0;
}

/**
 * @brief Destroy the Pierre object
 *
 */
Pierre::~Pierre()
{
}

/**
 * @brief Define the new position of the Pierre
 * (Doesn't move because it's a rock)
 *
 * @param x new X position of the Pierre
 * @param y new Y position of the Pierre
 */
void Pierre::deplace(int maxX, int maxY)
{
    this->x = this->x;
    this->y = this->y;
}

/**
 * @brief Define the attack of the Pierre
 *
 */
void Pierre::setAttaque()
{
    this->typeAttaque = AttackType::ROCK;
}