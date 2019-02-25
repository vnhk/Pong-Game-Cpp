#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;



struct ranking
{
    string id;
    int points;
    int setPositioninRank(struct ranking *player);
};


int saveRank(struct ranking *player);

void addPlayer(int **score,string name);

void setRankTable(sf::Text *playerRank,sf::RenderWindow &window);

int LoadTable(sf::Text *playerRank);
