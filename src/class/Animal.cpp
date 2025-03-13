#include "Animal.hpp"
/**
 * @brief Construct a new Animal object
 *
 * @param maxX Max x length of the board
 * @param maxY Max y length of the board
 */
Animal::Animal(int maxX, int maxY)
{
    this->x = getRand(0, maxX - 1);
    this->y = getRand(0, maxY - 1);
}

/**
 * @brief Construct a new Animal object
 *
 * @param maxX Max x length of the board
 * @param maxY Max y length of the board
 * @param a position X of the animal
 * @param b position Y of the animal
 */
Animal::Animal(int maxX, int maxY, int a, int b)
{
    this->x = a;
    this->y = b;
}

/**
 * @brief Get the Name object
 *
 * @return string
 */
string Animal::getName() const
{
    return this->name;
}

/**
 * @brief Get X property
 *
 * @return int
 */
int Animal::getX(void) const
{
    return this->x;
}

/**
 * @brief Get Y property
 *
 * @return int
 */
int Animal::getY(void) const
{
    return this->y;
}

/**
 * @brief Get the Vivant object
 *
 * @return true
 * @return false
 */
bool Animal::getVivant() const
{
    return this->living;
}

/**
 * @brief Set the Vivant object
 *
 * @param b
 */
void Animal::setVivant(bool y)
{

    if (y != 0 && y != 1)
    {
        throw invalid_argument("Y doit valoir 0 ou 1.");
    }
    this->living = y;
}

/**
 * @brief Get the Attaque object
 *
 * @return Attaque
 */
Attaque Animal::getAttaque() const
{
    return this->typeAttaque;
}

/**
 * @brief Attack an animal
 *
 * @param a the animal
 * @return true
 * @return false
 */
bool Animal::attaque(Animal &a)
{
    Attaque target = a.getAttaque();
    return this->typeAttaque.resoudreAttaque(target);
}
