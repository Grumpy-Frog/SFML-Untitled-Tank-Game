#include "gameState_1.h"

gameState_1::gameState_1()
{
    //ctor
}

gameState_1::~gameState_1()
{
    //dtor
}

int gameState_1::greaterRandom1(int max)
{
    srand(time(0));
    int randomNumber = rand();
    float random = (randomNumber % max)+1;
    int myRandom = random;
    return myRandom;
}

void gameState_1::wait(float f)
{
    sf::Clock clock;
    sf::Time time;

    while(true)
    {
        time = clock.getElapsedTime();
        if(time.asSeconds() > f)
        {
            break;
        }
    }
}



int gameState_1::gameState1(sf::RenderWindow &window)
{
    ///variables

    system("CLS");

    srand(time(NULL));
    //sf::Clock matchTime;

    sf::Clock player1Clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock player2Clock;

    sf::Clock gameOverWaitingTime;

    //sf::Clock shieldClock1;
    float shieldClock1 = 30;

    //sf::Clock speedUpClock1;
    float speedUpClock1 = 45;

    //sf::Clock invisibilityClock1;
    float invisibilityClock1 = 30;

    //sf::Clock shieldClock2;
    float shieldClock2 = 30;
    //sf::Clock speedUpClock2;
    float speedUpClock2 = 45;

    //sf::Clock invisibilityClock2;
    float invisibilityClock2 = 30;

    //sf::Clock mechaSpawnClock;
    float mechaSpawnClock = 2;

    //sf::Clock droneSpawnClock;
    float droneSpawnClock = 10;

    float droneMineDropingTime = 3.5;

    float invisible = 45;

    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    float totalMatchTime = 301;
    float minute,second;


    bool upDown = true;
    bool leftRight = false;

    bool fired = false;

    bool isPause = false;
    bool isGameOver = false;
    bool matchIsDraw = false;
    //bool startingCountdown = true;

    bool changeDirection=false;


    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(),"Base Map",sf::Style::Fullscreen);
    window.setFramerateLimit(60);



    ///View
    //sf::View view1(sf::FloatRect(200,200,300,200));
    //view1.setSize(sf::Vector2f(window.getSize().x,window.getSize().y));
    //view1.setCenter(sf::Vector2f(view1.getSize().x/2,view1.getSize().y/2));
    //window.setView(view1);



    ///String Input////////////////////////////////////////////
    string playerInput;
    sf::Text playerText;




    sf::Texture gameBackground;
    if(!gameBackground.loadFromFile("images/frame.png"))
    {
        printf("Error imaages/frame.png");
        return 0;
    }
    sf::Sprite gameBackgroundSprite;
    gameBackgroundSprite.setTexture(gameBackground);
    gameBackgroundSprite.setTextureRect(sf::IntRect(0,0,1920,1080));
    gameBackgroundSprite.setPosition(sf::Vector2f(0.f,0.f));


    ///Load a sprite player
    ///icon
    sf::Texture texturePlayer2;
    if(!texturePlayer2.loadFromFile("images/tankicon2.png"))
    {
        printf("Error imaages/tankicon21.png");
        return 0;
    }
    sf::Sprite iconSprite2;
    iconSprite2.setTexture(texturePlayer2);

    sf::Texture texturePlayer1;
    if(!texturePlayer1.loadFromFile("images/tankicon1.png"))
    {
        printf("Error imaages/tankicon21.png");
        return 0;
    }
    sf::Sprite iconSprite1;
    iconSprite1.setTexture(texturePlayer1);

    //player texture
    sf::Texture texturePlayer21;
    if(!texturePlayer21.loadFromFile("images/redtank1.png"))
    {
        printf("Error imaages/redtank1.png");
        return 0;
    }
    sf::Texture texturePlayer22;
    if(!texturePlayer22.loadFromFile("images/redtank2.png"))
    {
        printf("Error imaages/redtank2.png");
        return 0;
    }
    sf::Texture texturePlayer23;
    if(!texturePlayer23.loadFromFile("images/redtank3.png"))
    {
        printf("Error imaages/redtank3.png");
        return 0;
    }
    ///have to change something
    sf::Texture texturePlayer11;
    if(!texturePlayer11.loadFromFile("images/bluetank1.png"))
    {
        printf("Error imaages/bluetank1.png");
        return 0;
    }
    sf::Texture texturePlayer12;
    if(!texturePlayer12.loadFromFile("images/bluetank2.png"))
    {
        printf("Error imaages/bluetank2.png");
        return 0;
    }
    sf::Texture texturePlayer13;
    if(!texturePlayer13.loadFromFile("images/bluetank3.png"))
    {
        printf("Error imaages/bluetank2.png");
        return 0;
    }

    ///enemy texture
    sf::Texture textureEnemyMecha;
    if(!textureEnemyMecha.loadFromFile("images/enemy.png"))
    {
        printf("Error imaages/enemy.png");
        return 0;
    }

    sf::Texture textureEnemyDrone;
    if(!textureEnemyDrone.loadFromFile("images/drone.png"))
    {
        printf("Error imaages/drone.png");
        return 0;
    }


    ///pick ups textures///

    ///powerup
    sf::Texture texturePickup;
    if(!texturePickup.loadFromFile("images/pickup.png"))
    {
        printf("Error images/pickup.png");
        return 0;
    }

    ///shield effect
    sf::Texture textureShieldEffect;
    if(!textureShieldEffect.loadFromFile("images/shieldeffect.png"))
    {
        printf("Error images/shieldeffect.png");
        return 0;
    }
    sf::Sprite shieldEffectSprite;
    shieldEffectSprite.setTexture(textureShieldEffect);
    shieldEffectSprite.setTextureRect(sf::IntRect(0,0,40,40));

    ///Fire projectile texture
    sf::Texture textureFire;
    if(!textureFire.loadFromFile("images/projectile.png"))
    {
        printf("Error images/projectile.png");
        return 0;
    }
    sf::Texture flashTexture;
    if(!flashTexture.loadFromFile("images/flash.png"))
    {
        printf("Error images/flash.png");
        return 0;
    }
    sf::Sprite flashSprite;
    flashSprite.setTexture(flashTexture);

    ///Texture blood
    sf::Texture textureBlood;
    if(!textureBlood.loadFromFile("images/explosion.png"))
    {
        printf("Error images/explosion.png");
        return 0;
    }


    ///Obstacle texture
    sf::Texture textureObstacle;
    if(!textureObstacle.loadFromFile("images/map.png"))
    {
        printf("Error images/map.png");
        return 0;
    }

    sf::Texture textureTransparent;
    if(!textureTransparent.loadFromFile("images/transparent.png"))
    {
        printf("Error images/transparent.png");
        return 0;
    }
    sf::Sprite transparentSprite;
    transparentSprite.setTexture(textureTransparent);
    transparentSprite.setTextureRect(sf::IntRect(0,0,1920,1080));
    transparentSprite.setPosition(sf::Vector2f(0.f,0.f));




    ///sounds for shooting fire collision Musics etc etc
    sf::Music music;
    if(!music.openFromFile("sounds/music.ogg"))
    {
        cout<<"Error music.ogg\n";
        return 0;
    }
    //music.play();
    //music.setLoop(true);

    sf::SoundBuffer bufferShot;
    if(!bufferShot.loadFromFile("sounds/shot.ogg"))
    {
        cout<<"Sound error shot.ogg\n";
        return 0;
    }
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);

    sf::SoundBuffer bufferCollision;
    if(!bufferCollision.loadFromFile("sounds/collision.ogg"))
    {
        cout<<"Sound error collision.ogg\n";
        return 0;
    }
    sf::Sound soundCollision;
    soundCollision.setBuffer(bufferCollision);

    sf::SoundBuffer bufferPlayerDamaged;
    if(!bufferPlayerDamaged.loadFromFile("sounds/playerhit.ogg"))
    {
        cout<<"Sound error playerhit.ogg\n";
        return 0;
    }
    sf::Sound soundPlayerDamaged;
    soundPlayerDamaged.setBuffer(bufferPlayerDamaged);

    sf::SoundBuffer bufferCoin;
    if(!bufferCoin.loadFromFile("sounds/coinpickup.wav"))
    {
        cout<<"Sound error coinpickup.wav\n";
        return 0;
    }
    sf::Sound soundCoin;
    soundCoin.setBuffer(bufferCoin);


    sf::SoundBuffer windowChangeBuffer;
    if(!windowChangeBuffer.loadFromFile("sounds/door.ogg"))
    {
        cout<<"Sound error door.ogg\n";
        return 0;
    }
    sf::Sound windowChangeSound;
    windowChangeSound.setBuffer(windowChangeBuffer);





    sf::Texture button;
    if(!button.loadFromFile("images/pausebutton.png"))
    {
        printf("Error pausebutton.png\n");
        return 0;
    }
    sf::Sprite resume;
    sf::Sprite endMatch;
    resume.setTexture(button);
    endMatch.setTexture(button);


    sf::SoundBuffer upDownSoundBuffer;
    if(!upDownSoundBuffer.loadFromFile("sounds/blink.ogg"))
    {
        cout<<"Sound error blink.ogg\n";
        return 0;
    }
    sf::Sound upDownSound;
    upDownSound.setBuffer(upDownSoundBuffer);


    sf::SoundBuffer windowChangeBuffer1;
    if(!windowChangeBuffer1.loadFromFile("sounds/button.ogg"))
    {
        cout<<"Sound error button.ogg\n";
        return 0;
    }
    sf::Sound windowChangeSound1;
    windowChangeSound1.setBuffer(windowChangeBuffer1);



    ///Variables///////////
    int selectedItemIndex = 0;
    int clickedItem = 0;






    ///Text vector array////////////////////////////////////////////////////////////
    vector<textDisplay>::const_iterator iter8;
    vector<textDisplay> textArray;
    ///font
    sf::Font font;
    if(!font.loadFromFile("fonts/pixel2.ttf"))
    {
        cout<<"FONT ERROR: \n";
        return 0;
    }

    sf::Font font2;
    if(!font2.loadFromFile("fonts/pixel2.ttf"))
    {
        cout<<"FONT ERROR: \n";
        return 0;
    }


    ///class object//////////////////////////////////////////////////////
    class player Player1;
    Player1.rect.setPosition(1480,100);
    Player1.isPlayer1 = true;
    Player1.isPlayer2 = false;
    Player1.isLevel1 = true;
    Player1.sprite.setTexture(texturePlayer11);
    Player1.direction = 2;

    class player Player2;
    Player2.isPlayer1 = false;
    Player2.isPlayer2 = true;
    Player2.isLevel1 = true;
    Player2.rect.setPosition(400,1020);
    Player2.sprite.setTexture(texturePlayer21);
    Player2.direction =1;

    sf::Color winnerTitle;


    ///projectile vector array///////////////////////////////////////////////////////
    vector<projectile>::const_iterator iter;
    vector<projectile>projectileArray;
    ///projectile object
    class projectile projectile1;
    projectile1.sprite.setTexture(textureFire);



    ///enemy vector array//////////////////////////////////////////////////
    vector<enemy>::const_iterator iter4;
    vector<enemy> enemyArray;
    ///Enemy object
    class enemy enemy1;

    enemy1.text.setFont(font);
    enemy1.text.setCharacterSize(17);
    enemy1.text.setColor(sf::Color::Red);



    ///Blood vector array//////////////////////////////////////////////////
    vector<enemy>::const_iterator iter20;
    vector<enemy> bloodArray;
    ///Blood object///////////
    class enemy blood1;
    blood1.isBlood = true;
    blood1.sprite.setTexture(textureBlood);
    blood1.sprite.setTextureRect(sf::IntRect(0,0,40,40));




    ///Points showing/////////////////////////////////////////
    sf::Text text("Points: ",font,25);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(0,0);

    ///Player HP text
    sf::Text textHp("HP: ",font,25);
    textHp.setFillColor(sf::Color::Green);
    textHp.setPosition(0,0);




    ///Games Text
    sf::Text countdownText("3",font,90);
    countdownText.setFillColor(sf::Color::White);
    //countdownText.setOrigin(45,45);
    countdownText.setPosition((window.getSize().x/2) - 25,window.getSize().y/2);



    ///Text Display object//////////////////////////////////////////////
    class textDisplay textDisplay1;
    textDisplay1.text.setFont(font);



    ///Wall vector array//////////////////////////////////
    vector<wall>::const_iterator iter15;
    vector<wall> wallArray;
    class wall wall1;


    ///PickUp Array/////////////////////////////////////////////////////
    vector<pickUp>::const_iterator iter11;
    vector<pickUp> pickupArray;
    ///pickup class object coins
    class pickUp pickup1;
    pickup1.isCoin = true;
    pickup1.sprite.setTexture(texturePickup);
    pickup1.text.setFont(font);
    pickup1.text.setCharacterSize(18);
    pickup1.text.setColor(sf::Color::Green);







