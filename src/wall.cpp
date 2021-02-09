#include "wall.h"

wall::wall()
{
    //ctor
    rect.setSize(sf::Vector2f(40,40));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::White);
    sprite.setTextureRect(sf::IntRect(0,0,40,40));
}

wall::~wall()
{
    //dtor
}

void wall::update()
{
    sprite.setPosition(rect.getPosition());
}
