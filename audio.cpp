#include "audio.h"

Music::Music()
{
    credits.setFont(font);
    credits.setCharacterSize(10);
    credits.setFillColor(sf::Color::White);
    credits.setOutlineThickness(5);
    credits.setPosition(900,585);
    font.loadFromFile("fonts/montague.ttf");

}
Music::~Music()
{

}
void Music::musicPlay()
{
    music.play();
    music.setLoop(true);
}
void Music::musicChoice(std::string *n)
{

    if(n[4]=="1")
   {
        music.openFromFile("music/Adventure Meme.ogg");
        credits.setString("Music: Adventure Meme - Kevin MacLeod");
   }

   else
   {
        music.openFromFile("music/To the Next Destination.ogg");
        credits.setString("Music: Techno Axe - To the Next Destination");
   }


}
void Music::musicStop()
{
    music.stop();
}
void Music::musicVolume(int n)
{
    music.setVolume(n);
}
void Music::drawCredits(sf::RenderWindow &window)
{
    window.draw(credits);
}
