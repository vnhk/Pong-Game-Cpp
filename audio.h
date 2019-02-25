#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Music
{
private:
    sf::Music music;
    sf::Text credits;
    sf::Font font;

public:
    Music();
    ~Music();
    void musicPlay();
    void musicChoice(std::string *n);
    void musicStop();
    void musicVolume(int n);
    void drawCredits(sf::RenderWindow &window);
} ;


