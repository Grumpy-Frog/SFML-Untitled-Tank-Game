#include "textDisplay.h"

textDisplay::textDisplay()
{
    //ctor
    text.setColor(sf::Color::Red);
    text.setCharacterSize(30);
    text.setPosition(300,300);
    text.setString(myString);
}

textDisplay::~textDisplay()
{
    //dtor
}


void textDisplay::update()
{
    text.move(0,-movementSpeed);

    counter++;
    if(counter >= lifeTime)
    {
        destroy = true;
    }
}
