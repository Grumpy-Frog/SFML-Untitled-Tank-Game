#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class projectile: public entity
{
    public:
        projectile();
        virtual ~projectile();

        int movementSpeed = 15;
        int attackDamage = 1;
        int direction = 0; //1-up 2-down 3- left 4 -right

        bool destroy = false;

        bool isPlayer1 = false;
        bool isPlayer2 = false;
        bool isEnemy = false;

        bool isPlayerLevel1 = false;
        bool isPlayerLevel2 = false;
        bool isPlayerLevel3 = false;

        bool fromEnemy = false;

        int counterLifetime = 0;
        int lifeTime = 40;  //projectile life time

        void update();
        //void updateMovement();

    protected:

    private:
};

#endif // PROJECTILE_H
