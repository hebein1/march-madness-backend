#ifndef DBC_H 
#define DBC_H

#include <list>
#include <string>

struct Game {
    std::string teamA;
    std::string teamB;
    unsigned int scoreA;
    unsigned int scoreB;
    std::string year;
    std::string month;
    std::string day;    

    Game(std::string teamA, std::string teamB, unsigned int scoreA,
        unsigned int scoreB, std::string year, std::string month, std::string day):
        teamA(teamA), teamB(teamB), scoreA(scoreA), scoreB(scoreB), year(year), 
        month(month), day(day) {}
};

std::list<Game> retrieveGames();

#endif
