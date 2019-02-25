#include <SFML/Graphics.hpp>
#include <sstream>

class Field
{
private:

    sf::Texture textureRandShape;
    sf::Sprite randShape;
    sf::Texture field;
    sf::Texture field1;
    sf::Texture field2;
    sf::Texture field3;
    sf::Texture field4;
    sf::Sprite fieldsprite;
    sf::Texture hearttexture;
    sf::Sprite heartsprite;
    sf:: Text points;
    sf:: Text lives;
    sf::Font font;
    std:: string str;
    int x;


public:

    Field(int width,int height);
    ~Field();
    void draw(sf::RenderWindow &window, bool trafiony,int *positionforEv, int *score,int *fail);
    void intToStringPoints(int *intvar);
    void setTexture(int choice);

};
