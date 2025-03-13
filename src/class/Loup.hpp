#ifndef _LOUP_H_
#define _LOUP_H_

#include "Animal.hpp"

class Loup : public Animal
{

private:
public:
    Loup(int maxX, int maxY);
    Loup(int maxX, int maxY, int a, int b);
    void setAttaque();

    void deplace(int maxX, int maxY);
};

#endif;