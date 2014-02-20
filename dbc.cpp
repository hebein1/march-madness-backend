#include <sqlite3.h>
#include "dbc.h"



/**
 * retrieveGames
 * Returns a list of all games from the database in a C++ readable format 
 */
std::list<Game> retrieveGames()
{
    std::list<Game> gameRecords;
    sqlite3 * db;
    sqlite3_stmt * stmt;

    sqlite3_open("test.db", &db);
    sqlite3_prepare(db, "SELECT * FROM Games", -1, &stmt, NULL);

    int result = sqlite3_step(stmt);
    while (result == SQLITE_ROW)
    {
        std::string teamA((const char *) sqlite3_column_text(stmt, 0));
        std::string teamB((const char *) sqlite3_column_text(stmt, 1));
        int teamAScore(sqlite3_column_int(stmt, 2));
        int teamBScore(sqlite3_column_int(stmt, 3));
        std::string date((const char *) sqlite3_column_text(stmt, 4));
        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 2);
        std::string day = date.substr(8, 2);

        struct Game toBeAdded(teamA, teamB, teamAScore, teamBScore, year, month, day);
        gameRecords.push_back(toBeAdded);

        result = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return gameRecords;
}
