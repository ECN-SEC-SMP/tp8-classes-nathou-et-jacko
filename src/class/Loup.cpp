#include "Loup.hpp"

/**
 * @brief Construct a new Loup object
 *
 * @param x length value of the board
 * @param y height value of the board
 */
Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->name = NAME_LOUP;
    this->living = 1;
}

/**
 * @brief Construct a new Loup object
 *
 * @param x length value of the board
 * @param y height value of the board
 * @param a position X of the Loup
 * @param b position Y of the loup
 */
Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b)
{
    this->name = NAME_LOUP;
    this->living = 1;
}

/**
 * @brief Destroy the Loup object
 *
 */
Loup::~Loup()
{
}

/**
 * @brief Set the new position of the Loup
 *
 * @param x new X position
 * @param y new Y position
 */
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

/**
 * @brief Define the attack of the Loup
 *
 */
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