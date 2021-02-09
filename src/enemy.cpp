#include "enemy.h"

int greaterRandom(int max)
{
    int randomNumber = rand();
    float random = (randomNumber % max)+1;
    int myRandom = random;
    return myRandom;
}


enemy::enemy()
{
    //ctor
    rect.setSize(sf::Vector2f(35.f,35.f));
    //rect.setPosition(400,200);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
    //sprite.setOrigin(40/2.f,40/2.f);
}

enemy::~enemy()
{
    //dtor
}

void enemy::update()
{
    if(isBlood == true)
    {
        counter+=0.21;
        if(counter > 12)
        {
           alive = false;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),0,40,40));
    }

    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x -  rect.getSize().x/2 + 5,rect.getPosition().y - rect.getSize().y/2 -5);


    if(isDrone == true)
    {
        counter+=0.4;
        if(counter >8)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),0,40,40));
    }

    if(isProjectile == true)
    {
        if(direction == 4)
        {
            counter+=0.5;
            if(counter >2)
            {
                alive = false;
            }
            sprite.setTextureRect(sf::IntRect(40*int(counter),40,40,40));
        }
        if(direction == 3)
        {
            counter+=0.5;
            if(counter >2)
            {
                alive = false;
            }
            sprite.setTextureRect(sf::IntRect(40*int(counter),80,40,40));
        }
        if(direction == 1)
        {
            counter+=0.5;
            if(counter >2)
            {
                alive = false;
            }
            sprite.setTextureRect(sf::IntRect(40*int(counter),0,40,40));
        }
        if(direction == 2)
        {
            counter+=0.5;
            if(counter >2)
            {
                alive = false;
            }
            sprite.setTextureRect(sf::IntRect(40*int(counter),120,40,40));
        }
    }
}


void enemy::updateMovement()
{
    if(isMecha == true)
    {
        if(direction == 3) //left
        {
            if(canMoveLeft)
            {
                if(counter2 > 7)
                {
                    counter2 = 0;
                }
                counter2+=0.1;
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(80,40*int(counter2),40,40));
                //direction = 3;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 4) // right
        {
            if(canMoveRight)
            {
                if(counter2 > 7)
                {
                    counter2 = 0;
                }
                counter2+=0.1;
                rect.move(movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(40,40*int(counter2),40,40));
                //direction = 4;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 1) // up
        {
            if(canMoveUp)
            {
                if(counter2 > 7)
                {
                    counter2 = 0;
                }
                counter2+=0.1;
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(0,40*int(counter2),40,40));
                //direction = 1;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 2) // down
        {
            if(canMoveDown)
            {
                if(counter2 > 7)
                {
                    counter2 = 0;
                }
                counter2+=0.1;
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(120,40*int(counter2),40,40));
                //direction = 2;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else
        {
            //no movement
        }
        if(aggresive == false)
        {
            counter++;
            if(counter >= movementLength)
            {
                direction = greaterRandom(12);
                counter=0;
            }
        }
    }
    if(isDrone == true)
    {
        if(direction == 3) //left
        {
            if(canMoveLeft)
            {
                rect.move(-movementSpeed,0);
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 4) // right
        {
            if(canMoveRight)
            {
                rect.move(movementSpeed,0);
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 1) // up
        {
            if(canMoveUp)
            {
                rect.move(0,-movementSpeed);
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(direction == 2) // down
        {
            if(canMoveDown)
            {
                rect.move(0,movementSpeed);
                //direction = 2;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else
        {
            //no movement
        }
        if(aggresive == false)
        {
            counter++;
            if(counter >= movementLength)
            {
                direction = greaterRandom(12);
                counter=0;
            }
        }

    }
}

