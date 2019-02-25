#include "Racket.h"
#include "Ball.h"
#include "Field.h"
#include "Button.h"
#include "Ranking.h"
#include "textEntered.h"
#include "audio.h"
#include "Credits.h"
#include "Options.h"

int main()
{
    sf::Font font1;
    font1.loadFromFile("fonts/montague.ttf");
    const int width=1200,height=600;
    const int racketSizex = 30;
    const int racketSizey = 150;

    srand(time(NULL));

    int ballPosition[2];
    int speedx=0;

    int racket1Position;
    int racket2Position;
    bool special[4];
    int racketSpeed = 10;
    int lvl = 0; //0latwy3sredni6trudny9wygrana


    int var = 0;
    int var1 = 0;
    int *score = &var;
    int *fail = &var1;

    bool trafiony = true;
    int positionforEv[2]= {575,275};

    sf::RenderWindow window(sf::VideoMode(width, height,32), "PONGPING", sf::Style::None);
    window.setVerticalSyncEnabled(true);

    int numberoptions = 5;
    Option computerTYPE;
    Option musicingame;
    Option musicinmenu;
    string cnt="0000";
    string *options = &cnt;
    loadOptions(&options);

    sf::Text optionsGame[numberoptions];
    string content[numberoptions];
    for(int i = 0; i<numberoptions; i++)
    {
        content[i] = cnt[i];
        optionsGame[i].setFont(font1);
    }

    optionsGame[0].setString("Computer MODE: FOLLOW ");
    optionsGame[1].setString("Music in game ");
    optionsGame[2].setString("Music in menu ");
    optionsGame[3].setString("Choose ball ");
    optionsGame[4].setString("Click to change music ");
    textsetting(optionsGame,numberoptions);
    optionsGame[4].setPosition(25,250);

    sf::Sprite ballOptions;
    sf::Texture ballOptionsTexture;
    string choiceball = content[3];
    ballOptionsTexture.loadFromFile(loadBall(content));
    ballOptions.setTexture(ballOptionsTexture);
    ballOptions.setPosition(700,160);

    sf::Sprite musicSprite;
    sf::Texture musicTexture;

    musicTexture.loadFromFile("textures/music.png");
    musicSprite.setTexture(musicTexture);
    musicSprite.setPosition(700,255);

    Field gameFieldDefault(width,height);

    sf::Texture pause;
    pause.loadFromFile("textures/pause.png");
    sf::Sprite pauseSprite;
    pauseSprite.setTexture(pause);

    Button buttonStart(50,50);
    buttonStart.setTexture(2);
    Button buttonExit(50,525);
    buttonExit.setTexture(4);
    Button buttonRank(50,105);
    buttonRank.setTexture(6);
    Button buttonCredits(50,160);
    buttonCredits.setTexture(10);
    Button buttonBack(0,525);
    buttonBack.setTexture(8);
    Button buttonOptions(50,215);
    buttonOptions.setTexture(12);
    Button on_off(1000,10);
    on_off.setTexture(14);
    Button on_off1(1000,65);
    on_off1.setTexture(14);
    Button on_off2(1000,120);
    on_off2.setTexture(14);


    Music interfacemusic;
    interfacemusic.musicChoice(content);
    interfacemusic.musicVolume(85);
    Music gamemusic;
    gamemusic.musicChoice(content);
    gamemusic.musicVolume(40);

    if(musicinmenu.loadOption(content,3)=="ON")
        interfacemusic.musicPlay();



    sf::Texture interfacetext;
    interfacetext.loadFromFile("textures/interface1.png");
    sf::Sprite interface;
    interface.setTexture(interfacetext);

    sf::Texture ranktext;
    ranktext.loadFromFile("textures/ranking.png");
    sf::Sprite rankingSpr;
    rankingSpr.setTexture(ranktext);

    sf:: Text playerRank[10];

    for(int i = 0; i<10; i++)
    {
        playerRank[i].setFont(font1);
    }
    textsetting(playerRank,10);

    Racket racket1(50,height-racketSizey,racketSizex,racketSizey);
    racket1.setPlayerRacket();
    Racket racket2(width-racketSizex-50,75,racketSizex,racketSizey);
    racket2.setComputerRacket();

    Ball ball(window);

    bool gameRun=false;
    bool interfaceRun = true;
    bool rankRun = false;
    bool creditsRun = false;
    bool optionsRun = false;
    bool pauseRun = false;
    bool compOP = computerTYPE.loadOption(content,1)=="ON"?true:false;
    bool backgroundimage = false;

    int creditsline;
    creditsline = creditsSize();
    sf::Text creditText[creditsline];
    for(int i = 1; i < creditsline; ++i)
    {
        creditText[i].setFont(font1);
        creditText[i].setCharacterSize(10);
        creditText[i].setFillColor(sf::Color::White);
        creditText[i].setPosition(10,50+(i-1)*20);
    }
    creditText[0].setCharacterSize(50);
    creditText[0].setPosition(10,0);
    creditText[0].setFont(font1);
    creditText[0].setFillColor(sf::Color::White);

    string playerNick;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape&&gameRun)
            {
                pauseRun = false;
                gameRun = true;
                backgroundimage = false;
                lvl = 0;
                *fail = 4;
                if(musicingame.loadOption(content,2)=="ON")
                    gamemusic.musicStop();
                if(musicinmenu.loadOption(content,3)=="ON")
                    interfacemusic.musicPlay();
            }
            if (gameRun&&event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            {
                pauseRun=true;
                gameRun=false;
            }
            else if(pauseRun&&event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            {
                pauseRun=false;
                gameRun = true;
            }

            if(gameRun == false&&interfaceRun == true)
            {


                if(sf::Mouse::getPosition( window ).x >= buttonStart.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonStart.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=buttonStart.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonStart.getPositiony()+50)
                {
                    buttonStart.setTexture(1);
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {

                        playerNick =chooseNick();
                        gameRun = true;
                        interfacemusic.musicStop();
                        if(musicingame.loadOption(content,2)=="ON")
                            gamemusic.musicPlay();

                    }

                }
                else buttonStart.setTexture(2);

                if(sf::Mouse::getPosition( window ).x >= buttonExit.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonExit.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=buttonExit.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonExit.getPositiony()+50)
                {
                    buttonExit.setTexture(3);
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        window.close();
                        if(musicingame.loadOption(content,2)=="ON")
                            gamemusic.musicStop();
                        if(musicinmenu.loadOption(content,3)=="ON")
                            interfacemusic.musicPlay();
                    }

                }
                else buttonExit.setTexture(4);

                if(sf::Mouse::getPosition( window ).x >= buttonCredits.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonCredits.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=buttonCredits.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonCredits.getPositiony()+50)
                {
                    buttonCredits.setTexture(9);
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(creditText[0].getString()!="CREDITS")
                        {
                            credits(creditText);
                            creditText[0].setString("CREDITS");
                        }


                        creditsRun = true;
                        interfaceRun = false;
                    }
                }
                else buttonCredits.setTexture(10);

                if(sf::Mouse::getPosition( window ).x >= buttonOptions.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonOptions.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=buttonOptions.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonOptions.getPositiony()+50)
                {
                    buttonOptions.setTexture(11);
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(musicinmenu.loadOption(content,3)=="ON")
                        {
                            on_off2.setTexture(14);
                        }
                        else on_off2.setTexture(13);

                        if(musicingame.loadOption(content,2)=="ON")
                        {
                            on_off1.setTexture(14);
                        }
                        else on_off1.setTexture(13);
                        if(computerTYPE.loadOption(content,1)=="ON")
                        {
                            on_off.setTexture(14);
                        }
                        else on_off.setTexture(13);

                        optionsRun = true;
                        interfaceRun = false;
                    }
                }
                else buttonOptions.setTexture(12);

                if(sf::Mouse::getPosition( window ).x >= buttonRank.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonRank.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=buttonRank.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonRank.getPositiony()+50)
                {
                    buttonRank.setTexture(5);
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        interfaceRun = false;
                        LoadTable(playerRank);
                        rankRun = true;
                    }
                }
                else buttonRank.setTexture(6);
            }
            else if (optionsRun)
            {
                if(sf::Mouse::getPosition( window ).x >= on_off.getPositionx()&&sf::Mouse::getPosition( window ).y>=on_off.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=on_off.getPositionx()+50&&sf::Mouse::getPosition( window ).y<=on_off.getPositiony()+50)
                {
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(computerTYPE.loadOption(content,1)=="ON")
                        {
                            on_off.setTexture(13);
                            content[0]="0";
                            compOP = false;
                        }
                        else
                        {
                            on_off.setTexture(14);
                            content[0]="1";
                            compOP = true;
                        }
                    }

                }
                else if(sf::Mouse::getPosition( window ).x >= on_off1.getPositionx()&&sf::Mouse::getPosition( window ).y>=on_off1.getPositiony()
                        &&sf::Mouse::getPosition( window ).x<=on_off1.getPositionx()+50&&sf::Mouse::getPosition( window ).y<=on_off1.getPositiony()+50)
                {
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(musicingame.loadOption(content,2)=="ON")
                        {
                            on_off1.setTexture(13);
                            content[1]="0";
                        }
                        else
                        {
                            on_off1.setTexture(14);
                            content[1]="1";
                        }
                    }
                }
                else if(sf::Mouse::getPosition( window ).x >= 700&&sf::Mouse::getPosition( window ).y>=160
                        &&sf::Mouse::getPosition( window ).x<=700+50&&sf::Mouse::getPosition( window ).y<=160+50)
                {
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {

                        if(content[3]=="1")content[3]="2";
                        else if (content[3]=="2")content[3]="3";
                        else if (content[3]=="3")content[3]="4";
                        else if (content[3]=="4")content[3]="5";
                        else content[3]="1";
                        ballOptionsTexture.loadFromFile(loadBall(content));
                        choiceball = content[3];

                    }
                }
                else if(sf::Mouse::getPosition( window ).x >= 700&&sf::Mouse::getPosition( window ).y>=255
                        &&sf::Mouse::getPosition( window ).x<=700+50&&sf::Mouse::getPosition( window ).y<=255+50)
                {
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {

                        if(musicinmenu.loadOption(content,3)=="ON")
                            interfacemusic.musicStop();
                        if(content[4]=="1")content[4]="2";
                        else content[4]="1";
                        interfacemusic.musicChoice(content);
                        gamemusic.musicChoice(content);
                        interfacemusic.musicPlay();

                    }
                }

                else  if(sf::Mouse::getPosition( window ).x >= on_off2.getPositionx()&&sf::Mouse::getPosition( window ).y>=on_off2.getPositiony()
                         &&sf::Mouse::getPosition( window ).x<=on_off2.getPositionx()+50&&sf::Mouse::getPosition( window ).y<=on_off2.getPositiony()+50)
                {
                    if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    {
                        if(musicinmenu.loadOption(content,3)=="ON")
                        {
                            on_off2.setTexture(13);
                            content[2]="0";
                            interfacemusic.musicStop();
                        }
                        else
                        {
                            on_off2.setTexture(14);
                            content[2]="1";
                            interfacemusic.musicPlay();
                        }
                    }

                }
            }

            if((rankRun||creditsRun||optionsRun)&&sf::Mouse::getPosition( window ).x >= buttonBack.getPositionx()&&sf::Mouse::getPosition( window ).y>=buttonBack.getPositiony()
                    &&sf::Mouse::getPosition( window ).x<=buttonBack.getPositionx()+200&&sf::Mouse::getPosition( window ).y<=buttonBack.getPositiony()+50)
            {
                buttonBack.setTexture(7);

                if( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    if(optionsRun)
                        saveToFile(content,numberoptions);

                    interfaceRun = true;
                    rankRun = false;
                    creditsRun = false;
                    optionsRun = false;
                }
            }
            else buttonBack.setTexture(8);
        }


        if(lvl==0)
            racketSpeed = 9;

        if(lvl>=3)
            racketSpeed = 6;
        if(lvl>=9)
            racketSpeed = 3;

        if(gameRun&&compOP==false)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                racket1.move(-racketSpeed,height);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                racket1.move(racketSpeed,height);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                special[0] = true;
            }
            else
                special[0] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
            {
                special[1] = true;
            }
            else
                special[1] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                special[2] = true;
            }
            else
                special[2] = false;

        }
        if(compOP)
        {
            special[0] = true;
            special[1] = false;
            special[2] = true;
        }



        if(pauseRun)
        {
            window.clear();
            gameFieldDefault.draw(window,trafiony,positionforEv,score,fail);
            racket1Position = racket1.draw(window);
            racket2Position = racket2.draw(window);
            ball.draw(window,choiceball);
            window.draw(pauseSprite);
            window.display();
        }
        else if(gameRun)
        {
            if(*fail>3)
            {
                gameRun = false;
                interfaceRun = true;
                backgroundimage = false;
                if(musicingame.loadOption(content,2)=="ON")
                    gamemusic.musicStop();
                if(musicinmenu.loadOption(content,3)=="ON")
                    interfacemusic.musicPlay();

                    if(compOP==false)
                        addPlayer(&score,playerNick);

                lvl = 0;
                *score = 0;
                ball.setPositionxy(window);
                *fail = 0;
            }
            window.clear();
            if(lvl==0&&backgroundimage==false)
            {
                gameFieldDefault.setTexture(1);
                backgroundimage = true;
            }
            else if(lvl==3&&backgroundimage)
            {
                gameFieldDefault.setTexture(2);
                backgroundimage = false;
            }
            else if(lvl==6&&backgroundimage==false)
            {
                gameFieldDefault.setTexture(3);
                backgroundimage = true;
            }
            else if(lvl==9&&backgroundimage)
            {
                gameFieldDefault.setTexture(4);
                backgroundimage = false;
            }
            gameFieldDefault.draw(window,trafiony,positionforEv,score,fail);

            racket1Position = racket1.draw(window);
            racket2Position = racket2.draw(window);
            speedx = ball.moveball(racket1Position,racket2Position,special,ballPosition,&score,positionforEv,trafiony,&fail,&lvl);
            ball.draw(window,choiceball);

            if(compOP)
            {
                racket1.followBallPlayerToTest(ballPosition);
            }


            racket2.followBall(ballPosition,speedx,lvl);

            window.display();
        }
        else if(interfaceRun)
        {
            window.clear();
            window.draw(interface);
            buttonStart.draw(window);
            buttonExit.draw(window);
            buttonRank.draw(window);
            buttonCredits.draw(window);
            buttonOptions.draw(window);
            interfacemusic.drawCredits(window);
            window.display();
        }
        else if(rankRun)
        {
            window.clear();
            window.draw(rankingSpr);
            setRankTable(playerRank,window);
            buttonBack.draw(window);
            interfacemusic.drawCredits(window);
            window.display();
        }
        else if(creditsRun)
        {
            window.clear();
            creditsDraw(window, creditsline,creditText);
            buttonBack.draw(window);
            window.display();
        }
        else if(optionsRun)
        {
            window.clear();
            buttonBack.draw(window);
            optionsDraw(window, numberoptions,optionsGame);
            interfacemusic.drawCredits(window);
            on_off.draw(window);
            on_off1.draw(window);
            window.draw(ballOptions);
            window.draw(musicSprite);
            on_off2.draw(window);
            window.display();
        }
    }

    if(musicinmenu.loadOption(content,3)=="ON")
        interfacemusic.musicStop();
    return 0;
}
