#ifndef _OURS_H_
#define _OURS_H_

#include "Animal.hpp"

#define NAME_OURS "Ours"

class Ours : public Animal
{

private:
public:
    /**
     * @brief Construct a new Ours object
     *
     * @param x length value of the board
     * @param y height value of the board
     */
    Ours(int x, int y);

    /**
     * @brief Construct a new Ours object
     *
     * @param x length value of the board
     * @param y height value of the board
     * @param a X position of the Ours
     * @param b Y position of the Ours
     */
    Ours(int x, int y, int a, int b);

    /**
     * @brief Destroy the Ours object
     *
     */
    ~Ours();

    /**
     * @brief Define the attack of the Ours
     *
     */
    void setAttaque();

    /**
     * @brief Set the new position of the Ours
     *
     * @param x new X position
     * @param y new Y position
     */
    void deplace(int x, int y);
};

#endif