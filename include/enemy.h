#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

#include <SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <bits/stdc++.h>
using namespace std;

class enemy: public entity
{
    public:
        enemy();
        virtual ~enemy();

        float movementSpeed = 3;
        int movementLength = 150;
        int attackDamage = 1;
        int direction = 0; //1-up 2-down 3- left 4 -right

        float counter = 0;
        float counter2 = 0;

        int bloodCounter = 0;
        int bloodLifetime = 400;

        int hp = 3;
        int maxHp = 3;

        bool canMoveUp = true;
        bool canMoveDown = true;
        bool canMoveLeft = true;
        bool canMoveRight = true;

        int spritex = 40;
        int spritey = 40;
        int spritexStart = 40 * 0;
        int spriteyStart = 40 * 0;

        int previousDirection=0;

        float aggresiveTime=0;


        bool attackPlayer1 = false;
        bool attackPlayer2 = false;
        bool destroyWall = false;

        ///for defence only
        int selected = 4;
        int posX[4]={840,1040,840,1040};
        int posY[4]={460,460,660,660};

        int plusMinus40[2]={40,-40};
        int targetX = 0;
        int targetY = 0;

        bool upDown = true;
        bool leftRight = false;

        bool isIn = false;

        bool isBlood = false;
        bool playerDestroyed = false;

        bool alive = true;

        float prevPosX,prevPosY;

        bool aggresive = false;


        bool isMecha = false;
        bool isDrone = false;
        bool isProjectile = false;

        bool changeDirection = true;

        float changeSelectionTime = 4.0f;
        bool changeSelection = false;


        void update();
        void updateMovement();


    protected:

    private:
};

#endif // ENEMY_H
