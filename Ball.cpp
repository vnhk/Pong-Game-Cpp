#include "Ball.h"


Ball:: Ball(sf::RenderWindow &window)
{
    ballsize = 50;
    ball.setPosition(window.getSize().x/2,window.getSize().y/2);
    texture.loadFromFile("textures/ball4.png");
    ball.setTexture(texture);
    racketSizex=150;

    speedx=5.5;
    speedy=5.5;
    speed =5.5;
}
Ball:: ~Ball()
{

}

void Ball::setPositionxy(sf::RenderWindow &window)
{
    ball.setPosition(window.getSize().x/2,window.getSize().y/2);
}


void Ball::draw(sf::RenderWindow &window, std::string choice)
{


        texture.loadFromFile("textures/ball"+choice+".png");
        ball.setTexture(texture);
        window.draw(ball);

}

int Ball::moveball(int racket1pos,int racket2pos, bool *ctrl,int *ballposition,int **score,int *positionforEv,bool trafiony, int **fail,int *lvl)
{

    if(speedx>30)
        speedx=12;

    if(speedy>12)
        speedy=7;

    if(rand()%2)
        special[0]=true;
    else
        special[0]=false;

    if(rand()%2)
        special[1]=true;
    else
        special[1]=false;

    if(rand()%2)
        special[2]=true;
    else
        special[2]=false;


    int x = ball.getPosition().x;
    int y = ball.getPosition().y;


    //r9andevents
    if((x >= positionforEv[0]&&x <= positionforEv[0]+50&&y >= positionforEv[1]&&y <=positionforEv[1]+50)
            ||(x +50 >= positionforEv[0]&&x + 50 <= positionforEv[0]+50&&y >= positionforEv[1]&&y <=positionforEv[1]+50)
            ||(x >= positionforEv[0]&&x <= positionforEv[0]+50&&y+50 >= positionforEv[1]&&y+50 <=positionforEv[1]+50)
            ||(x+50 >= positionforEv[0]&&x+50 <= positionforEv[0]+50&&y+50 >= positionforEv[1]&&y+50 <=positionforEv[1]+50))
    {
        trafiony = true;
        if(positionforEv[1]==325)speedx=-speedx;
        speedy=-speedy;
        while(eventlast==event)
            event = 1+ rand()%7;

        switch(event)
        {
        case 1:
            positionforEv[0] = 450;
            positionforEv[1] = 200;
            break;
        case 2:
            positionforEv[0] = 450;
            positionforEv[1] = 300;
            break;
        case 3:
            positionforEv[0] = 450;
            positionforEv[1] = 400;
            break;
        case 4:
            positionforEv[0] = 750;
            positionforEv[1] = 200;
            break;
        case 5:
            positionforEv[0] = 750;
            positionforEv[1] = 300;
            break;
        case 6:
            positionforEv[0] = 750;
            positionforEv[1] = 400;
            break;
        case 7:
            positionforEv[0] = 575;
            positionforEv[1] = 325;
            break;

        }
        eventlast=event;



    }



    if(y<=0)
    {
        ball.setPosition(x,y+5);
        speedy=-speedy;
    }
    if(x>=1200-ballsize)
    {
        ball.setPosition(600-ballsize/2,300-ballsize/2);


        switch(*lvl)
        {
            case 2:
            case 1:
            case 0: **score+=10;
            break;
            case 5:
            case 4:
            case 3: **score+=150;
            break;
            default: **score+=400;
            break;
        }

        if(**fail>0&&(*lvl==3||*lvl==6||*lvl>=9))
            --**fail;
        ++*lvl;


        speedx = speed;
        speedy = speed;
    }
    if(x<=0)
    {
        ball.setPosition(600-ballsize/2,300-ballsize/2);
        ++**fail;
        speedx = -speed;
        speedy = -speed;

    }
    if(y>=600-ballsize)
    {
        ball.setPosition(x,y-5);
        speedy=-speedy;
    }

    if((x<=75&&x>=50)&&(y>=racket1pos-50&&y<=racket1pos+racketSizex+10))
    {
        speedx=-speedx;
        ball.setPosition(80,y);

        if(ctrl[0])
            speedx+=5;
        if(ctrl[1])
        {
            speedy=-speedy;

        }
        else if(ctrl[2])
        {
            speedy*=1.2;
            speedx+=12;
        }

        **score +=5;
        if(*lvl>=9)
            **score+=100;

    }
    else if((x>=1050&&x<=1100)&&(y>=racket2pos-10&&y<=racket2pos+racketSizex+10))
    {
        ball.setPosition(1050,y);
        speedx=-speed;
        if(speedy>=0)
            speedy=speed;
        else
            speedy = -speed;

        if(special[0])
            speedx-=5;
        if(special[1])
        {
            speedy=-speedy;

        }
        else if(special[2])
        {
            speedy*=1.2;
            speedx-=12;
        }

    }
    ball.move(speedx,speedy);
    if(**score>=99999)
        **score=99999;

    ballposition[0]=ball.getPosition().x;
    ballposition[1]=ball.getPosition().y;

    return speedx;
}
