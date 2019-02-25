#include "textEntered.h"


std::string chooseNick()
{
    std::size_t maxTextLength = 8;

    std::string nick;
    sf::Text text;


    sf::Font font;
    font.loadFromFile("fonts/montague.ttf");

    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(10, 10);

    sf::RenderWindow window(sf::VideoMode(300, 80), "Choose nickname:", sf::Style::Titlebar);
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
            {
                window.close();
                if(nick.length()<2)
                    return "Player";
                else
                    return nick;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                sf::Uint32 unicode = event.text.unicode;

                if (unicode == 8 && nick.size() > 0)
                {
                    nick.erase(nick.size() - 1, 1);
                    text.setString(nick);
                }

                else if (((unicode >= 65 && unicode <= 90) ||
                          (unicode >= 97 && unicode <= 122)) && nick.size() < maxTextLength)
                {
                    nick += static_cast<char>(unicode);
                    text.setString(nick);
                }
            }

        }
        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    if(nick.length()<2)
        return "Player";
    else
        return nick;


}
