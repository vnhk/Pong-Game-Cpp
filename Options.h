#include <SFML/Graphics.hpp>
#include <fstream>

int loadOptions(std::string **content);
void optionsDraw(sf::RenderWindow &window,int n,sf::Text *text);
void textsetting(sf::Text *optionsGame, int numberoptions);
void saveToFile(std::string *content, int options);
std::string loadBall(std::string *content);

class Option
{
    private:
    std::string value;
    public:
       void chooseOption();
       std::string loadOption(std::string *content,int options);


};
