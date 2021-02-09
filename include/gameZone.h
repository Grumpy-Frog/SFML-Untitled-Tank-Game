#ifndef GAMEZONE_H
#define GAMEZONE_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

class gameZone
{
    public:
        gameZone();
        virtual ~gameZone();


        int gameState1(sf::RenderWindow &window);
        int gameState2(sf::RenderWindow &window);
        int gameState3(sf::RenderWindow &window);

        int online();

        int defenceMatch1(sf::RenderWindow &window);

        int greaterRandom1(int max);
        void wait(float f);

        void controlsPage(sf::RenderWindow &controlWindow);
        void creditPage(sf::RenderWindow &creditsWindow);
        void hallOfFamePage(sf::RenderWindow &fameWindow);
        void selectDeathMap(bool death,bool defence,sf::RenderWindow &mainMenuWindow,sf::Music &music);
        void selectMode(sf::RenderWindow &mainMenuWindow,sf::Music &music);



    protected:

    private:
};

#endif // GAMEZONE_H
