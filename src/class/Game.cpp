// ================================================================================
// Includes
// ================================================================================
#include "Game.hpp"

#include "Animal.hpp"

// ================================================================================
// Define
// ================================================================================
#define DISTRIB_PLATEAU 25 // Pourcent, le plateau est de 10x10 donc 100 cases donc 25 = 25% de 100

// ================================================================================
// Types (Struct, enum, ...)
// ================================================================================

// ================================================================================
// Prototype
// ================================================================================

// ================================================================================
// Class def
// ================================================================================

/**
 * @brief Construct a new Game object
 * Initialize Game by default
 */
Game::Game() {
    this->board = vector<vector<vector<Animal *>>>(MAX_Y, vector<vector<Animal *>>(MAX_X, vector<Animal*>(0)));
    this->resetGame();
};

/**
 * @brief Check if the Game is empty
 *
 * @return true
 * @return false
 */
bool Game::isEmpty()
{
    for (vector<vector<Animal *>> vect : this->board)
    {
        for (vector<Animal*> animalVect : vect)
        {
            // If there is at least on animal on a case
            if (animalVect.size() != NULL) {
                return false;
            }
        }
    }
    return true;
}

Game::~Game() {
    Animal* anim_temp;

    for (vector<vector<Animal *>> vect : this->board) {
        for (vector<Animal*> animalVect : vect) {
            while (animalVect.size() > 0) {
                anim_temp = animalVect.back();  // Get element
                animalVect.pop_back();  // Remove from vector
                delete anim_temp;   // Delete memory
            }
        }
    }
    
}

void Game::resetGame(void) {
    Animal* temp;

    // Where DISTRIB_PLATEAU is the percentage of animal on the board
    uint32_t nb_animals = (DISTRIB_PLATEAU * NB_CASES) / 100;

    int animX;
    int animY;

    for (uint32_t i = 0; i < nb_animals; i++) {
        // temp = new Animal(MAX_X, MAX_Y);
        animX = temp->getX();
        animY = temp->getY();
        this->board.at(animY).at(animX).push_back(temp);
        cout << "[resetGame] add animal to x : " << animX << " y : " << animY << endl;
    }
    
}

/**
 * @brief Displays the board in a terminal
 *
 */
void Game::printBoardGame()
{

    for (int i = 0; i < MAX_Y; i++)
    {
        cout << "----";
    }
    cout << "-" << endl;
    for (vector<vector<Animal *>> vect : this->board)
    {
        for (vector<Animal *> animalVect : vect)
        {
            cout << "| ";
            if (animalVect.size() != NULL) {
                cout << "🙃";
            } else {
                cout << " ";
            }
            cout << ' ';
        }
        cout << "|" << endl;
        for (int i = 0; i < MAX_Y; i++)
        {
            cout << "|---";
        }
        cout << "|" << endl;
    }
}

// ================================================================================
// Fonctions
// ================================================================================
