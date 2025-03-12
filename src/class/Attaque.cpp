// ================================================================================
// Includes
// ================================================================================
#include "Attaque.hpp"
// cpp

// Project
#include "util.hpp"

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

Attaque::Attaque(void) {
    this->attack = getRandAttack();
}

Attaque::Attaque(AttackType attack) {

}

Attaque::~Attaque() {

}

AttackType Attaque::getTypeAttaque() const {

}

bool Attaque::resoudreAttaque(Attaque &a) const {

}

std::string Attaque::getNomAttaque() const {
    return attackTypes_toString[this->attack];
}

// ================================================================================
// Fonctions
// ================================================================================
/**
 * @brief Get the Rand Attack object
 * 
 * @return AttackType 
 */
AttackType getRandAttack(void) {
    // Attack enum correspond to integer form 0 to 2
    return (AttackType)getRand((int8_t)AttackType::ROCK, (int8_t)AttackType::CISOR);
}
