#ifndef PICKUP_H
#define PICKUP_H

#include "entity.h"

class pickUp : public entity
{
    public:
        pickUp();
        virtual ~pickUp();

        int coinValue = 1;
        float counter = 0;



        bool isCoin = false;
        bool isHpSheild = false;
        bool isShield = false;
        bool isSpeedUp = false;
        bool isInvisibility = false;
        bool isMineBomb = false;

        bool destroy = false;

        //bool isShop = false;
        //int cost = 0;

        void update();
        //void updateMovement();

    protected:

    private:
};

#endif // PICKUP_H
