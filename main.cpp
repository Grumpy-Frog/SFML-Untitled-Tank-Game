#include "player.h"
#include "entity.h"
#include "projectile.h"
#include "enemy.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "wall.h"
#include "gameZone.h"

#include <bits/stdc++.h>
using namespace std;

gameZone myGameZone;

int main()
{
    sf::RenderWindow mainMenuWindow(sf::VideoMode::getDesktopMode(),"UNTITLED TANK GAME", sf::Style::Fullscreen);
    mainMenuWindow.setFramerateLimit(20);

    mainMenuWindow.clear();
    sf::Image icon;
    icon.loadFromFile("images/icon.png");
    mainMenuWindow.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    sf::Texture mainMenuButtonTexture;
    if(!mainMenuButtonTexture.loadFromFile("images/buttons final.png"))
    {
        return 0;
    }

    sf::Texture background;
    if(!background.loadFromFile("images/mainmenubackground.png"))
    {
        cout<<"mainmenubackground.png error\n";
        return 0;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(background);
    backgroundSprite.setTextureRect(sf::IntRect(0,0,1920,1080));

    sf::Sprite playButton;
    sf::Sprite controlsButton;
    sf::Sprite hallOfFameButton;
    sf::Sprite creditsButton;
    sf::Sprite exitButton;


    sf::Music music;
    if(!music.openFromFile("sounds/mainmenu.wav"))
    {
        cout<<"Error music.ogg\n";
        return 0;
    }
    music.play();
    music.setLoop(true);
    music.setVolume(50);

    sf::Texture splashTexture;
    if(!splashTexture.loadFromFile("images/splashloop1t.png"))
    {
        cout<<"splashloop1 error\n";
        return 0;
    }
    sf::Sprite splashSprite;
    splashSprite.setTexture(splashTexture);
    splashSprite.setScale(3.75,3.75);

    sf::SoundBuffer upDownSoundBuffer;
    if(!upDownSoundBuffer.loadFromFile("sounds/blink.ogg"))
    {
        cout<<"Sound error blink.ogg\n";
        return 0;
    }
    sf::Sound upDownSound;
    upDownSound.setBuffer(upDownSoundBuffer);


    sf::SoundBuffer windowChangeBuffer;
    if(!windowChangeBuffer.loadFromFile("sounds/button.ogg"))
    {
        cout<<"Sound error button.ogg\n";
        return 0;
    }
    sf::Sound windowChangeSound;
    windowChangeSound.setBuffer(windowChangeBuffer);



    sf::Font font;
    font.loadFromFile("fonts/pixel.ttf");

    sf::Text text;
    text.setFont(font);

    text.setString("PRESS SPACE TO CONTINUE");
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(680,1020));


    ///Variables///////////
    int selectedItemIndex = 0;
    int clickedItem = 0;
    int i=0;

    float counter = 0;
    int frame = 31;

    bool showingSplash = true;
    bool showingSplash1 = true;
    bool noSplash = false;

    bool active = true;


    //mainMenuWindow.setMouseCursorVisible(false);

    while (mainMenuWindow.isOpen())
    {
        sf::Event event;
        while (mainMenuWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                mainMenuWindow.close();
            }
            if(noSplash == true)
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        if (selectedItemIndex - 1 >= 0)
                        {
                            upDownSound.play();
                            selectedItemIndex--;
                        }
                        else
                        {
                            upDownSound.play();
                            selectedItemIndex = 4;
                        }
                        break;
                    case sf::Keyboard::W:
                        if (selectedItemIndex - 1 >= 0)
                        {
                            upDownSound.play();
                            selectedItemIndex--;
                        }
                        else
                        {
                            upDownSound.play();
                            selectedItemIndex = 4;
                        }
                        break;

                    case sf::Keyboard::Down:
                        if (selectedItemIndex + 1 < 5)
                        {
                            upDownSound.play();
                            selectedItemIndex++;
                        }
                        else
                        {
                            selectedItemIndex = 0;
                            upDownSound.play();
                        }
                        break;
                    case sf::Keyboard::S:
                        if (selectedItemIndex + 1 < 5)
                        {
                            upDownSound.play();
                            selectedItemIndex++;
                        }
                        else
                        {
                            selectedItemIndex = 0;
                            upDownSound.play();
                        }
                        break;

                    case sf::Keyboard::Return:
                        switch (selectedItemIndex)
                        {
                        case 0:
                        {
                            cout << "Play button has been pressed" << endl;
                            clickedItem = 1;
                            break;
                        }
                        case 1:
                            cout << "controls button has been pressed" << endl;
                            clickedItem = 2;
                            break;
                        case 2:
                            cout << "hall of fame\n";
                            clickedItem = 3;
                            break;
                        case 3:
                            cout<<"credits\n";
                            clickedItem = 4;
                            break;
                        case 4:
                            cout<<"exit\n";
                            clickedItem = 5;
                            break;
                        }
                        break;
                    case sf::Keyboard::Space:
                        switch (selectedItemIndex)
                        {
                        case 0:
                        {
                            cout << "Play button has been pressed" << endl;
                            clickedItem = 1;
                            break;
                        }
                        case 1:
                            cout << "controls button has been pressed" << endl;
                            clickedItem = 2;
                            break;
                        case 2:
                            cout << "hall of fame\n";
                            clickedItem = 3;
                            break;
                        case 3:
                            cout<<"credits\n";
                            clickedItem = 4;
                            break;
                        case 4:
                            cout<<"exit\n";
                            clickedItem = 5;
                            break;
                        }
                        break;
                    }
                    break;
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            showingSplash1 = false;
        }

        mainMenuWindow.clear(sf::Color::Black);

        //if(showingSplash1 == false)

        mainMenuWindow.draw(backgroundSprite);

        ///Draw Button main menu
        if(clickedItem == 1)
        {
            playButton.setTexture(mainMenuButtonTexture);
            playButton.setTextureRect(sf::IntRect(800,0,400,400));
            playButton.setPosition(sf::Vector2f(760,450));
            mainMenuWindow.draw(playButton);


        }
        else if(selectedItemIndex == 0)
        {
            playButton.setTexture(mainMenuButtonTexture);
            playButton.setTextureRect(sf::IntRect(400,0,400,400));
            playButton.setPosition(sf::Vector2f(760,450));
            mainMenuWindow.draw(playButton);
        }
        else
        {
            playButton.setTexture(mainMenuButtonTexture);
            playButton.setTextureRect(sf::IntRect(0,0,400,400));
            playButton.setPosition(sf::Vector2f(760,450));
            mainMenuWindow.draw(playButton);
        }

        if(clickedItem == 2)
        {
            controlsButton.setTexture(mainMenuButtonTexture);
            controlsButton.setTextureRect(sf::IntRect(800,400,400,400));
            controlsButton.setPosition(sf::Vector2f(760,530));
            mainMenuWindow.draw(controlsButton);
        }
        else if(selectedItemIndex == 1)
        {
            controlsButton.setTexture(mainMenuButtonTexture);
            controlsButton.setTextureRect(sf::IntRect(400,400,400,400));
            controlsButton.setPosition(sf::Vector2f(760,530));
            mainMenuWindow.draw(controlsButton);
        }
        else
        {
            controlsButton.setTexture(mainMenuButtonTexture);
            controlsButton.setTextureRect(sf::IntRect(0,400,400,400));
            controlsButton.setPosition(sf::Vector2f(760,530));
            mainMenuWindow.draw(controlsButton);
        }

        if(clickedItem == 3)
        {
            hallOfFameButton.setTexture(mainMenuButtonTexture);
            hallOfFameButton.setTextureRect(sf::IntRect(800,800,400,400));
            hallOfFameButton.setPosition(sf::Vector2f(760,600));
            mainMenuWindow.draw(hallOfFameButton);
        }
        else if(selectedItemIndex == 2)
        {
            hallOfFameButton.setTexture(mainMenuButtonTexture);
            hallOfFameButton.setTextureRect(sf::IntRect(400,800,400,400));
            hallOfFameButton.setPosition(sf::Vector2f(760,600));
            mainMenuWindow.draw(hallOfFameButton);
        }
        else
        {
            hallOfFameButton.setTexture(mainMenuButtonTexture);
            hallOfFameButton.setTextureRect(sf::IntRect(0,800,400,400));
            hallOfFameButton.setPosition(sf::Vector2f(760,600));
            mainMenuWindow.draw(hallOfFameButton);
        }

        if(clickedItem == 4)
        {
            creditsButton.setTexture(mainMenuButtonTexture);
            creditsButton.setTextureRect(sf::IntRect(800,1200,400,400));
            creditsButton.setPosition(sf::Vector2f(760,685));
            mainMenuWindow.draw(creditsButton);
        }
        else if(selectedItemIndex == 3)
        {

            creditsButton.setTexture(mainMenuButtonTexture);
            creditsButton.setTextureRect(sf::IntRect(400,1200,400,400));
            creditsButton.setPosition(sf::Vector2f(760,685));
            mainMenuWindow.draw(creditsButton);
        }
        else
        {
            creditsButton.setTexture(mainMenuButtonTexture);
            creditsButton.setTextureRect(sf::IntRect(0,1200,400,400));
            creditsButton.setPosition(sf::Vector2f(760,680));
            mainMenuWindow.draw(creditsButton);
        }

        if(clickedItem == 5)
        {
            exitButton.setTexture(mainMenuButtonTexture);
            exitButton.setTextureRect(sf::IntRect(800,1600,400,400));
            exitButton.setPosition(sf::Vector2f(760,750));
            mainMenuWindow.draw(exitButton);
        }
        else if(selectedItemIndex == 4)
        {
            exitButton.setTexture(mainMenuButtonTexture);
            exitButton.setTextureRect(sf::IntRect(400,1600,400,400));
            exitButton.setPosition(sf::Vector2f(760,750));
            mainMenuWindow.draw(exitButton);
        }
        else
        {
            exitButton.setTexture(mainMenuButtonTexture);
            exitButton.setTextureRect(sf::IntRect(0,1600,400,400));
            exitButton.setPosition(sf::Vector2f(760,750));
            mainMenuWindow.draw(exitButton);
        }


