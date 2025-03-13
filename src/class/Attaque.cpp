// ================================================================================
// Includes
// ================================================================================
#include "Attaque.hpp"
// cpp

// Project

// ================================================================================
// Define
// ================================================================================

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

// ================================================================================
// Prototype
// ================================================================================
AttackType getRandAttack(void);

// ================================================================================
// Class def
// ================================================================================

/**
 * @brief Construct a new Attaque object
 *
 */

Attaque::Attaque(void) : attack{getRandAttack()} {}

/**
 * @brief Construct a new Attaque object
 *
 * @param attack
 */
Attaque::Attaque(AttackType attack) : attack{attack} {}

/**
 * @brief Destroy the Attaque object
 *
 */
Attaque::~Attaque()
{
}

/**
 * @brief Get the Type Attaque object
 *
 * @return AttackType
 */
AttackType Attaque::getTypeAttaque() const
{
    return this->attack;
}

/**
 * @brief Returns true if the attack is better than the parameter
 *
 * @param a An attack
 * @return true
 * @return false
 */
bool Attaque::resoudreAttaque(Attaque &a) const
{
    // Rock > Cisor
    // Paper > Rock
    // Cisor > Paper
    if (this->attack == AttackType::ROCK && a.attack == AttackType::CISOR ||
        this->attack == AttackType::PAPER && a.attack == AttackType::ROCK ||
        this->attack == AttackType::CISOR && a.attack == AttackType::PAPER)
    {
        return true;
    }
    return false;
}

std::string Attaque::getNomAttaque() const
{
    return g_attackTypes_toString.at(this->attack);
}

// ================================================================================
// Fonctions
// ================================================================================
/**
 * @brief Get the Rand Attack object
 *
 * @return AttackType
 */
AttackType getRandAttack(void)
{
    // Attack enum correspond to integer form 0 to 2
    return (AttackType)getRand((int8_t)AttackType::ROCK, (int8_t)AttackType::CISOR);
}
