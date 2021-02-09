#include "projectile.h"

projectile::projectile()
{
    //ctor
    rect.setSize(sf::Vector2f(20.f,20.f));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Green);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
}

projectile::~projectile()
{
    //dtor
}

void projectile::update()
{
    if( isPlayer1 == true)
    {
        if(isPlayerLevel1 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(0,0,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(120,0,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(80,0,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(40,0,40,40));
                rect.move(movementSpeed,0);
            }
            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
        if(isPlayerLevel2 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(0,40,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(120,40,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(80,40,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(40,40,40,40));
                rect.move(movementSpeed,0);
            }

            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
        if(isPlayerLevel3 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(0,80,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(120,80,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(80,80,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(40,80,40,40));
                rect.move(movementSpeed,0);
            }

            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
    }
    if( isPlayer2 == true)
    {
        if(isPlayerLevel1 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(160,0,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(160+120,0,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(160+80,0,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(160+40,0,40,40));
                rect.move(movementSpeed,0);
            }

            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
        if(isPlayerLevel2 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(160,40,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(160 + 120,40,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(160 + 80,40,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(160 + 40,40,40,40));
                rect.move(movementSpeed,0);
            }

            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
        if(isPlayerLevel3 == true)
        {
            if(direction == 1)//up
            {
                sprite.setTextureRect(sf::IntRect(160,80,40,40));
                rect.move(0,-movementSpeed);
            }
            if(direction == 2)//down
            {
                sprite.setTextureRect(sf::IntRect(160 + 120,80,40,40));
                rect.move(0,movementSpeed);
            }
            if(direction == 3)//left
            {
                sprite.setTextureRect(sf::IntRect(160 + 80,80,40,40));
                rect.move(-movementSpeed,0);
            }
            if(direction == 4)//right
            {
                sprite.setTextureRect(sf::IntRect(160 + 40,80,40,40));
                rect.move(movementSpeed,0);
            }

            counterLifetime++;
            if(counterLifetime >= lifeTime)
            {
                destroy = true;
            }
        }
    }


    //setting sprite position same as rect
    sprite.setPosition(rect.getPosition().x - rect.getSize().x/2,rect.getPosition().y - rect.getSize().y/2);
}
