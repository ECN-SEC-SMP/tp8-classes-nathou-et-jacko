#ifndef _GAME_H_
#define _GAME_H_

// ================================================================================
// Includes
// ================================================================================
#include <vector>
#include <iostream>
#include "Animal.hpp"
#include <map>
using namespace std;

// ================================================================================
// Define
// ================================================================================
#define MAX_X 10
#define MAX_Y 10
#define NB_CASES MAX_X *MAX_Y

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

// ================================================================================
// Class def
// ================================================================================
class Game
{

private:
    // Y, X, vector of animals on the case
    vector<vector<vector<Animal *>>> board;

    void resetGame(void);

    void deplaceAll(void);

    /**
     * @brief Do the fight between 2 animals
     *
     * @param fighters Vectors of animals
     * @param fighterOne index of the first fighter
     * @param fighterTwo index of the second fighter
     * @return int index of the looser
     */
    int fight(vector<Animal *> fighters, int fighterOne, int fighterTwo);

    /**
     * @brief Count the member of animal on the board
     * 
     * @return uint32_t 
     */
    uint32_t countAnimals(void);

public:
    /**
     * @brief Construct a new Game object
     * Initialize Game by default
     */
    Game();

    /**
     * @brief Destroy the Game object
     */
    ~Game();

    /**
     * @brief Run each iteration of the game, return false at the end
     *
     * @return true
     * @return false
     */
    bool run(void);

    /**
     * @brief Resolve conflict inside the board
     *
     */
    map<string, int> resolveConflict();

    /**
     * @brief Displays the board in a terminal
     *
     */
    void printBoardGame();
};

#endif