#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

#include <SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <bits/stdc++.h>

class player: public entity
{
public:
    player();
    virtual ~player();


    int movementSpeed = 2;

    int attackDamage =1;
    int direction = 0; //1-up 2-down 3- left 4 -right

    int hp = 5;
    int maxHp = 5;
    int points = 0;

    float counter = 0;


    bool isShield = false;

    bool isSpeedUp = false;
    int speedUpSpeed = 5;
    int normalSpeed = 3;

    bool isPlayer1 = false;
    bool isPlayer2 = false;


    bool isInvisibility = false;

    bool isAlive = true;


    bool playerLevelChanged = false;

    bool isLevel1 = false;
    bool isLevel2 = false;
    bool isLevel3 = false;


    bool canMoveUp = true;
    bool canMoveDown = true;
    bool canMoveLeft = true;
    bool canMoveRight = true;


    void update();
    void updateMovement();


protected:

private:
};

#endif // PLAYER_H
