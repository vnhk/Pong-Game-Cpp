#include "Options.h"

int loadOptions(std::string **content)
{
    std::string options;
    std::fstream file;
    file.open( "options.txt", std::ios::in | std::ios::out );

    if( file.good() == true )
    {

        while(file.good())
        {
            getline(file,**content);
            break;
        }
        file.close();
        return 0;
    }
    return -1;

}

std::string Option::loadOption(std::string *content,int options)
 {
    value = content[options-1]=="1"?"ON":"OFF";

   return value;
 }

 void saveToFile(std::string *content,int options)
 {
    std::fstream file;
    std::string tofile ="";

    for(int i = 0 ;i < options; ++i)
        tofile+=content[i];

    file.open( "options.txt",  std::ios::in | std::ios::out);

    if( file.good() == true )
    {

        file<<tofile;
        file.close();

    }
    else file.close();

 }

 void optionsDraw(sf::RenderWindow &window,int n,sf::Text *text)
{

    for(int i = 0; i < n; ++i)
        window.draw(text[i]);
}

void textsetting(sf::Text *optionsGame, int numberoptions)
{
     for(int i = 0; i<numberoptions; i++)
     {
        optionsGame[i].setCharacterSize(50);
        optionsGame[i].setFillColor(sf::Color::White);
        optionsGame[i].setOutlineThickness(5);
        optionsGame[i].setPosition(25,i*50);
     }
}

std::string loadBall(std::string *content)
{
    if(content[3]=="1"||content[3]=="2"||content[3]=="3"||content[3]=="4"||content[3]=="5")
        return "textures/ball"+content[3]+".png";
    else return "textures/ball3.png";
}




