#ifndef ATTAQUE_H_
#define ATTAQUE_H_
// ================================================================================
// Includes
// ================================================================================
#include <stdint.h>
#include <string>
#include <map>
#include "../util.hpp"

// ================================================================================
// Define
// ================================================================================

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================
enum class AttackType
{
    ROCK,
    PAPER,
    CISOR
};

const std::map<AttackType, std::string> g_attackTypes_toString = {
    {AttackType::ROCK, "Rock"},
    {AttackType::PAPER, "Paper"},
    {AttackType::CISOR, "Cisor"}};

// ================================================================================
// Class def
// ================================================================================

class Attaque
{
private:
    AttackType attack;

public:
    /**
     * @brief Construct a new Attaque object
     *
     */
    Attaque(void);

    /**
     * @brief Construct a new Attaque object
     * 
     * @param attack 
     */
    Attaque(AttackType attack); // Attack specific

    /**
     * @brief Destroy the Attaque object
     * 
     */
    ~Attaque();

    /**
     * @brief Get the Type Attaque object
     * 
     * @return AttackType 
     */
    AttackType getTypeAttaque() const;

    /**
     * @brief Returns true if the attack is better than the parameter
     * 
     * @param a An attack
     * @return true 
     * @return false 
     */
    bool resoudreAttaque(Attaque &a) const;

    /**
     * @brief Get the NomAttaque object
     * 
     * @return std::string 
     */
    std::string getNomAttaque(void) const;
};

#endif // ATTAQUE_H_