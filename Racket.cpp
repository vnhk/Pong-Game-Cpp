#include "Racket.h"


Racket::Racket(int x, int y, int width, int height)
{
    texture.loadFromFile("textures/racket5.png");
    rectangle.setTexture(texture);
    boostracket = 0;


}
Racket::~Racket()
{

}

void Racket::setPlayerRacket()
{
    rectangle.setPosition(50,225);
}
void Racket::setComputerRacket()
{
    rectangle.setPosition(1100,225);
    texture.loadFromFile("textures/racket5c.png");
    rectangle.setTexture(texture);

}

int Racket::draw(sf::RenderWindow &window)
{
    window.draw(rectangle);
    return rectangle.getPosition().y;
}

void Racket::move(int y, int height)
{
    rectangle.move(0,y);

    if(rectangle.getPosition().y<0)
        rectangle.setPosition(50,0);
    else if(rectangle.getPosition().y>height-150)
        rectangle.setPosition(50,height-150);
}

void Racket::followBall(int *y, int ballSpeedX, int lvl)
{
    if(lvl>=9)
       boostracket = 2;
    else if(lvl>=6)
       boostracket = 1;
    else boostracket = 0;


    if(ballSpeedX>0)
    {

        if(y[0]>1000&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+4+boostracket);
        else if(y[0]>1000&&(y[1]<rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(4+boostracket));

        if(y[0]>750&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+6+boostracket);
        else if(y[0]>750&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(6+boostracket));

        else if(y[0]>600&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+5+boostracket);
        else if(y[0]>600&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(5+boostracket));

        else if(y[0]>450&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+4+boostracket);
        else if(y[0]>450&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(4+boostracket));

        else if(y[0]>300&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+3+boostracket);
        else if(y[0]>300&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(3+boostracket));

        else if(y[0]>150&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+2+boostracket);
        else if(y[0]>150&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(2+boostracket));


        else
            rectangle.setPosition(1100,rectangle.getPosition().y-(1+boostracket));
    }
    else
    {
        if(y[0]>1000&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y);
        else if(y[0]>1000&&(y[1]<rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y);



        else if(y[0]>600&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+2+boostracket);
        else if(y[0]>600&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(2+boostracket));

        else if(y[0]>450&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+1+boostracket);
        else if(y[0]>450&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(1+boostracket));

        else if(y[0]>300&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+2+boostracket);
        else if(y[0]>300&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(2+boostracket));

        else if(y[0]>150&&(y[1]>rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y+4+boostracket);
        else if(y[0]>150&&(y[1]<=rectangle.getPosition().y))
            rectangle.setPosition(1100,rectangle.getPosition().y-(4+boostracket));


        else
            rectangle.setPosition(1100,rectangle.getPosition().y-1);
    }




    if(rectangle.getPosition().y<0)
        rectangle.setPosition(1100,0);
    else if(rectangle.getPosition().y>(600-150))
        rectangle.setPosition(1100,600-150);
}

void Racket::followBallPlayerToTest(int *y)
{
    rectangle.setPosition(50,y[1]-150/2 + 25);
    if(rectangle.getPosition().y<0)
        rectangle.setPosition(50,0);
    else if(rectangle.getPosition().y>600-150)
        rectangle.setPosition(50,600-150);
}
