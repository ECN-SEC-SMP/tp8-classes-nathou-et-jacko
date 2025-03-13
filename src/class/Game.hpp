#ifndef _GAME_H_
#define _GAME_H_

// ================================================================================
// Includes
// ================================================================================
#include <vector>
#include <iostream>
#include "Animal.hpp"
using namespace std;

// ================================================================================
// Define
// ================================================================================
#define MAX_X 10
#define MAX_Y 10
#define NB_CASES MAX_X * MAX_Y

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
     * @brief Check if the Game is empty
     *
     * @return true
     * @return false
     */
    bool isEmpty();

    /**
     * @brief Displays the board in a terminal
     * 
     */
    void printBoardGame();
};

#endif