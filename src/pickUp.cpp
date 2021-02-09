#include "pickUp.h"

pickUp::pickUp()
{
    //ctor
    rect.setSize(sf::Vector2f(40,40));
    //rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Yellow);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
}

pickUp::~pickUp()
{
    //dtor
}


void pickUp::update()
{
    text.setPosition(rect.getPosition().x -10,rect.getPosition().y - 30);
    sprite.setPosition(rect.getPosition());
    if(isCoin == true)
    {
        sprite.setTextureRect(sf::IntRect(40*int(counter),120,40,40));
        counter+=0.1;
        if(counter >=10)
        {
            counter=0;
        }
    }
    if(isMineBomb == true)
    {
        counter+=0.1;
        if(counter >10)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),200,40,40));
    }
    if(isShield == true)
    {
        counter+=0.1;
        if(counter >10)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),40,40,40));
    }
    if(isSpeedUp == true)
    {
        counter+=0.1;
        if(counter >10)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),80,40,40));
    }
    if(isInvisibility == true)
    {
        counter+=0.1;
        if(counter >10)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),0,40,40));
    }
    if(isHpSheild == true)
    {
        counter+=0.1;
        if(counter >10)
        {
            counter=0;
        }
        sprite.setTextureRect(sf::IntRect(40*int(counter),160,40,40));
    }

}