///Map/////////////////////
    int mapArray[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,3,5,5,5,5,5,5,5,1,5,5,5,5,5,5,2,5,5,1,5,5,5,1,5,5,5,1,5,5,5,1,5,5,5,3,3,1,
        1,3,3,2,5,2,2,2,5,2,2,5,2,5,2,5,1,5,5,5,5,5,5,5,5,2,5,5,5,2,5,2,2,5,5,3,3,1,
        1,3,3,3,5,5,1,5,5,5,2,5,1,2,2,5,5,5,1,5,5,5,1,5,5,2,5,2,1,2,5,5,2,5,1,3,3,1,
        1,3,3,3,3,2,2,5,1,5,5,5,2,5,5,5,5,2,2,2,5,2,2,2,5,5,5,5,2,5,5,1,2,5,5,3,3,1,
        1,3,3,3,3,3,2,5,5,5,1,5,5,5,1,5,2,2,5,2,1,2,5,1,5,5,1,5,2,2,5,5,5,5,3,3,3,1,
        1,3,3,3,3,3,2,5,2,5,2,5,2,5,5,5,5,5,5,2,5,2,5,2,5,5,5,5,5,2,2,3,3,3,3,2,4,1,
        1,3,3,2,3,3,2,2,2,2,2,2,2,2,5,1,5,2,5,5,5,5,5,5,5,1,2,1,5,5,3,3,3,3,2,4,4,1,
        1,3,2,2,3,3,3,3,2,1,1,1,1,2,3,3,3,1,5,5,1,5,2,2,5,2,5,2,5,3,3,3,4,4,4,4,2,1,
        1,2,2,3,3,3,1,3,2,1,5,5,1,2,3,3,3,1,1,1,1,5,5,5,5,5,5,5,5,3,4,4,4,4,2,2,2,1,
        1,2,3,3,3,3,2,5,5,5,5,5,5,2,5,1,5,5,5,5,2,5,5,2,4,0,0,0,0,4,4,3,3,3,3,3,3,1,
        1,3,3,3,3,2,1,2,5,2,1,2,5,5,5,5,5,5,2,5,5,5,2,4,4,0,0,0,0,4,3,3,3,3,3,3,3,1,
        1,3,3,3,2,2,5,5,5,5,2,5,5,2,2,2,4,4,4,4,4,4,4,4,2,5,5,5,5,2,2,5,5,2,1,3,3,1,
        1,3,3,1,2,5,5,2,2,5,5,5,5,2,4,4,4,4,4,4,4,4,2,2,2,5,5,2,5,5,5,5,2,2,3,3,3,1,
        1,3,3,3,3,3,3,3,4,0,0,0,0,4,4,2,5,5,5,2,5,5,5,5,5,5,2,1,2,5,2,1,2,3,3,3,3,1,
        1,3,3,3,3,3,3,4,4,0,0,0,0,4,2,5,5,2,5,5,5,5,1,5,2,5,5,5,5,5,5,2,3,3,3,3,2,1,
        1,2,2,2,4,4,4,4,3,5,5,5,5,5,5,5,5,1,1,1,1,3,3,3,2,1,5,5,1,2,3,1,3,3,3,2,2,1,
        1,2,4,4,4,4,3,3,3,5,2,5,2,5,2,2,5,1,5,5,1,3,3,3,2,1,1,1,1,2,3,3,3,3,2,2,3,1,
        1,4,4,2,3,3,3,3,5,5,1,2,1,5,5,5,5,5,5,5,2,5,1,5,2,2,2,2,2,2,2,2,3,3,2,3,3,1,
        1,4,2,3,3,3,3,2,2,5,5,5,5,5,2,5,2,5,2,5,5,5,5,5,5,2,5,2,5,2,5,2,3,3,3,3,3,1,
        1,3,3,3,5,5,5,5,2,2,5,1,5,5,1,5,2,1,2,5,2,2,5,1,5,5,5,1,5,5,5,2,3,3,3,3,3,1,
        1,3,3,5,5,2,1,5,5,2,5,5,5,5,2,2,2,5,2,2,2,5,5,5,5,2,5,5,5,1,5,2,2,3,3,3,3,1,
        1,3,3,1,5,2,5,5,2,1,2,5,2,5,5,1,5,5,5,1,5,5,5,2,2,1,5,2,5,5,5,1,5,5,3,3,3,1,
        1,3,3,5,5,2,2,5,2,5,5,5,2,5,5,5,5,5,5,5,5,1,5,2,5,2,5,2,2,5,2,2,2,5,2,3,3,1,
        1,3,3,5,5,5,1,5,5,5,1,5,5,5,1,5,5,5,1,5,5,2,5,5,5,5,5,5,1,5,5,5,5,5,5,5,3,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100
    };



    vector<float>x,y;
    x.clear();
    y.clear();

    wall1.sprite.setTexture(textureObstacle);
    int i=0;
    while(mapArray[i]!=100)
    {
        if(mapArray[i]==0)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = false;
            wall1.destructable = false;
            wall1.isJungle = false;
            wall1.isWater = false;
            wall1.isProjectilePassable = true;
            wallArray.push_back(wall1);
        }
        if(mapArray[i]==1)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = true;
            wall1.destructable = false;
            wall1.isJungle = false;
            wall1.isWater = false;
            wall1.isProjectilePassable = false;
            wallArray.push_back(wall1);
        }
        if(mapArray[i]==2)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = true;
            wall1.destructable = true;
            wall1.isJungle = false;
            wall1.isWater = false;
            wall1.isProjectilePassable = false;
            wallArray.push_back(wall1);
        }
        if(mapArray[i]==3)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = false;
            wall1.destructable = false;
            wall1.isJungle = true;
            wall1.isWater = false;
            x.push_back(wall1.rect.getPosition().x);
            y.push_back(wall1.rect.getPosition().y);
            wall1.isProjectilePassable = true;

            wallArray.push_back(wall1);
        }
        if(mapArray[i]==4)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = true;
            wall1.destructable = false;
            wall1.isWater = true;
            wall1.isJungle = false;
            wall1.isProjectilePassable = true;
            wallArray.push_back(wall1);
        }
        if(mapArray[i]==5)
        {
            wall1.sprite.setTextureRect(sf::IntRect(40 * mapArray[i],0,40,40));
            wall1.rect.setPosition(400/2 + (i%38)*40,(i/38)*40 + 60);
            wall1.isColliedable = false;
            wall1.destructable = false;
            wall1.isJungle = false;
            wall1.isWater = false;
            wall1.isProjectilePassable = true;
            wallArray.push_back(wall1);
        }
        i++;
    }


    sf::Music countdownSound;
    if(!countdownSound.openFromFile("sounds/countdown.ogg"))
    {
        cout<<"Error countdown.ogg\n";
        return 0;
    }
    countdownSound.play();

    counter2 = 0;
    ///Starting countdown
    while(window.isOpen())
    {
        window.clear();

        if((3-counter2)==0)
        {
            countdownText.setString("FIGHT!");
            countdownText.setPosition((window.getSize().x/2) - 210,window.getSize().y/2);
        }
        else
        {
            countdownText.setString(to_string(3-counter2));
        }
        countdownText.setCharacterSize(90);
        sf::Color w(238,238,238);
        countdownText.setFillColor(w);
        counter=0;
        for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if(wallArray[counter].isJungle == false)
            {
                wallArray[counter].update(); ///update wall
                window.draw(wallArray[counter].sprite);
            }
            counter++;
        }
        window.draw(gameBackgroundSprite);
        window.draw(transparentSprite);
        window.draw(countdownText);
        window.display();
        wait(1);
        counter2++;
        if(counter2 > 3)
        {
            countdownText.setCharacterSize(70);
            break;
        }
    }


    //matchTime.restart();

    string winnerPlayerTitle="";

    ///start game loop//////////////////////////////////////////////////////////////////////////////////////
    while (window.isOpen())
    {


        sf::Time elapsedTimePlayer1 = player1Clock.getElapsedTime();
        sf::Time elapsedTimePlayer2 = player2Clock.getElapsedTime();

        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();

        sf::Time elapsedGameOverWaitingTime = gameOverWaitingTime.getElapsedTime();


        if( isPause == false)
        {
            ///Clock
            //sf::Time elapsedTimeOfMatch = matchTime.getElapsedTime();
            totalMatchTime -= float(1.f/60.f);

            droneMineDropingTime -= float(1.f/60.f);

            //sf::Time elapsedTimeSpeedUp1 = speedUpClock1.getElapsedTime();
            speedUpClock1 -= float(1.f/60.f);

            // sf::Time elapsedTimeShield1 = shieldClock1.getElapsedTime();
            shieldClock1 -= float(1.f/60.f);

            // sf::Time elapsedTimeInvisibility1 = invisibilityClock1.getElapsedTime();
            invisibilityClock1 -= float(1.f/60.f);

            //sf::Time elapsedTimeSpeedUp2 = speedUpClock2.getElapsedTime();
            speedUpClock2 -= float(1.f/60.f);

            //sf::Time elapsedTimeShield2 = shieldClock2.getElapsedTime();
            shieldClock2 -= float(1.f/60.f);

            //sf::Time elapsedTimeInvisibility2 = invisibilityClock2.getElapsedTime();
            invisibilityClock2 -= float(1.f/60.f);

            //sf::Time elapsedTimeMechaSpawn = mechaSpawnClock.getElapsedTime();
            mechaSpawnClock -= float(1.f/60.f);

            //sf::Time elapsedTimedroneSpawn = droneSpawnClock.getElapsedTime();
            droneSpawnClock -= float(1.f/60.f);
        }

        window.clear(sf::Color::Black);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || isPause == true) && isGameOver == false)
            {
                //windowChangeSound.play();
                //wait(0.25);

                isPause = true;
                if(isPause == true)
                {
                    if (event.type == sf::Event::Closed)
                    {
                        isPause = false;
                        window.close();
                    }
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
                            break;

                        case sf::Keyboard::Down:
                            if (selectedItemIndex + 1 < 2)
                            {
                                upDownSound.play();
                                selectedItemIndex++;
                            }
                            break;

                        case sf::Keyboard::Return:
                            switch (selectedItemIndex)
                            {
                            case 0:
                            {
                                clickedItem = 1;
                                break;
                            }
                            case 1:
                                clickedItem = 2;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                }
            }
            if(isGameOver == true)
            {

            }
        }
        ///Clearing Windows





        if(isGameOver == false)
        {
            gameOverWaitingTime.restart();
            if(totalMatchTime <= 0)
            {
                ///game over
                if(Player1.points > Player2.points)
                {
                    ///Player 1 win
                    window.setFramerateLimit(7);
                    winnerPlayerTitle = "PLAYER 1 WINS!";
                    winnerTitle = sf::Color(0,128,255);
                }
                if(Player1.points < Player2.points)
                {
                    ///Player 2 win
                    window.setFramerateLimit(7);
                    winnerTitle = sf::Color(255,12,0);
                    winnerPlayerTitle = "PLAYER 2 WINS!";

                }
                else
                {
                    ///match draw
                    matchIsDraw = true;
                    window.setFramerateLimit(7);
                    winnerTitle = sf::Color(238,238,238);
                    winnerPlayerTitle = "MATCH DRAW!x";
                }
                isGameOver = true;
                isPause = true;
                gameOverWaitingTime.restart();

            }

            if(Player1.points <= -20)
            {
                ///Player 1 win
                window.setFramerateLimit(7);
                winnerPlayerTitle = "PLAYER 1 WINS!";
                winnerTitle = sf::Color(0,128,255);
                isGameOver = true;
                isPause = true;
                gameOverWaitingTime.restart();
            }
            if(Player2.points <= -20)
            {
                ///Player 2 win
                window.setFramerateLimit(7);
                winnerTitle = sf::Color(255,12,0);
                winnerPlayerTitle = "PLAYER 2 WINS!";
                isGameOver = true;
                isPause = true;
                gameOverWaitingTime.restart();
            }

            if(Player1.hp <=0)
            {
                ///player 2 win
                winnerTitle = sf::Color(255,12,0);
                winnerPlayerTitle = "PLAYER 2 WINS!";

                window.setFramerateLimit(7);

                blood1.rect.setPosition(Player1.rect.getPosition());
                blood1.isBlood = true;
                bloodArray.push_back(blood1);
                pickupArray[counter].destroy = true;

                isGameOver = true;
                isPause = true;
                gameOverWaitingTime.restart();


            }
            if(Player2.hp <= 0)
            {
                ///Player 1 win
                winnerTitle = sf::Color(0,128,255);
                winnerPlayerTitle = "PLAYER 1 WINS!";

                window.setFramerateLimit(7);

                blood1.rect.setPosition(Player2.rect.getPosition());
                blood1.isBlood = true;
                bloodArray.push_back(blood1);
                pickupArray[counter].destroy = true;
                isGameOver = true;
                isPause = true;
                gameOverWaitingTime.restart();

            }
        }




        ///player collied with wall////////////////////////////////////////////
        counter=0;
        for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
