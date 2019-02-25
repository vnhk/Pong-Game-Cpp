#include <SFML/Graphics.hpp>


class Ball
{
private:

    sf::Texture texture;
    sf::Sprite ball;
    float speed;
    float speedx;
    float speedy;
    int racketSizex;
    int event;
    int eventlast;
    int ballsize;
    bool special[3];

public:
    Ball(sf::RenderWindow &window);
    ~Ball();
    void setPositionxy(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window, std::string choice);
    int moveball(int racket1pos,int racket2pos, bool *ctrl,int *ballposition,int **score,int *positionforEv,bool trafiony,int **fail,int *lvl);
};
