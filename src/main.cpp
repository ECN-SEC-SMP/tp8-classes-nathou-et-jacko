#include <iostream>

#include "util.hpp"
#include "class/Game.hpp"
#include "class/Attaque.hpp"


int main(int argc, char const *argv[]) {
    
    initRand();

    Attaque att;
    int i;
    for (i = 0; i < 100; i++) {
        att = Attaque();
        std::cout << i << ". " << att.getNomAttaque() << std::endl;
    }
    i++;
    att = Attaque(AttackType::ROCK);
    std::cout << i << ". " << att.getNomAttaque() << std::endl;
    i++;
    att = Attaque(AttackType::PAPER);
    std::cout << i << ". " << att.getNomAttaque() << std::endl;
    i++;
    att = Attaque(AttackType::CISOR);
    std::cout << i << ". " << att.getNomAttaque() << std::endl;

    return 0;
}
