#ifndef _PIERRE_H_
#define _PIERRE_H_

#include "Animal.hpp"

#define NAME_PIERRE "Pierre"

class Pierre : public Animal
{

private:
public:
    /**
     * @brief Construct a new Pierre object
     *
     * @param x length value of the board
     * @param y height value of the board
     */
    Pierre(int x, int y);

    /**
     * @brief Construct a new Pierre object
     *
     * @param x Length value of the board
     * @param y height value of the board
     * @param a position X of the Pierre
     * @param b position Y of the Pierre
     */
    Pierre(int x, int y, int a, int b);

    /**
     * @brief Destroy the Pierre object
     *
     */
    ~Pierre();

    /**
     * @brief Define the attack of the Pierre
     *
     */
    void setAttaque();

    /**
     * @brief Define the new position of the Pierre
     * (Doesn't move because it's a rock)
     *
     * @param x new X position of the Pierre
     * @param y new Y position of the Pierre
     */
    void deplace(int x, int y);
};

#endif