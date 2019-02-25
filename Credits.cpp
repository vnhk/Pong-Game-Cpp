#include "Credits.h"


int creditsSize()
{

    int counter = 0;
    std::string content;
    std::fstream file;
    file.open( "credits.txt", std::ios::in | std::ios::out );

    if( file.good() == true )
    {

        while(file.good())
        {
            ++counter;
            getline(file,content);
        }
        file.close();

    }
    if(counter>0)
        return counter;
    else return 1;
}

void creditsDraw(sf::RenderWindow &window,int n,sf::Text *text)
{

    for(int i = 0; i < n; ++i)
        window.draw(text[i]);
}


void credits(sf::Text *text)
{
    std::string content;
    sf::Font font;
    font.loadFromFile("fonts/montague.ttf");

    int counter = 0;
    std::fstream file;
    file.open( "credits.txt", std::ios::in | std::ios::out );
    if( file.good() == true )
    {

        while(file.good())
        {
            ++counter;
            getline(file,content);
            if(content.length()<1)
            text[counter-1].setString("");
            else
            text[counter-1].setString(content);
        }
        file.close();

    }

}