RAFI:
            if(Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()) && wallArray[counter].isColliedable == true)
            {
                sf::Vector2f prevPos = Player1.rect.getPosition();
                ///hit wall
                if(Player1.direction == 1) //up
                {
                    Player1.canMoveUp = false;
                    Player1.rect.move(0,1);
                    goto RAFI;

                }
                else if(Player1.direction == 2) //down
                {
                    Player1.canMoveDown = false;
                    Player1.rect.move(0,-1);
                    goto RAFI;

                }
                else if(Player1.direction == 3) //left
                {
                    Player1.canMoveLeft = false;
                    Player1.rect.move(1,0);
                    goto RAFI;
                }
                else if(Player1.direction == 4) // Right
                {
                    Player1.canMoveRight = false;
                    Player1.rect.move(-1,0);
                    goto RAFI;
                }
                else
                {
                    ///Do nothing
                }
            }
MAHMUD:
            if(Player2.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()) && wallArray[counter].isColliedable == true)
            {

                ///hit wall
                if(Player2.direction == 1) //up
                {
                    Player2.canMoveUp = false;
                    Player2.rect.move(0,1);
                    goto MAHMUD;
                }
                else if(Player2.direction == 2) //down
                {
                    Player2.canMoveDown = false;
                    Player2.rect.move(0,-1);
                    goto MAHMUD;
                }
                else if(Player2.direction == 3) //left
                {
                    Player2.canMoveLeft = false;
                    Player2.rect.move(1,0);
                    goto MAHMUD;
                }
                else if(Player2.direction == 4) // Right
                {
                    Player2.canMoveRight = false;
                    Player2.rect.move(-1,0);
                    goto MAHMUD;
                }
                else
                {
                    ///Do nothing
                }
            }
            counter++;
        }





        ///player collied with pickup item///////////////////////////////////////////////////////////////////////////////////
        counter=0;
        for(iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if(Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if(pickupArray[counter].isCoin == true)
                {
                    soundCoin.play();
                    Player1.points += pickupArray[counter].coinValue;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isHpSheild == true)
                {
                    Player1.hp = Player1.maxHp;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isMineBomb == true)
                {
                    if(Player1.isShield == false)
                    {
                        Player1.hp -= 1;
                        Player1.points -= 1;
                    }
                    ///Creat mine blast
                    blood1.rect.setPosition(pickupArray[counter].rect.getPosition());
                    blood1.isBlood = true;
                    bloodArray.push_back(blood1);
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isSpeedUp == true && Player1.isInvisibility == false && Player1.isShield == false)
                {
                    //speedUpClock1.restart();
                    speedUpClock1 = 45;
                    Player1.movementSpeed = Player1.speedUpSpeed;
                    Player1.isSpeedUp = true;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isShield == true && Player1.isInvisibility == false && Player1.isSpeedUp == false)
                {
                    //shieldClock1.restart();
                    shieldClock1 = 30;
                    Player1.isShield =true ;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isInvisibility == true && Player1.isSpeedUp == false && Player1.isShield == false)
                {
                    //invisibilityClock1.restart();
                    invisibilityClock1 = 30;
                    Player1.isInvisibility = true;
                    pickupArray[counter].destroy = true;
                }

            }
            if(Player2.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
            {
                if(pickupArray[counter].isCoin == true)
                {
                    soundCoin.play();
                    Player2.points += pickupArray[counter].coinValue;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isHpSheild == true)
                {
                    Player2.hp = Player2.maxHp;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isMineBomb == true)
                {
                    if(Player2.isShield == false)
                    {
                        Player2.hp -= 1;
                        Player2.points -= 1;
                    }
                    ///Creat mine blast
                    blood1.rect.setPosition(pickupArray[counter].rect.getPosition());
                    blood1.isBlood = true;
                    bloodArray.push_back(blood1);
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isSpeedUp == true && Player2.isInvisibility == false && Player2.isShield == false)
                {
                    //speedUpClock2.restart();
                    speedUpClock2 = 45;
                    Player2.movementSpeed = Player2.speedUpSpeed;
                    Player2.isSpeedUp = true;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isShield == true && Player2.isInvisibility == false && Player2.isSpeedUp == false)
                {
                    //shieldClock2.restart();
                    shieldClock2 = 30;
                    Player2.isShield =true ;
                    pickupArray[counter].destroy = true;
                }
                else if(pickupArray[counter].isInvisibility == true && Player2.isSpeedUp == false && Player2.isShield == false)
                {
                    //invisibilityClock2.restart();
                    invisibilityClock2 = 30;
                    Player2.isInvisibility = true;
                    pickupArray[counter].destroy = true;
                }

            }
            counter++;
        }




        ///power up time limit settings///////////////////////////////////
        //Player 1
        if(speedUpClock1 <= 0)
        {
            //speedUpClock1.restart();
            speedUpClock1 = 45;
            if(Player1.isSpeedUp == true)
            {
                Player1.isSpeedUp = false;
                Player1.movementSpeed = Player1.normalSpeed;
            }
        }
        if(shieldClock1 <= 0)
        {
            //shieldClock1.restart();
            shieldClock1 = 30;
            if(Player1.isShield == true)
            {
                Player1.isShield = false;
            }
        }
        if(invisibilityClock1 <= 0)
        {
            //invisibilityClock1.restart();
            invisibilityClock1 = 30;
            if(Player1.isInvisibility == true)
            {
                Player1.isInvisibility = false;
            }
        }
        //Player 2
        if(speedUpClock2 <= 0)
        {
            //speedUpClock2.restart();
            speedUpClock2 = 45;
            if(Player2.isSpeedUp == true)
            {
                Player2.isSpeedUp = false;
                Player2.movementSpeed = Player2.normalSpeed;
            }
        }
        if(shieldClock2 <=0 )
        {
            //shieldClock2.restart();
            shieldClock2 = 30;
            if(Player2.isShield == true)
            {
                Player2.isShield = false;
            }
        }
        if(invisibilityClock2 <= 0)
        {
            //invisibilityClock2.restart();
            invisibilityClock2 = 30;
            if(Player2.isInvisibility == true)
            {
                Player2.isInvisibility = false;
            }
        }




        if(isPause == false)
        {
            ///Enemy collied with player///////////////////////////////////////////////////////////////////////////////////////
            if(elapsed2.asSeconds() >= 1)
            {
                clock2 .restart();
                ///Enemy collide with player 1 and player 1 takes damage
                counter=0;
                for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                {
                    if(Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
                    {
                        soundPlayerDamaged.play();
                        textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                        textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2,
                                                      Player1.rect.getPosition().y - Player1.rect.getSize().y/2);
                        textArray.push_back(textDisplay1);
                        if(enemyArray[counter].isMecha == true)
                        {
                            Player1.hp -= enemyArray[counter].attackDamage;
                            Player1.points -= 1;
                            enemyArray[counter].changeDirection = true;
                            enemyArray[counter].aggresive=true;
                        }

                        if(enemyArray[counter].isDrone == true && Player1.isInvisibility == false)
                        {
                            pickup1.isCoin = false;
                            pickup1.isHpSheild = false;
                            pickup1.isShield = false;
                            pickup1.isSpeedUp = false;
                            pickup1.isInvisibility = false;
                            pickup1.isMineBomb = true;

                            pickup1.sprite.setTexture(texturePickup);
                            pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                            pickupArray.push_back(pickup1);
                        }

                    }
                    counter++;
                }
            }
            if(elapsed2.asSeconds() >= 1)
            {
                clock2 .restart();
                ///Enemy collide with player 2 and player 2 takes damage
                counter=0;
                for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
                {
                    if(Player2.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()) )
                    {
                        soundPlayerDamaged.play();
                        textDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                        textDisplay1.text.setPosition(Player2.rect.getPosition().x + Player2.rect.getSize().x/2,
                                                      Player2.rect.getPosition().y - Player2.rect.getSize().y/2);
                        textArray.push_back(textDisplay1);

                        if(enemyArray[counter].isMecha == true)
                        {
                            enemyArray[counter].changeDirection = true;
                            enemyArray[counter].aggresive=true;
                            Player2.points -= 1;
                            Player2.hp -= enemyArray[counter].attackDamage;
                        }

                        if(enemyArray[counter].isDrone == true && Player2.isInvisibility == false)
                        {
                            pickup1.isCoin = false;
                            pickup1.isHpSheild = false;
                            pickup1.isShield = false;
                            pickup1.isSpeedUp = false;
                            pickup1.isInvisibility = false;
                            pickup1.isMineBomb = true;

                            pickup1.sprite.setTexture(texturePickup);
                            pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
                            pickupArray.push_back(pickup1);
                        }
                    }
                    counter++;
                }
            }
        }



        ///Projectile collied with walls/////////////////////////////////////////////////////////////////////
        counter=0;
        for(iter=projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2=0;
            for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
            {
                if(projectileArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds())
                        && wallArray[counter2].isProjectilePassable == false)
                {
                    if(wallArray[counter2].destructable == true)
                    {
                        wallArray[counter2].hp -= Player1.attackDamage;

                        if(wallArray[counter2].hp <=0)
                        {
                            wallArray[counter2].destroy = true;
                        }
                    }
                    projectileArray[counter].destroy = true;
                }
                counter2++;
            }
            counter++;
        }




        ///Projectile collied with Player/////////////////////////////////////////////////////////////////////
        counter=0;
        for(iter=projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if(projectileArray[counter].rect.getGlobalBounds().intersects(Player2.rect.getGlobalBounds()) && projectileArray[counter].isPlayer1 == true)
            {
                Player1.points += 2;
                if(Player2.isShield == false)
                {
                    Player2.hp -= Player1.attackDamage;
                    Player2.points -= 2;
                }
                projectileArray[counter].destroy = true;

            }
            if(projectileArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()) && projectileArray[counter].isPlayer2 == true)
            {
                Player2.points+=2;
                if(Player1.isShield == false)
                {
                    Player1.hp -= Player2.attackDamage;
                    Player1.points -= 2;
                }
                projectileArray[counter].destroy = true;
            }
            counter++;
        }


        ///Update player1 level//////////////////////////////////////////////////////////////////////////////////////////////////
        if(Player1.points >0 && Player1.points <5 && Player1.isLevel1 == false)
        {
            Player1.isLevel1 = true;
            Player1.isLevel2 = false;
            Player1.isLevel3 = false;
            Player1.movementSpeed = 2;
            Player1.hp = 5;
            Player1.maxHp = 5;
            Player1.attackDamage = 1;
            Player1.sprite.setTexture(texturePlayer11);
        }
        if(Player1.points >=5 && Player1.points <10 && Player1.isLevel2 == false)
        {
            Player1.isLevel1 = false;
            Player1.isLevel2 = true;
            Player1.isLevel3 = false;

            Player1.movementSpeed = 3;
            Player1.hp = 10;
            Player1.maxHp = 10;
            Player1.attackDamage = 2;
            Player1.sprite.setTexture(texturePlayer12);
        }
        if(Player1.points >=10 && Player1.points <=15 && Player1.isLevel3 == false)
        {
            Player1.isLevel1 = false;
            Player1.isLevel2 = false;
            Player1.isLevel3 = true;

            Player1.movementSpeed = 4;
            Player1.hp = 15;
            Player1.maxHp = 15;
            Player1.attackDamage = 3;
            Player1.sprite.setTexture(texturePlayer13);

        }

        ///Update player2 level////////////////////////////////////////////////////////////////////////////////////////////////////
        if(Player2.points >0 && Player2.points <5 && Player2.isLevel1 == false)
        {
            Player2.isLevel1 = true;
            Player2.isLevel2 = false;
            Player2.isLevel3 = false;

            Player2.movementSpeed = 2;
            Player2.hp = 5;
            Player2.maxHp = 5;
            Player2.attackDamage = 1;
            Player2.sprite.setTexture(texturePlayer21);

        }
        if(Player2.points >=5 && Player2.points <10 && Player2.isLevel2 == false)
        {
            Player2.isLevel1 = false;
            Player2.isLevel2 = true;
            Player2.isLevel3 = false;

            Player2.movementSpeed = 3;
            Player2.hp = 10;
            Player2.maxHp = 10;
            Player2.attackDamage = 2;
            Player2.sprite.setTexture(texturePlayer22);
        }
        if(Player2.points >=10 && Player2.points <=15 && Player2.isLevel3 == false)
        {
            Player2.isLevel1 = false;
            Player2.isLevel2 = false;
            Player2.isLevel3 = true;

            Player2.movementSpeed = 4;
            Player2.hp = 15;
            Player2.maxHp = 15;
            Player2.attackDamage = 3;
            Player2.sprite.setTexture(texturePlayer23);
        }





        ///Enemy collied with walls
        counter=0;
        for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            counter2=0;
            for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
            {
                if(enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()) &&
                        wallArray[counter2].isColliedable == true && enemyArray[counter].isDrone == false)
                {
                    //enemyArray[counter].aggresive = false;
                    ///hit wall
                    //cout<<"moving\n";
                    if(enemyArray[counter].direction == 1) //up
                    {
                        enemyArray[counter].canMoveUp = false;
                        enemyArray[counter].rect.move(0,1);
                        upDown = false;
                        leftRight = true;
                    }
                    else if(enemyArray[counter].direction == 2) //down
                    {
                        enemyArray[counter].canMoveDown = false;
                        enemyArray[counter].rect.move(0,-1);
                        upDown = false;
                        leftRight = true;
                    }
                    else if(enemyArray[counter].direction == 3) //left
                    {
                        enemyArray[counter].canMoveLeft = false;
                        enemyArray[counter].rect.move(1,0);

                        leftRight = false;
                        upDown = true;
                    }
                    else if(enemyArray[counter].direction == 4) // Right
                    {
                        enemyArray[counter].canMoveRight = false;
                        enemyArray[counter].rect.move(-1,0);
                        enemyArray[counter].direction = 2;
                        leftRight = false;
                        upDown = true;
                    }
                    //enemyArray[counter].aggresive = false;
                    enemyArray[counter].changeDirection = true;

                }
                if(enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()) &&
                        wallArray[counter2].isColliedable == false && enemyArray[counter].isDrone == true)
                {
                    if(droneMineDropingTime <0)
                    {
                        droneMineDropingTime = 2;
                        pickup1.isCoin = false;
                        pickup1.isHpSheild = false;
                        pickup1.isShield = false;
                        pickup1.isSpeedUp = false;
                        pickup1.isInvisibility = false;
                        pickup1.isMineBomb = true;

                        pickup1.sprite.setTexture(texturePickup);
                        pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                        pickupArray.push_back(pickup1);
                    }
                }
                else
                {
                    ///Do nothing
                    //enemyArray[counter].aggresive = true;
                }
                counter2++;
            }
            counter++;
        }




        if(isPause == false)
        {
            ///Enemy aggresive
            ///.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///.//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            counter = 0;
            for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if(enemyArray[counter].aggresive == true)
                {
                    if(elapsed3.asSeconds() >= 0)
                    {
                        clock3.restart();

                        /*int tempRand = greaterRandom1(4);

                        ///Enemy fire projectile and chase player//////////////////////////////////////////
                        if(tempRand == 3 && enemyArray[counter].isMecha == true)
                        {
                            projectile1.fromEnemy = true;
                            ///Player to right
                            if((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) &&
                               (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) <= 40)
                            {
                                soundShot.play();
                                projectile1.isEnemy = true;
                                projectile1.direction = 3;
                                projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -projectile1.rect.getSize().x/2
                                                     ,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);

                                projectileArray.push_back(projectile1);

                                projectile1.isEnemy = false;
                                enemyArray[counter].direction = 3;

                            }
                            ///Player to left
                            if((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) &&
                               (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) <= 40)
                            {
                                soundShot.play();
                                projectile1.isEnemy = true;
                                projectile1.direction = 4;
                                projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -projectile1.rect.getSize().x/2
                                                     ,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);

                                projectileArray.push_back(projectile1);

                                projectile1.isEnemy = false;
                                enemyArray[counter].direction = 4;
                            }
                            ///Player to up down
                            if((Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) &&
                               (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) <= 40)
                            {
                                soundShot.play();
                                projectile1.isEnemy = true;
                                projectile1.direction = 1;
                                projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -projectile1.rect.getSize().x/2
                                                     ,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);

                                projectileArray.push_back(projectile1);

                                projectile1.isEnemy = false;
                                enemyArray[counter].direction = 1;

                            }
                            if((Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) &&
                               (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) <= 40)
                            {
                                soundShot.play();
                                projectile1.isEnemy = true;
                                projectile1.direction = 2;
                                projectile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x/2 -projectile1.rect.getSize().x/2
                                                     ,enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y/2 - projectile1.rect.getSize().y/2);

                                projectileArray.push_back(projectile1);

                                projectile1.isEnemy = false;
                                enemyArray[counter].direction = 2;

                            }
                            projectile1.fromEnemy = false;
                        }
                        ///j///////////////////////////////////////////////
                        */

                        if(enemyArray[counter].isDrone == true)
                        {
                            if(enemyArray[counter].attackPlayer1 == true)
                            {
                                ///chase player
                                if(upDown == true)
                                {
                                    if(Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 1;
                                    }
                                    else if(Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 2;
                                    }
                                    else if(Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 3;
                                    }
                                    else if(Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 4;
                                    }
                                }
                                else if(leftRight == true)
                                {
                                    if(Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 3;
                                    }
                                    else if(Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 4;
                                    }
                                    else if(Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 1;
                                    }
                                    else if(Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 2;
                                    }
                                }
                            }

                            if(enemyArray[counter].attackPlayer2 == true)
                            {
                                if(upDown == true)
                                {
                                    if(Player2.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 1;
                                    }
                                    else if(Player2.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 2;
                                    }
                                    else if(Player2.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 3;
                                    }
                                    else if(Player2.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 4;
                                    }
                                }
                                else if(leftRight == true)
                                {
                                    if(Player2.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 3;
                                    }
                                    else if(Player2.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10)
                                    {
                                        enemyArray[counter].direction = 4;
                                    }
                                    else if(Player2.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 1;
                                    }
                                    else if(Player2.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10)
                                    {
                                        enemyArray[counter].direction = 2;
                                    }
                                }
                            }
                        }
                        if(enemyArray[counter].isMecha == true)
                        {
                            if(enemyArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
                            {
                                enemyArray[counter].changeDirection = true;
                            }
                            if(enemyArray[counter].attackPlayer1 == true)
                            {
                                ///chase player
                                if(upDown == true)
                                {
                                    if(Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 1)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 2)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 3)
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 4)
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 4;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                }
                                else if(leftRight == true)
                                {
                                    if(Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 3)
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 4)
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 4;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 1)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 2)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                }
                            }

                            if(enemyArray[counter].attackPlayer2 == true)
                            {
                                if(enemyArray[counter].rect.getGlobalBounds().intersects(Player2.rect.getGlobalBounds()))
                                {
                                    enemyArray[counter].changeDirection = true;
                                }
                                if(upDown == true)
                                {
                                    if(Player2.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 1)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 2)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 3)
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 4)
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 4;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                }
                                else if(leftRight == true)
                                {
                                    if(Player2.rect.getPosition().x < enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 3)
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().x > enemyArray[counter].rect.getPosition().x &&
                                            (abs(Player2.rect.getPosition().x - enemyArray[counter].rect.getPosition().x)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 4)
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 4;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().y < enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 1)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 1;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                    else if(Player2.rect.getPosition().y > enemyArray[counter].rect.getPosition().y &&
                                            (abs(Player2.rect.getPosition().y - enemyArray[counter].rect.getPosition().y)) >= 10 && enemyArray[counter].changeDirection==true)
                                    {
                                        if(enemyArray[counter].direction == 2)
                                        {
                                            enemyArray[counter].direction = 3;
                                        }
                                        else
                                        {
                                            enemyArray[counter].direction = 2;
                                        }
                                        if(enemyArray[counter].isMecha == true)
                                        {
                                            enemyArray[counter].changeDirection=false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                counter++;
            }

        }




        ///projectile collide with enemies///////////////////////////////////////////////////////////////
        counter=0;
        for(iter=projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            counter2 = 0;
            for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
            {
                if( projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()) &&
                        projectileArray[counter].fromEnemy == false)
                {
                    soundCollision.play();
                    projectileArray[counter].destroy = true;

                    if(projectileArray[counter].isPlayer1 == true)
                    {
                        enemyArray[counter2].aggresive = true;
                        enemyArray[counter2].attackPlayer1 = true;
                        enemyArray[counter2].attackPlayer2 = false;
                    }
                    if(projectileArray[counter].isPlayer2 == true)
                    {
                        enemyArray[counter2].aggresive = true;
                        enemyArray[counter2].attackPlayer1 = false;
                        enemyArray[counter2].attackPlayer2 = true;
                    }

                    ///Text display
                    textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x/2,
                                                  enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y/2);
                    textArray.push_back(textDisplay1);

                    enemyArray[counter2].hp -= projectileArray[counter].attackDamage;
                    if(enemyArray[counter2].hp <=0)
                    {
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }


        /// delete dead enemy//////////////////////////////////////////////////////////////////////////
        counter = 0;
        for(auto iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if(enemyArray[counter].alive == false )
            {
                int x = greaterRandom1(8);
                ///drop xp
                if(x==0 || x==1 || x==2 || x==3 || x==4 || x== 5 || x==6 || x== 7)
                {
                    pickup1.isCoin = true;
                    pickup1.isHpSheild = false;
                    pickup1.isShield = false;
                    pickup1.isSpeedUp = false;
                    pickup1.isInvisibility = false;
                    pickup1.isMineBomb = false;



                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x -5,enemyArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                }

                if(x==0 || x==7)
                {
                    pickup1.isCoin = false;
                    pickup1.isHpSheild = false;
                    pickup1.isShield = true;
                    pickup1.isSpeedUp = false;
                    pickup1.isInvisibility = false;
                    pickup1.isMineBomb = false;


                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x +10,enemyArray[counter].rect.getPosition().y );
                    pickupArray.push_back(pickup1);
                }
                if(x==1 || x == 6)
                {
                    pickup1.isCoin = false;
                    pickup1.isHpSheild = false;
                    pickup1.isShield = false;
                    pickup1.isSpeedUp = true;
                    pickup1.isInvisibility = false;
                    pickup1.isMineBomb = false;


                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x +10,enemyArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                }
                if(x==3 || x==5)
                {
                    pickup1.isCoin = false;
                    pickup1.isHpSheild = false;
                    pickup1.isShield = false;
                    pickup1.isSpeedUp = false;
                    pickup1.isInvisibility = true;
                    pickup1.isMineBomb = false;

                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(enemyArray[counter].rect.getPosition().x +10,enemyArray[counter].rect.getPosition().y);
                    pickupArray.push_back(pickup1);
                }


                ///Creat enemy blood
                blood1.rect.setPosition(enemyArray[counter].rect.getPosition());
                bloodArray.push_back(blood1);


                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        ///delete projectile///////////////////////////////////////////////////////////////
        counter=0;
        for(iter=projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            if(projectileArray[counter].destroy == true)
            {
                projectileArray.erase(iter);
                break;
            }
            counter++;
        }

        ///Delete text display/////////////////////////////////////////////////////////////
        counter = 0;
        for(iter8 = textArray.begin(); iter8 != textArray.end(); iter8++)
        {
            if(textArray[counter].destroy==true)
            {
                textArray.erase(iter8);
                break;
            }
            counter++;
        }


        ///delete pickup items///////////////////////////////////////////////////////////////
        counter=0;
        for(iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            if(pickupArray[counter].destroy == true)
            {
                //cout<<"coin should be delete\n";
                pickupArray.erase(iter11);
                break;
            }
            counter++;
        }



        ///delete wall///////////////////////////////////////////////////////////////
        counter = 0;
        for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if(wallArray[counter].destroy == true)
            {
                int x = greaterRandom1(4);
                ///Land mine drop
                if(x==2)
                {
                    pickup1.isCoin = false;
                    pickup1.isHpSheild = false;
                    pickup1.isShield = false;
                    pickup1.isSpeedUp = false;
                    pickup1.isInvisibility = false;
                    pickup1.isMineBomb = true;

                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }
                if(x==1)
                {
                    pickup1.isCoin = false;
                    pickup1.isHpSheild = true;
                    pickup1.isShield = false;
                    pickup1.isSpeedUp = false;
                    pickup1.isInvisibility = false;
                    pickup1.isMineBomb = false;

                    pickup1.sprite.setTexture(texturePickup);
                    pickup1.rect.setPosition(wallArray[counter].rect.getPosition());
                    pickupArray.push_back(pickup1);
                }



                wallArray[counter].sprite.setTexture(textureObstacle);
                wallArray[counter].sprite.setTextureRect(sf::IntRect(40 * 5,0,40,40));
                wallArray[counter].isColliedable = false;
                wallArray[counter].destructable = false;
                wallArray[counter].isJungle = false;
                wallArray[counter].isProjectilePassable = true;
                wallArray[counter].destroy = false;
                //wallArray.erase(iter15);
                break;
            }
            counter++;
        }


        ///Delete  blood////////////////////////////////////////////////////////
        counter=0;
        for(iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            if(bloodArray[counter].alive == false)
            {
                bloodArray.erase(iter20);
                break;
            }
            counter++;
        }


        ///fun spawning enemy pressing y///////////////////////////////////////yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
        if(droneSpawnClock <= 0)
        {
            //droneSpawnClock.restart();
            droneSpawnClock = 10;
            int x=0,y=0;
            srand(time(0));
            int temp = rand()%4;
            if(temp == 0)
            {
                x = 200;
                y = 120;
                srand(time(0));
                y += (rand()%520 + rand()%400);
            }
            if(temp == 1)
            {
                x = 280;
                y = 1100;
                srand(time(0));
                x += (rand()%1000 + rand()%400);
            }
            if(temp == 2)
            {
                x = 240+1480;
                y = 120;
                srand(time(0));
                y += (rand()%600 + rand()%320);
            }
            if(temp == 3)
            {
                x = 280;
                y = 100;
                srand(time(0));
                x += (rand()%580 + rand()%820);
            }
            if(x!=0 && y!=0)
            {
                srand(time(NULL));
                int rando = rand()%2;
                if(rando==0)
                {
                    enemy1.attackPlayer1 = true;
                    enemy1.attackPlayer2 = false;
                }
                else
                {
                    enemy1.attackPlayer2 = true;
                    enemy1.attackPlayer1 = false;
                }
                enemy1.isDrone = true;
                enemy1.isMecha = false;
                enemy1.hp = 1;
                enemy1.maxHp = 1;
                enemy1.movementSpeed = 3;
                enemy1.aggresive = true;
                enemy1.sprite.setTexture(textureEnemyDrone);
                enemy1.rect.setPosition(sf::Vector2f(x,y));
                enemyArray.push_back(enemy1);
            }
        }
        if(mechaSpawnClock <= 0 && enemyArray.size() <=8)
        {
            //mechaSpawnClock.restart();
            mechaSpawnClock = 4;
            srand(time(0));
            int tempnumber = x.size();
            tempnumber = greaterRandom1(tempnumber);
            /*int temp = rand()%4;
            if(temp == 0)
            {
                x = 280;
                y = 120;
                srand(time(0));
                y += (rand()%520 + rand()%400);
            }
            if(temp == 1)
            {
                x = 280;
                y = 1040;
                srand(time(0));
                x += (rand()%1000 + rand()%400);
            }
            if(temp == 2)
            {
                x = 240+1400;
                y = 120;
                srand(time(0));
                y += (rand()%600 + rand()%320);
            }
            if(temp == 3)
            {
                x = 280;
                y = 140;
                srand(time(0));
                x += (rand()%580 + rand()%820);
            }*/

            {
                srand(time(NULL));
                int rando = rand()%2;
                if(rando==0)
                {
                    enemy1.attackPlayer1 = true;
                    enemy1.attackPlayer2 = false;
                }
                else
                {
                    enemy1.attackPlayer2 = true;
                    enemy1.attackPlayer1 = false;
                }
                enemy1.isDrone = false;
                enemy1.isMecha = true;
                enemy1.aggresive = false;
                enemy1.hp = 3;
                enemy1.maxHp = 3;
                enemy1.movementSpeed = 1;
                enemy1.sprite.setTexture(textureEnemyMecha);
                enemy1.rect.setPosition(sf::Vector2f(x[tempnumber],y[tempnumber]));
                enemyArray.push_back(enemy1);
            }
        }





        ///Draw wall////////////////////////////////////////////////////////////////
        counter=0;
        for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if(wallArray[counter].isJungle == false)
            {
                wallArray[counter].update(); ///update wall
                window.draw(wallArray[counter].sprite);
            }
            counter++;
        }






        ///Draw pickup/////////////////////////////////////////////////////////////
        counter=0;
        for(iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
        {
            //if(pickupArray[counter].isShop == true)
            // {
            //     window.draw(pickupArray[counter].text);
            // }


            pickupArray[counter].update(); ///update pickup
            //window.draw(pickupArray[counter].rect);
            window.draw(pickupArray[counter].sprite);
            counter++;
        }


        if(isPause == false)
        {

            ///Firing projectile(space bar)/////////////////////////////////////////////////////
            if(elapsedTimePlayer1.asSeconds()>= 0.5)
            {

                player1Clock.restart();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    fired = true;

                    projectile1.isPlayer1 = true;
                    projectile1.isPlayer2 = false;

                    projectile1.isPlayerLevel1 = Player1.isLevel1;
                    projectile1.isPlayerLevel2 = Player1.isLevel2;
                    projectile1.isPlayerLevel3 = Player1.isLevel3;

                    projectile1.attackDamage = Player1.attackDamage;

                    soundShot.play();


                    //else // normal attack
                    {
                        projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/2 - projectile1.rect.getSize().x/2
                                                     ,Player1.rect.getPosition().y + Player1.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player1.direction;
                        projectileArray.push_back(projectile1);
                    }
                    blood1.isProjectile = true;
                    blood1.sprite.setTexture(flashTexture);
                    if(Player1.direction == 1)
                    {
                        blood1.rect.setPosition(Player1.rect.getPosition().x-5,Player1.rect.getPosition().y-30);
                    }
                    if(Player1.direction == 2)
                    {
                        blood1.rect.setPosition(Player1.rect.getPosition().x-5,Player1.rect.getPosition().y+30);
                    }
                    if(Player1.direction == 3) ///left
                    {
                        blood1.rect.setPosition(Player1.rect.getPosition().x-33,Player1.rect.getPosition().y);
                    }
                    if(Player1.direction == 4) ///right
                    {
                        blood1.rect.setPosition(Player1.rect.getPosition().x+27,Player1.rect.getPosition().y);
                    }
                    blood1.direction = Player1.direction;
                    bloodArray.push_back(blood1);
                    blood1.isProjectile = false;
                    blood1.sprite.setTexture(textureBlood);
                }
            }
            if(elapsedTimePlayer2.asSeconds()>= 0.5)
            {
                player2Clock.restart();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
                {
                    projectile1.isPlayer1 = false;
                    projectile1.isPlayer2 = true;
                    soundShot.play();

                    projectile1.isPlayerLevel1 = Player2.isLevel1;
                    projectile1.isPlayerLevel2 = Player2.isLevel2;
                    projectile1.isPlayerLevel3 = Player2.isLevel3;

                    projectile1.attackDamage = Player2.attackDamage;


                    //else // normal attack
                    {
                        projectile1.rect.setPosition(Player2.rect.getPosition().x + Player2.rect.getSize().x/2 - projectile1.rect.getSize().x/2
                                                     ,Player2.rect.getPosition().y + Player2.rect.getSize().y/2 - projectile1.rect.getSize().y/2);
                        projectile1.direction = Player2.direction;
                        projectileArray.push_back(projectile1);
                    }
                    blood1.isProjectile = true;
                    blood1.sprite.setTexture(flashTexture);
                    if(Player2.direction == 1)
                    {
                        blood1.rect.setPosition(Player2.rect.getPosition().x-5,Player2.rect.getPosition().y-30);
                    }
                    if(Player2.direction == 2)
                    {
                        blood1.rect.setPosition(Player2.rect.getPosition().x-5,Player2.rect.getPosition().y+30);
                    }
                    if(Player2.direction == 3) ///left
                    {
                        blood1.rect.setPosition(Player2.rect.getPosition().x-33,Player2.rect.getPosition().y);
                    }
                    if(Player2.direction == 4) ///right
                    {
                        blood1.rect.setPosition(Player2.rect.getPosition().x+27,Player2.rect.getPosition().y);
                    }
                    blood1.direction = Player2.direction;
                    bloodArray.push_back(blood1);
                    blood1.isProjectile = false;
                    blood1.sprite.setTexture(textureBlood);
                }
            }


        }






        ///Draw projectile//////////////////////////////////////////////////////////////////
        counter=0;
        for(iter=projectileArray.begin(); iter != projectileArray.end(); iter++)
        {
            projectileArray[counter].update(); ///update projectile
            //window.draw(projectileArray[counter].rect);
            window.draw(projectileArray[counter].sprite);
            counter++;
        }


        if(isPause == false)
        {
            ///update player/////////////////////////////////////////////////////////////////////////
            Player1.update();
            Player1.updateMovement();

            Player2.update();
            Player2.updateMovement();


            ///Player View
            //window.setView(view1);
            //view1.setCenter(Player1.rect.getPosition());

        }


        ///Draw player
        if(Player1.isInvisibility == false)
        {
            Player1.rect.setFillColor(sf::Color::Red);
            //window.draw(Player1.rect);

            window.draw(Player1.sprite);
            if(Player1.isShield == true)
            {
                shieldEffectSprite.setPosition(Player1.rect.getPosition());
                window.draw(shieldEffectSprite);
            }
        }

        if(Player2.isInvisibility == false)
        {
            Player2.rect.setFillColor(sf::Color::Red);
            //window.draw(Player1.rect);
            window.draw(Player2.sprite);
            if(Player2.isShield == true)
            {
                shieldEffectSprite.setPosition(Player2.rect.getPosition());
                window.draw(shieldEffectSprite);
            }
        }



        ///Draw enemies//////////////////////////////////////////////////////////////
        counter=0;
        for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if(enemyArray[counter].isMecha == true)
            {
                if(isPause == false)
                {
                    enemyArray[counter].update(); ///update enemy

                    enemyArray[counter].updateMovement();
                }
                ///window.draw(enemyArray[counter].rect);
                window.draw(enemyArray[counter].sprite);
            }
            counter++;
        }

        /*///draw enemy text hp
        counter=0;
        for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            enemyArray[counter].text.setString("HP "+to_string(enemyArray[counter].hp)+ "/"+to_string(enemyArray[counter].maxHp));
            window.draw(enemyArray[counter].text);
            counter++;
        }*/


        ///Draw Explosions////////////////////////////////////////////////////////
        counter=0;
        for(iter20 = bloodArray.begin(); iter20 != bloodArray.end(); iter20++)
        {
            bloodArray[counter].update();
            window.draw(bloodArray[counter].sprite);
            counter++;
        }



        /*///Draw Text when projectile hit enemy or player got hit
        counter = 0;
        for(iter8 = textArray.begin(); iter8 != textArray.end(); iter8++)
        {
            textArray[counter].update();
            window.draw( textArray[counter].text);
            counter++;
        }*/

        ///Draw wall////////////////////////////////////////////////////////////////JUNGLE
        counter=0;
        for(iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
        {
            if(wallArray[counter].isJungle == true)
            {
                wallArray[counter].update(); ///update wall
                window.draw(wallArray[counter].sprite);
            }
            counter++;
        }




        ///Draw enemies Drone//////////////////////////////////////////////////////////////
        counter=0;
        for(iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
        {
            if(enemyArray[counter].isDrone == true)
            {
                if(isPause == false)
                {
                    enemyArray[counter].update(); ///update enemy

                    enemyArray[counter].updateMovement();
                }
                ///window.draw(enemyArray[counter].rect);
                window.draw(enemyArray[counter].sprite);
            }
            counter++;
        }



        window.draw(gameBackgroundSprite);


        sf::Color temp;

        ///Display Player title
        text.setCharacterSize(20);
        text.setPosition(22,35);
        text.setString("PLAYER-1");
        text.setFillColor(sf::Color::White);
        window.draw(text);

        text.setPosition(1717,35);
        text.setString("PLAYER-2");
        text.setFillColor(sf::Color::White);
        window.draw(text);



        temp = sf::Color(0,128,255);

        text.setPosition(25,150);
        text.setCharacterSize(45);
        text.setString("BLUE");
        text.setFillColor(temp);
        window.draw(text);
        text.setPosition(20,200);
        text.setCharacterSize(45);
        text.setString("TANK");
        text.setFillColor(temp);
        window.draw(text);

        temp = sf::Color(255,12,0);


        text.setPosition(1712+33,150);
        text.setCharacterSize(45);
        text.setString("RED");
        text.setFillColor(temp);
        window.draw(text);
        text.setPosition(1712+8,200);
        text.setCharacterSize(45);
        text.setString("TANK");
        text.setFillColor(temp);
        window.draw(text);

        ///Display Invisility time
        if(Player1.isInvisibility == true)
        {
            sf::Color temp(198,50,251);

            text.setPosition(25,500);
            text.setCharacterSize(20);
            text.setString("INVISIBLE");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(35,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(invisibilityClock1)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(25,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);

        }
        if(Player2.isInvisibility == true)
        {
            sf::Color temp(198,50,251);

            text.setPosition(1722,500);
            text.setCharacterSize(20);
            text.setString("INVISIBLE");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1732,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(invisibilityClock2)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1722,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);
        }


        ///Display Shield time
        if(Player1.isShield == true)
        {
            sf::Color temp(50,251,198);

            text.setPosition(30,500);
            text.setCharacterSize(20);
            text.setString("SHIELDED");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(35,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(shieldClock1)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(25,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);

        }
        if(Player2.isShield == true)
        {
            sf::Color temp(50,251,198);

            text.setPosition(1727,500);
            text.setCharacterSize(20);
            text.setString("SHIELDED");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1732,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(shieldClock2)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1722,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);
        }


        ///Display Speed time
        if(Player1.isSpeedUp == true)
        {
            sf::Color temp(251,198,50);

            text.setPosition(35,500);
            text.setCharacterSize(20);
            text.setString("BOOSTED");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(35,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(speedUpClock1)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(25,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);

        }
        if(Player2.isSpeedUp == true)
        {
            sf::Color temp(251,198,50);

            text.setPosition(1732,500);
            text.setCharacterSize(20);
            text.setString("BOOSTED");
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1732,535);
            text.setCharacterSize(80);
            text.setString(to_string(int(speedUpClock2)));
            text.setFillColor(temp);
            window.draw(text);

            text.setPosition(1722,625);
            text.setCharacterSize(20);
            text.setString("SECS LEFT");
            text.setFillColor(temp);
            window.draw(text);
        }




        ///Display Player Level
        int level = 0;
        if(Player1.isLevel1 == true)
        {
            level = 1;
            iconSprite1.setTextureRect(sf::IntRect(0,0,200,200));
        }
        if(Player1.isLevel2 == true)
        {
            level = 2;
            iconSprite1.setTextureRect(sf::IntRect(200,0,200,200));
        }
        if(Player1.isLevel3 == true)
        {
            level = 3;
            iconSprite1.setTextureRect(sf::IntRect(400,0,200,200));
        }
        iconSprite1.setPosition(15,270);
        window.draw(iconSprite1);


        temp = sf::Color(238,238,238);

        text.setPosition(22,675);
        text.setCharacterSize(20);
        text.setString("LEVEL");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(135,667);
        text.setCharacterSize(30);
        text.setString(to_string(int(level)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(150,675);
        text.setCharacterSize(20);
        text.setString(" /3");
        text.setFillColor(temp);
        window.draw(text);




        if(Player2.isLevel1 == true)
        {
            level = 1;
            iconSprite2.setTextureRect(sf::IntRect(0,0,200,200));
        }
        if(Player2.isLevel2 == true)
        {
            level = 2;
            iconSprite2.setTextureRect(sf::IntRect(200,0,200,200));
        }

        if(Player2.isLevel3 == true)
        {
            level = 3;
            iconSprite2.setTextureRect(sf::IntRect(400,0,200,200));
        }
        iconSprite2.setPosition(1709,270);
        window.draw(iconSprite2);

        temp = sf::Color(238,238,238);

        text.setPosition(1712+22 - 17,675);
        text.setCharacterSize(20);
        text.setString("LEVEL");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(1712+135 - 17,667);
        text.setCharacterSize(30);
        text.setString(to_string(int(level)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(1712 +150 - 17,675);
        text.setCharacterSize(20);
        text.setString(" /3");
        text.setFillColor(temp);
        window.draw(text);




        ///Displaay Match timer
        //minute = (totalMatchTime-elapsedTimeOfMatch.asSeconds())/60;
        //second = int(totalMatchTime-elapsedTimeOfMatch.asSeconds())%60;
        minute = totalMatchTime/60.f;
        second = float(int(totalMatchTime)%60);

        countdownText.setCharacterSize(55);
        countdownText.setPosition((window.getSize().x/2) - 145,20.f);
        countdownText.setString(to_string(int(minute))+ ":" + to_string(int(second)));
        if(window.isOpen())
        {
            sf::Color temp(238,238,238);
            countdownText.setFillColor(temp);
            window.draw(countdownText);
        }



        ///Display XP

        temp = sf::Color(128,255,0);

        text.setPosition(1712+22 - 17,675+ 50);
        text.setCharacterSize(20);
        text.setString("XP ");
        text.setFillColor(temp);
        window.draw(text);


        text.setCharacterSize(30);
        if(Player2.points < 0)
            text.setPosition(1712+105,667+ 50);
        else
            text.setPosition(1712+135 - 17,667+ 50);
        text.setString(to_string(int(Player2.points)));
        text.setFillColor(temp);
        window.draw(text);



        text.setPosition(22,675+ 50);
        text.setCharacterSize(20);
        text.setString("XP ");
        text.setFillColor(temp);
        window.draw(text);


        text.setCharacterSize(30);
        if(Player1.hp < 0)
            text.setPosition(105,667+ 50);
        else
            text.setPosition(135,667+ 50);
        text.setString(to_string(int(Player1.points)));
        text.setFillColor(temp);
        window.draw(text);




        ///HP
        temp = sf::Color(255,0,128);

        text.setPosition(22,775);
        text.setCharacterSize(20);
        text.setString("HP");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(135,767);
        text.setCharacterSize(30);
        if(Player1.hp < 0)
        {
            Player1.hp = 0;
        }
        if(Player1.hp > 5)
        {
            text.setPosition(105,767);
        }
        if(Player1.hp > 9)
        {
            text.setPosition(85,767);
        }
        text.setString(to_string(int(Player1.hp)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(150,775);
        if(Player1.maxHp > 9)
        {
            text.setPosition(130,770);
        }
        text.setCharacterSize(20);
        text.setString(" /" + to_string(Player1.maxHp));
        text.setFillColor(temp);
        window.draw(text);


        text.setPosition(22+1695,775);
        text.setCharacterSize(20);
        text.setString("HP");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(135+1695,767);
        text.setCharacterSize(30);
        if(Player2.hp < 0)
        {
            Player2.hp = 0;
        }
        if(Player2.hp > 5)
        {
            text.setPosition(105+1695,767);
        }
        if(Player2.hp > 9)
        {
            text.setPosition(85+1695,767);
        }
        text.setString(to_string(int(Player2.hp)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(150+1695,775);
        text.setCharacterSize(20);
        if(Player2.maxHp > 9)
        {
            text.setPosition(125+1695,770);
        }
        text.setString(" /" + to_string(Player2.maxHp));
        text.setFillColor(temp);
        window.draw(text);



        ///DPS
        temp = sf::Color(0,128,255);

        text.setPosition(22,775+ 50);
        text.setCharacterSize(20);
        text.setString("DPS");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(135,767+ 50);
        text.setCharacterSize(30);
        text.setString(to_string(int(Player1.attackDamage)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(150,775 + 50);
        text.setCharacterSize(20);
        text.setString(" /" + to_string(3));
        text.setFillColor(temp);
        window.draw(text);


        text.setPosition(22+1695,775+ 50);
        text.setCharacterSize(20);
        text.setString("DPS");
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(135+1695,767+ 50);
        text.setCharacterSize(30);
        text.setString(to_string(int(Player2.attackDamage)));
        text.setFillColor(temp);
        window.draw(text);

        text.setPosition(150+1695,775+ 50);
        text.setCharacterSize(20);
        text.setString(" /" + to_string(3));
        text.setFillColor(temp);
        window.draw(text);


        if(isPause == true && isGameOver == false)
        {
            window.draw(transparentSprite);

            ///Draw Button main menu
            if(clickedItem == 1)
            {
                resume.setTextureRect(sf::IntRect(1000,0,500,500));
                resume.setPosition(sf::Vector2f(700,200));
                window.draw(resume);
            }
            else if(selectedItemIndex == 0)
            {
                resume.setTextureRect(sf::IntRect(500,0,500,500));
                resume.setPosition(sf::Vector2f(700,200));
                window.draw(resume);
            }
            else
            {
                resume.setTextureRect(sf::IntRect(0,0,500,500));
                resume.setPosition(sf::Vector2f(700,200));
                window.draw(resume);
            }

            if(clickedItem == 2)
            {
                endMatch.setTextureRect(sf::IntRect(1000,500,500,500));
                endMatch.setPosition(sf::Vector2f(700,320));
                window.draw(endMatch);
            }
            else if(selectedItemIndex == 1)
            {
                endMatch.setTextureRect(sf::IntRect(500,500,500,500));
                endMatch.setPosition(sf::Vector2f(700,320));
                window.draw(endMatch);
            }
            else
            {
                endMatch.setTextureRect(sf::IntRect(0,500,500,500));
                endMatch.setPosition(sf::Vector2f(700,320));
                window.draw(endMatch);
            }
        }

        if(isPause == true && isGameOver == true  && elapsedGameOverWaitingTime.asSeconds() > 3.f)
        {
            window.draw(transparentSprite);

            text.setString(winnerPlayerTitle);
            text.setCharacterSize(70);
            text.setPosition(510,350);
            text.setFillColor(winnerTitle);
            window.draw(text);

            sf::Color temp(238,238,238);
            text.setFillColor(temp);

            if(elapsedGameOverWaitingTime.asSeconds() > 5.f && matchIsDraw == false)
            {
                text.setString("ENTER YOUR NAME:");
                text.setCharacterSize(35);
                text.setPosition(680,485);
                window.draw(text);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                {
                    if(playerInput.length() > 0)
                    {
                        playerInput.pop_back();
                        playerText.setString(playerInput);
                    }
                }
                else if(event.type == sf::Event::TextEntered && playerInput.length()<10)
                {
                    playerInput += event.text.unicode;
                    playerText.setString(playerInput);
                    playerText.setFont(font);
                    playerText.setPosition(815,570);
                }


                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && playerInput.length()!=0)
                {
                    cout<<"x\n";
                    fstream myFile;
                    myFile.open("file/HallOfFame.txt",ios::app);
                    string name = playerInput;
                    myFile << name << '\n';
                    myFile.close();

                    windowChangeSound.play();
                    wait(1);
                    //window.close();
                    return 0;
                }

                string tempDash="__________";
                text.setString(tempDash);
                text.setCharacterSize(30);
                text.setPosition(815,580);
                window.draw(text);
            }


        }
        window.draw(playerText);


        ///Display
        window.display();



        if(isPause == true && isGameOver == false)
        {
            switch (clickedItem)
            {
            case 0:
                break;
            case 1:
            {
                windowChangeSound1.play();
                wait(0.25);
                isPause = false;
                clickedItem = 0;
            }
            break;


            case 2:
            {
                windowChangeSound1.play();
                wait(0.25);
                //window.close();
                return 0;
            }
            break;
            }
        }

    }
}

