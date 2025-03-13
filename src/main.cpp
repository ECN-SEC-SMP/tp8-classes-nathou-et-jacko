#include <iostream>

#include "util.hpp"
#include "class/Game.hpp"
#include "class/Attaque.hpp"


int main(int argc, char const *argv[]) {
    
    initRand();

    Game game = Game();

    game.printBoardGame();

    return 0;
}
