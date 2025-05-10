#ifndef _LION_H_
#define _LION_H_

#include "Animal.hpp"

#define NAME_LION "Lion"

class Lion : public Animal
{

private:
public:
    /**
     * @brief Construct a new Lion object
     *
     * @param x length value of the board
     * @param y height value of the board
     */
    Lion(int x, int y);

    /**
     * @brief Construct a new Lion object
     *
     * @param x length value of the board
     * @param y heught value of the board
     * @param a X position  of the lion
     * @param b Y position of the lion
     */
    Lion(int x, int y, int a, int b);

    /**
     * @brief Destroy the Lion object
     *
     */
    ~Lion();

    /**
     * @brief Define the attack of the lion
     *
     */
    void setAttaque();

    /**
     * @brief Set the new position of the lion
     *
     * @param x new X position
     * @param y new Y position
     */
    void deplace(int x, int y);
};

#endif