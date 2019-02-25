#include <SFML/Graphics.hpp>

class Racket
{
private:

    sf::Texture texture;
    sf::Sprite rectangle;
    int boostracket;



public:
    Racket(int pos_x, int pos_y, int racket_width, int racket_height);
    ~Racket();
    int draw(sf::RenderWindow &window);
    void move(int x, int screenHeight);
    void setPlayerRacket();
    void setComputerRacket();
    void followBall(int *y, int speedx, int lvl);
    void followBallPlayerToTest(int *y);
};
