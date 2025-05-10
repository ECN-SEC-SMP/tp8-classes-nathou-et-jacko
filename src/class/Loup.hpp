#ifndef _LOUP_H_
#define _LOUP_H_

#include "Animal.hpp"

#define NAME_LOUP "Loup"

class Loup : public Animal
{

private:
public:
    /**
     * @brief Construct a new Loup object
     *
     * @param x length value of the board
     * @param y height value of the board
     */
    Loup(int x, int y);

    /**
     * @brief Construct a new Loup object
     * 
     * @param x length value of the board
     * @param y height value of the board
     * @param a position X of the Loup
     * @param b position Y of the loup
     */
    Loup(int x, int y, int a, int b);

    /**
     * @brief Destroy the Loup object
     * 
     */
    ~Loup();

    /**
     * @brief Define the attack of the Loup
     * 
     */
    void setAttaque();

    /**
     * @brief Set the new position of the Loup
     * 
     * @param x new X position
     * @param y new Y position
     */
    void deplace(int x, int y);
};

#endif