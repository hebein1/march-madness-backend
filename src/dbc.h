#ifndef DBC_H 
#define DBC_H

#include <list>
#include <string>
#include <sqlite3.h>

struct Game {
    std::string teamA;
    std::string teamB;
    unsigned int scoreA;
    unsigned int scoreB;
    std::string year;
    std::string month;
    std::string day;    
    bool teamAHome;
    bool teamBHome;

    Game(std::string teamA, std::string teamB, unsigned int scoreA,
        unsigned int scoreB, std::string year, std::string month, std::string day,
        bool teamAHome, bool teamBHome):
        teamA(teamA), teamB(teamB), scoreA(scoreA), scoreB(scoreB), year(year), 
        month(month), day(day), teamAHome(teamAHome), teamBHome(teamBHome) {}
};

class DBC{
    public:
        DBC();
        DBC(std::string dbfile);
        ~DBC();
        std::list<Game> retrieveGames();
        void addGame(std::string teamA, std::string teamB, int teamAScore, int teamBScore, bool teamAHome, bool teamBHome);

        void writeC5(std::string filename);
        void writeANN(std::string filename);
        void readESPN(std::string filename);

        void clearDB();
   private:
        sqlite3 * db;
};


#endif
