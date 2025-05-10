#include "Ours.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construct a new Ours object
 *
 * @param x length value of the board
 * @param y height value of the board
 */
Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->name = NAME_OURS;
    this->living = 1;
}

/**
 * @brief Construct a new Ours object
 *
 * @param x length value of the board
 * @param y height value of the board
 * @param a X position of the Ours
 * @param b Y position of the Ours
 */
Ours::Ours(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->name = NAME_OURS;
    this->living = 1;
}

/**
 * @brief Destroy the Ours object
 *
 */
Ours::~Ours()
{
}

/**
 * @brief Set the new position of the Ours
 *
 * @param x new X position
 * @param y new Y position
 */
void Ours::deplace(int maxX, int maxY)
{
    bool xMove_2 = (bool)(getRand(0, 1));  // 1 -> move by 2
    bool directionX = (bool)getRand(0, 1); // 1 -> move forward
    bool directionY = (bool)getRand(0, 1); // 1 -> move forward

    int newX = this->x + (directionX ? (xMove_2 == 1 ? 2 : 1) : (xMove_2 == 1 ? -2 : -1));
    int newY = this->y + (directionY ? (xMove_2 == 1 ? 1 : 2) : (xMove_2 == 1 ? -1 : -2));

    // Check position of X
    if (newX >= maxX)
    {
        newX = newX - maxX;
    }
    else if (newX < 0)
    {
        newX = newX + maxX;
    }

    // Check position of Y
    if (newY >= maxY)
    {
        newY = newY - maxY;
    }
    else if (newY < 0)
    {
        newY = newY + maxY;
    }
    this->x = newX;
    this->y = newY;
}

/**
 * @brief Define the attack of the Ours
 *
 */
void Ours::setAttaque()
{
    this->typeAttaque = AttackType::PAPER;
}