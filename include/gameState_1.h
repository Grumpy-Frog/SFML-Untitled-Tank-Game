#ifndef GAMESTATE_1_H
#define GAMESTATE_1_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include <bits/stdc++.h>
using namespace std;

class gameState_1
{
    public:
        gameState_1();
        virtual ~gameState_1();

        int gameState1(sf::RenderWindow &window);
        int greaterRandom1(int max);
        void wait(float f);

    protected:

    private:
};

#endif // GAMESTATE_1_H
