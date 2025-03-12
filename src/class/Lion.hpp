#ifndef _LION_H_
#define _LION_H_

#include "Animal.hpp"

class Lion : public Animal
{

    private:

    public:
        void setAttaque();

        void deplace(int maxX, int maxY);
};

#endif;