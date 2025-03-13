#ifndef _OURS_H_
#define _OURS_H_

#include "Animal.hpp"

class Ours : public Animal
{

private:
public:
    Ours(int maxX, int maxY);
    Ours(int maxX, int maxY, int a, int b);
    void setAttaque();

    void deplace(int maxX, int maxY);
};

#endif;