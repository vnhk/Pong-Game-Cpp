#include <SFML/Graphics.hpp>



class Button
{
private:
    sf::Texture ButtonTexture;
    sf::Sprite ButtonSprite;

public:
    Button(int width,int height);
    ~Button();
    void draw(sf::RenderWindow &window);
    void setTexture(int choice);
   int getPositionx();
   int getPositiony();
};
