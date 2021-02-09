#include "player.h"

player::player()
{
    //ctor
    rect.setSize(sf::Vector2f(36.f,36.f));
    rect.setPosition(400,200);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
    //sprite.setOrigin(40/2.f,40/2.f);
}

player::~player()
{
    //dtor
}

void player::update()
{
    sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
    if(isPlayer1 == true && isAlive == true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(canMoveLeft == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(40,40*int(counter),40,40));
                direction = 3;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(canMoveRight == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(120,40*int(counter),40,40));
                direction = 4;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(canMoveUp == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(0,40*int(counter),40,40));
                direction = 1;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(canMoveDown == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(80,40*int(counter),40,40));
                direction = 2;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
    }
    if(isPlayer2 == true && isAlive==true)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(canMoveLeft == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(-movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(40,40*int(counter),40,40));
                direction = 3;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(canMoveRight == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(movementSpeed,0);
                sprite.setTextureRect(sf::IntRect(120,40*int(counter),40,40));
                direction = 4;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(canMoveUp == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(0,-movementSpeed);
                sprite.setTextureRect(sf::IntRect(0,40*int(counter),40,40));
                direction = 1;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(canMoveDown == true)
            {
                if(counter > 3)
                {
                    counter = 0;
                }
                counter += 0.1;
                rect.move(0,movementSpeed);
                sprite.setTextureRect(sf::IntRect(80,40*int(counter),40,40));
                direction = 2;
                canMoveUp = true;
                canMoveDown = true;
                canMoveLeft = true;
                canMoveRight = true;

            }
        }
    }
}
