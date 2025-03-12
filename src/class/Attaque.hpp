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
enum class AttackType {
    ROCK,
    PAPER,
    CISOR
};

const std::map<AttackType, std::string> g_attackTypes_toString = {
    { AttackType::ROCK, "Rock" },
    { AttackType::PAPER, "Paper" },
    { AttackType::CISOR, "Cisor" }
};

// ================================================================================
// Class def
// ================================================================================

class Attaque {
private:
    AttackType attack;
public:
    Attaque(void); // Attack random
    Attaque(AttackType attack); // Attack specific
    ~Attaque();

    AttackType getTypeAttaque() const;
    bool resoudreAttaque(Attaque &a) const;
    std::string getNomAttaque(void) const;
};


#endif // ATTAQUE_H_