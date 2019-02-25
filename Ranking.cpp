#include "Ranking.h"




int::ranking::setPositioninRank(struct ranking *player)
{


    string textinfile;
    fstream file;
    int counter=0;
    int i=0;
    file.open( "ranking.txt", ios::in | ios::out );
    if( file.good() == true )
    {

        while(file.good()&&i<10)
        {
            ++counter;
            getline(file, textinfile);

            if(counter%2)
            {
                player[i].id = textinfile;
            }
            else
            {
                string str = textinfile;
                int z;
                istringstream iss(str);
                iss >> z;
                player[i].points = z;
                ++i;
            }
        }
        file.close();


        player[10].id = id;
        player[10].points = points;

        for(i = 0; i<=10; i++)
        {
            for(int j = 0; j<=10; j++)
                if(player[i].points>player[j].points)
                    if(i!=j)
                    {
                        struct ranking tmp;
                        tmp.id = player[i].id;
                        tmp.points = player[i].points;
                        player[i].id = player[j].id;
                        player[i].points = player[j].points;
                        player[j].id=tmp.id;
                        player[j].points=tmp.points;
                    }
        }

    }
    else
    {
        cout<<"Blad otwarcia pliku";
        file.close();
        return -1;

    }
    return 0;
}



int saveRank(struct ranking *player)
{
    fstream file;

    int i;
    file.open( "ranking.txt", ios::in | ios::out);
    if( file.good() == true )
    {
        for(i=0; i<10; ++i)
        {
            file<<player[i].id<<endl;
            file<<player[i].points<<endl;
        }

        file.close();

    }
    else
    {
        cout<<"Blad otwarcia pliku";
        file.close();
        return -1;

    }

    return 0;
}


void addPlayer(int **score,string name)
{
    struct ranking players[11];

    for(int i = 0; i<10; i++)
    {
        players[i].id = "--------";
        players[i].points = 0;

    }
    struct ranking *newPlayer = new ranking;

    newPlayer->id = name;
    newPlayer->points = **score;
    newPlayer->setPositioninRank(players);
    saveRank(players);


    delete newPlayer;
}

void setRankTable(sf:: Text *playerRank,sf::RenderWindow &window)
{
     for(int i = 0; i<10; ++i)
     {
                            window.draw(playerRank[i]);
     }
}

int LoadTable(sf::Text *playerRank)
{
    struct ranking player[10];

    for(int i = 0; i<10; i++)
    {
        player[i].id = "---------";
        player[i].points = 0;

    }

    string textinfile;
    fstream file;
    int counter=0;
    int i=0;
    file.open( "ranking.txt", ios::in | ios::out );
    if( file.good() == true )
    {

        while(file.good()&&i<10)
        {
            ++counter;
            getline(file, textinfile);

            if(counter%2)
            {
                if(textinfile.length()<1)
                    textinfile = "---------";

                player[i].id = textinfile;
            }
            else
            {
                string str = textinfile;
                int z;
                istringstream iss(str);
                iss >> z;
                player[i].points = z;
                ++i;
            }
        }
        file.close();

        for(i = 0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
                if(player[i].points>player[j].points)
                    if(i!=j)
                    {
                        struct ranking tmp;
                        tmp.id = player[i].id;
                        tmp.points = player[i].points;
                        player[i].id = player[j].id;
                        player[i].points = player[j].points;
                        player[j].id=tmp.id;
                        player[j].points=tmp.points;
                    }
        }

    }
    else
    {
        cout<<"Blad otwarcia pliku";
        file.close();
        return -1;

    }
    string str;
    for(i = 0; i<10;++i)
    {
        ostringstream temp;
        temp<<player[i].points;
        str=temp.str();
        playerRank[i].setString(player[i].id+" - "+str+" points");
    }

    return 0;
}


