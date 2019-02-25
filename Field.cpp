#include "Field.h"


Field::Field(int width, int height)
{


    textureRandShape.loadFromFile("textures/event1.png");
    randShape.setTexture(textureRandShape);

    field.loadFromFile("textures/game3.jpg");

    field1.loadFromFile("textures/etap1.png");
    field2.loadFromFile("textures/etap2.png");
    field3.loadFromFile("textures/etap3.png");
    field4.loadFromFile("textures/etap4.png");


    fieldsprite.setTexture(field);
    hearttexture.loadFromFile("textures/heart.png");
    heartsprite.setTexture(hearttexture);
    heartsprite.setPosition(70,10);
    font.loadFromFile("fonts/montague.ttf");
    points.setFont(font);
    points.setCharacterSize(90);
    points.setOutlineColor(sf::Color::Black);
    points.setOutlineThickness(5);
    points.setPosition(5,height-95);
    lives.setFont(font);
    lives.setCharacterSize(40);
    lives.setOutlineColor(sf::Color::Black);
    lives.setPosition(0,0);


}
Field::~Field()
{

}
void Field::intToStringPoints(int *intvar)
{

    std:: ostringstream temp;
    temp<<*intvar;
    str=temp.str();

}

void Field::setTexture(int choice)
{


    switch(choice)
    {
        case 1:fieldsprite.setTexture(field1);
        break;
        case 2:fieldsprite.setTexture(field2);
        break;
        case 3:fieldsprite.setTexture(field3);
        break;
        case 4:fieldsprite.setTexture(field4);
    }

}

void Field::draw(sf::RenderWindow &window, bool trafiony,int *positionforEv, int *score,int *fail)
{

    randShape.setPosition(positionforEv[0],positionforEv[1]);
    window.draw(fieldsprite);
    window.draw(heartsprite);


    if(trafiony)
    {
        window.draw(randShape);
        trafiony = false;
    }

    x = 3 - *fail;
    intToStringPoints(score);
    points.setString(str);
    window.draw(points);
    intToStringPoints(&x);
    lives.setString(" "+str+"X");
    window.draw(lives);
}
