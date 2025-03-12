#ifndef _ANIMAL_H_
#define _ANIMAL_H_
// ================================================================================
// Includes
// ================================================================================
#include <string>
#include <stdexcept>
#include "Attaque.hpp"
using namespace std;

// ================================================================================
// Define
// ================================================================================

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

// ================================================================================
// Class def
// ================================================================================
class Animal
{
protected:
    string name;
    int x;
    int y;
    bool living;
    Attaque typeAttaque;
public:
    /**
     * @brief Construct a new Animal object
     *
     * @param maxX
     * @param maxY
     */
    Animal(int maxX, int maxY);

    Animal(int maxX, int maxY, int a, int b);

    /**
     * @brief Get the Name object
     *
     * @return string
     */
    string getName() const;

    /**
     * @brief Get X property
     *
     * @return int
     */
    int getX() const;

    /**
     * @brief Get Y property
     *
     * @return int
     */
    int getY() const;

    /**
     * @brief Get the Vivant object
     *
     * @return true
     * @return false
     */
    bool getVivant() const;

    /**
     * @brief Get the Attaque object
     * 
     * @return Attaque 
     */
    Attaque getAttaque() const;

    /**
     * @brief Set the Vivant object
     *
     * @param b
     */
    void setVivant(bool b);

    /**
     * @brief Attack an animal
     *
     * @param a the animal
     * @return true
     * @return false
     */
    bool attaque(Animal &a);

    /**
     * @brief Define the Attaque function for children
     * 
     */
    virtual void setAttaque();

    /**
     * @brief Define the Deplace function for children
     * 
     * @param maxX 
     * @param maxY 
     */
    virtual void deplace(int maxX, int maxY);
};

#endif