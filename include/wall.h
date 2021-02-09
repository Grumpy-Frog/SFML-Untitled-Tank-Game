#ifndef WALL_H
#define WALL_H

#include "entity.h"

class wall : public entity
{
    public:
        wall();
        virtual ~wall();

        bool destructable = false;
        bool isColliedable = false;
        bool isProjectilePassable = false;
        bool isJungle = false;

        bool isWater = false;

        bool destroy = false;

        int hp = 5;

        void update();

    protected:

    private:
};

#endif // WALL_H
