#include "Button.h"


Button::Button(int x,int y)
{
    ButtonSprite.setPosition(x,y);
}

Button::~Button()
{

}

void Button::setTexture(int choice)
{
    switch(choice)
    {


    case 1:
        ButtonTexture.loadFromFile("textures/button1hover.png");
        break;
    case 2:
        ButtonTexture.loadFromFile("textures/button1.png");
        break;
    case 3:
        ButtonTexture.loadFromFile("textures/button2hover.png");
        break;
    case 4:
        ButtonTexture.loadFromFile("textures/button2.png");
        break;
    case 5:
        ButtonTexture.loadFromFile("textures/button3hover.png");
        break;
    case 6:
        ButtonTexture.loadFromFile("textures/button3.png");
        break;
    case 7:
        ButtonTexture.loadFromFile("textures/buttonbackhover.png");
        break;
    case 8:
        ButtonTexture.loadFromFile("textures/buttonback.png");
        break;
    case 9:
        ButtonTexture.loadFromFile("textures/button4hover.png");
        break;
    case 10:
        ButtonTexture.loadFromFile("textures/button4.png");
        break;
    case 11:
        ButtonTexture.loadFromFile("textures/button5hover.png");
        break;
    case 12:
        ButtonTexture.loadFromFile("textures/button5.png");
        break;
    case 13:
        ButtonTexture.loadFromFile("textures/offbutton.png");
        break;
    case 14:
        ButtonTexture.loadFromFile("textures/onbutton.png");
        break;
    default:
        ;
    }


    ButtonSprite.setTexture(ButtonTexture);
}

void Button::draw(sf::RenderWindow &window)
{

    window.draw(ButtonSprite);
}
int Button::getPositionx()
{
    return ButtonSprite.getPosition().x;
}
int Button::getPositiony()
{
    return ButtonSprite.getPosition().y;
}