RAFI2:
        if(showingSplash == true )
        {
            counter += 1;
            if(counter > frame)
            {
                counter = 0;
                if(frame == 18)
                {
                    noSplash = true;
                    if(noSplash == true)
                    {
                        showingSplash = false;
                        goto RAFI2;
                    }
                }
                if(showingSplash1 == false && counter == 0)
                {
                    if(!splashTexture.loadFromFile("images/loop2.png"))
                    {
                        cout<<"loop2 error\n";
                        return 0;
                    }
                    splashSprite.setScale(1,1);
                    splashSprite.setScale(3,3);
                    frame = 18;
                }

            }

            if(frame == 31)
            {
                splashSprite.setTextureRect(sf::IntRect(512*int(counter),0,512,288));
                mainMenuWindow.draw(splashSprite);
            }
            if( frame == 18)
            {
                splashSprite.setTextureRect(sf::IntRect(640*int(counter),0,640,360));
                mainMenuWindow.draw(splashSprite);
            }
        }


        if(showingSplash1 == true)
        {
            if(active)
            {
                mainMenuWindow.draw(text);
                if(i==8)
                {
                    active = false;
                    i=0;
                }
            }
            else
            {
                if( i ==10)
                {
                    active = true;
                    i=0;
                }
            }
            i++;
        }


        mainMenuWindow.display();

        switch (clickedItem)
        {
        case 0:
            system("CLS");
            break;
        case 1:
        {
            windowChangeSound.play();
            //mainMenuWindow.setActive(false);
            //gameState1();
            //music.stop();
            myGameZone.selectMode(mainMenuWindow,music);
            clickedItem = 0;
            //cout<<music.getStatus()<<" music status\n";
            if(music.getStatus() == 0)
            {
                music.play();
            }
            //mainMenuWindow.setActive(true);
        }
        break;
        case 2:
        {
            windowChangeSound.play();
            // mainMenuWindow.setActive(false);
            myGameZone.controlsPage(mainMenuWindow);
            clickedItem = 0;
            // mainMenuWindow.setActive(true);
        }
        break;
        case 3:
            windowChangeSound.play();
            //  mainMenuWindow.setActive(false);
            myGameZone.hallOfFamePage(mainMenuWindow);
            clickedItem = 0;
            //   mainMenuWindow.setActive(true);
            break;
        case 4:
            windowChangeSound.play();
            //   mainMenuWindow.setActive(false);
            myGameZone.creditPage(mainMenuWindow);
            clickedItem = 0;
            //  mainMenuWindow.setActive(true);
            break;
        case 5:
            windowChangeSound.play();
            myGameZone.wait(1);
            mainMenuWindow.close();
            break;
        }

    }
}
