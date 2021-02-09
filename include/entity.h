#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <bits/stdc++.h>

using namespace std;

class entity
{
    public:
        entity();
        virtual ~entity();

        //Physical object
        sf::RectangleShape rect;
        sf::Sprite sprite;
        sf::Text text;


    protected:

    private:

};

#endif // ENTITY_H
