#ifndef _LION_H_
#define _LION_H_

#include "Animal.hpp"

class Lion : public Animal
{

private:
public:
    Lion(int maxX, int maxY);
    Lion(int maxX, int maxY, int a, int b);
    void setAttaque();

    void deplace(int maxX, int maxY);
};

#endif;