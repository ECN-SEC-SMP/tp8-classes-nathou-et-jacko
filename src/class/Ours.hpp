#ifndef _OURS_H_
#define _OURS_H_

#include "Animal.hpp"

class Ours : public Animal
{

    private:

    public:
        void setAttaque();

        void deplace(int maxX, int maxY);
};

#endif;