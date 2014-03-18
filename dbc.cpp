#include "dbc.h"
#include <fstream>
#include <iostream>

DBC::DBC()
{
    sqlite3_open("development.sqlite3", &db);

}

DBC::DBC(std::string dbfile)
{
    sqlite3_open(dbfile.c_str(), &db);
}

DBC::~DBC()
{
    sqlite3_close(db);
}

/**
 * retrieveGames
 * Returns a list of all games from the database in a C++ readable format 
 */
std::list<Game> DBC::retrieveGames()
{
    std::list<Game> gameRecords;
    sqlite3_stmt * stmt;

    sqlite3_prepare(db, "SELECT * FROM games", -1, &stmt, NULL);

    int result = sqlite3_step(stmt);
    while (result == SQLITE_ROW)
    {
        std::string homeTeam((const char *) sqlite3_column_text(stmt, 3));
        std::string awayTeam((const char *) sqlite3_column_text(stmt, 4));

        int columncount = 5;
        float homePoints(sqlite3_column_double(stmt, columncount++));
        float homefgm(sqlite3_column_double(stmt, columncount++));
        float homefga(sqlite3_column_double(stmt, columncount++));
        float homefgPer(sqlite3_column_double(stmt, columncount++));
        float hometwoMade(sqlite3_column_double(stmt, columncount++));
        float hometwoAtt(sqlite3_column_double(stmt, columncount++));
        float hometwoPer(sqlite3_column_double(stmt, columncount++));
        float homethreeMade(sqlite3_column_double(stmt, columncount++));
        float homethreeAtt(sqlite3_column_double(stmt, columncount++));
        float homethreePer(sqlite3_column_double(stmt, columncount++));
        float homeftm(sqlite3_column_double(stmt, columncount++));
        float homefta(sqlite3_column_double(stmt, columncount++));
        float homeftPer(sqlite3_column_double(stmt, columncount++));
        float homeoffReb(sqlite3_column_double(stmt, columncount++));
        float homedefReb(sqlite3_column_double(stmt, columncount++));
        float hometotalReb(sqlite3_column_double(stmt, columncount++));
        float homepps(sqlite3_column_double(stmt, columncount++));
        float homeadjFG(sqlite3_column_double(stmt, columncount++));
        float homeassist(sqlite3_column_double(stmt, columncount++));
        float hometo(sqlite3_column_double(stmt, columncount++));
        float homeapto(sqlite3_column_double(stmt, columncount++));
        float homesteals(sqlite3_column_double(stmt, columncount++));
        float homefouls(sqlite3_column_double(stmt, columncount++));
        float homestealPerTO(sqlite3_column_double(stmt, columncount++));
        float homestealPerFoul(sqlite3_column_double(stmt, columncount++));
        float homeblocks(sqlite3_column_double(stmt, columncount++));
        float homeblocksPerFoul(sqlite3_column_double(stmt, columncount++));
        float awaypoints(sqlite3_column_double(stmt, columncount++));
        float awayfgm(sqlite3_column_double(stmt, columncount++));
        float awayfga(sqlite3_column_double(stmt, columncount++));
        float awayfgPer(sqlite3_column_double(stmt, columncount++));
        float awaytwoMade(sqlite3_column_double(stmt, columncount++));
        float awaytwoAtt(sqlite3_column_double(stmt, columncount++));
        float awaytwoPer(sqlite3_column_double(stmt, columncount++));
        float awaythreeMade(sqlite3_column_double(stmt, columncount++));
        float awaythreeAtt(sqlite3_column_double(stmt, columncount++));
        float awaythreePer(sqlite3_column_double(stmt, columncount++));
        float awayftm(sqlite3_column_double(stmt, columncount++));
        float awayfta(sqlite3_column_double(stmt, columncount++));
        float awayftPer(sqlite3_column_double(stmt, columncount++));
        float awayoffReb(sqlite3_column_double(stmt, columncount++));
        float awaydefReb(sqlite3_column_double(stmt, columncount++));
        float awaytotalReb(sqlite3_column_double(stmt, columncount++));
        float awaypps(sqlite3_column_double(stmt, columncount++));
        float awayadjFG(sqlite3_column_double(stmt, columncount++));
        float awayassist(sqlite3_column_double(stmt, columncount++));
        float awayto(sqlite3_column_double(stmt, columncount++));
        float awayapto(sqlite3_column_double(stmt, columncount++));
        float awaysteals(sqlite3_column_double(stmt, columncount++));
        float awayfouls(sqlite3_column_double(stmt, columncount++));
        float awaystealPerTO(sqlite3_column_double(stmt, columncount++));
        float awaystealPerFoul(sqlite3_column_double(stmt, columncount++));
        float awayblocks(sqlite3_column_double(stmt, columncount++));
        float awayblocksPerFoul(sqlite3_column_double(stmt, columncount++));


        Game toBeAdded(homeTeam, awayTeam, homePoints, homefgm, homefga, homefgPer, hometwoMade, hometwoAtt, hometwoPer, homethreeMade, homethreeAtt, homethreePer, homeftm, homefta, homeftPer, homeoffReb, homedefReb, hometotalReb, homepps, homeadjFG, homeassist, hometo, homeapto, homesteals, homefouls, homestealPerTO, homestealPerFoul, homeblocks, homeblocksPerFoul, awaypoints, awayfgm, awayfga, awayfgPer, awaytwoMade, awaytwoAtt, awaytwoPer, awaythreeMade, awaythreeAtt, awaythreePer, awayftm, awayfta, awayftPer, awayoffReb, awaydefReb, awaytotalReb, awaypps, awayadjFG, awayassist, awayto, awayapto, awaysteals, awayfouls, awaystealPerTO, awaystealPerFoul, awayblocks, awayblocksPerFoul);
        gameRecords.push_back(toBeAdded);

        result = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);

    return gameRecords;
}

/**
 * retrieveTeams
 * Returns a list of all teams from the database in a C++ readable format 
 */
std::list<Team> DBC::retrieveTeams()
{
    std::list<Team> teamRecords;
    sqlite3_stmt * stmt;

    sqlite3_prepare(db, "SELECT * FROM teams", -1, &stmt, NULL);

    int result = sqlite3_step(stmt);
    while (result == SQLITE_ROW)
    {
        std::string name((const char *) sqlite3_column_text(stmt, 1));

        int columncount = 9;
        float fgm(sqlite3_column_double(stmt, columncount++));
        float fga(sqlite3_column_double(stmt, columncount++));
        float fgPer(sqlite3_column_double(stmt, columncount++));
        float twoMade(sqlite3_column_double(stmt, columncount++));
        float twoAtt(sqlite3_column_double(stmt, columncount++));
        float twoPer(sqlite3_column_double(stmt, columncount++));
        float threeMade(sqlite3_column_double(stmt, columncount++));
        float threeAtt(sqlite3_column_double(stmt, columncount++));
        float threePer(sqlite3_column_double(stmt, columncount++));
        float ftm(sqlite3_column_double(stmt, columncount++));
        float fta(sqlite3_column_double(stmt, columncount++));
        float ftPer(sqlite3_column_double(stmt, columncount++));
        float offReb(sqlite3_column_double(stmt, columncount++));
        float defReb(sqlite3_column_double(stmt, columncount++));
        float totalReb(sqlite3_column_double(stmt, columncount++));
        float pps(sqlite3_column_double(stmt, columncount++));
        float adjFG(sqlite3_column_double(stmt, columncount++));
        float assist(sqlite3_column_double(stmt, columncount++));
        float to(sqlite3_column_double(stmt, columncount++));
        float apto(sqlite3_column_double(stmt, columncount++));
        float steals(sqlite3_column_double(stmt, columncount++));
        float fouls(sqlite3_column_double(stmt, columncount++));
        float stealPerTO(sqlite3_column_double(stmt, columncount++));
        float stealPerFoul(sqlite3_column_double(stmt, columncount++));
        float blocks(sqlite3_column_double(stmt, columncount++));
        float blocksPerFoul(sqlite3_column_double(stmt, columncount++));

        Team toBeAdded(name, fgm, fga, fgPer, twoMade, twoAtt, twoPer, threeMade, threeAtt, threePer, ftm, fta, ftPer, offReb, defReb, totalReb, pps, adjFG, assist, to, apto, steals, fouls, stealPerTO, stealPerFoul, blocks, blocksPerFoul);

        if (fgm != 0)
            teamRecords.push_back(toBeAdded);

        result = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);

    return teamRecords;
}

/**
 * Write the contents of the games db table to a file usable by the C5 algo.
 */
void DBC::writeC5(std::string filename)
{
    std::ofstream cfile(filename.c_str());
    std::list <Game> gameHistory = retrieveGames();
    for(auto it = gameHistory.begin(); it != gameHistory.end(); it++)
    {
        cfile << it -> homefgm << "," << it -> homefga << "," << it -> homefgPer << "," << it -> hometwoMade << "," << it -> hometwoAtt << "," << it -> hometwoPer << "," << it -> homethreeMade << "," << it -> homethreeAtt << "," << it -> homethreePer << "," << it -> homeftm << "," << it -> homefta << "," << it -> homeftPer << "," << it -> homeoffReb << "," << it -> homedefReb << "," << it -> hometotalReb << "," << it -> homepps << "," << it -> homeadjFG << "," << it -> homeassist << "," << it -> hometo << "," << it -> homeapto << "," << it -> homesteals << "," << it -> homefouls << "," << it -> homestealPerTO << "," << it -> homestealPerFoul << "," << it -> homeblocks << "," << it -> homeblocksPerFoul << ",";
        cfile << it -> awayfgm << "," << it -> awayfga << "," << it -> awayfgPer << "," << it -> awaytwoMade << "," << it -> awaytwoAtt << "," << it -> awaytwoPer << "," << it -> awaythreeMade << "," << it -> awaythreeAtt << "," << it -> awaythreePer << "," << it -> awayftm << "," << it -> awayfta << "," << it -> awayftPer << "," << it -> awayoffReb << "," << it -> awaydefReb << "," << it -> awaytotalReb << "," << it -> awaypps << "," << it -> awayadjFG << "," << it -> awayassist << "," << it -> awayto << "," << it -> awayapto << "," << it -> awaysteals << "," << it -> awayfouls << "," << it -> awaystealPerTO << "," << it -> awaystealPerFoul << "," << it -> awayblocks << "," << it -> awayblocksPerFoul << ",";  
        if (it -> homePoints >= it -> awaypoints)
            cfile << "A\n";
        else
            cfile << "B\n";
    }
    cfile.close();

}

/**
 * Write the contents of the teams db table to a file usable by the C5 algo.
 */
void DBC::writeC5Teams(std::string filename)
{
    std::ofstream cfile(filename.c_str());
    std::list <Team> teams = retrieveTeams();
    for(auto it = teams.begin(); it != teams.end(); it++)
    {
        cfile << it -> name << "," << it -> fgm << "," << it -> fga << "," << it -> fgPer << "," << it -> twoMade << "," << it -> twoAtt << "," << it -> twoPer << "," << it -> threeMade << "," << it -> threeAtt << "," << it -> threePer << "," << it -> ftm << "," << it -> fta << "," << it -> ftPer << "," << it -> offReb << "," << it -> defReb << "," << it -> totalReb << "," << it -> pps << "," << it -> adjFG << "," << it -> assist << "," << it -> to << "," << it -> apto << "," << it -> steals << "," << it -> fouls << "," << it -> stealPerTO << "," << it -> stealPerFoul << "," << it -> blocks << "," << it -> blocksPerFoul << "\n";
    }
    cfile.close();

}

/**
 * Write the contents of the games db table to a file usable by the ANN algo.
 */
void DBC::writeANN(std::string filename)
{
    std::ofstream afile(filename.c_str());
    std::list<Game> gameHistory = retrieveGames();

    afile << gameHistory.size() << " 52 1\n";
    for(auto it = gameHistory.begin(); it != gameHistory.end(); it++)
    {
        afile << it -> homefgm << " " << it -> homefga << " " << it -> homefgPer << " " << it -> hometwoMade << " " << it -> hometwoAtt << " " << it -> hometwoPer << " " << it -> homethreeMade << " " << it -> homethreeAtt << " " << it -> homethreePer << " " << it -> homeftm << " " << it -> homefta << " " << it -> homeftPer << " " << it -> homeoffReb << " " << it -> homedefReb << " " << it -> hometotalReb << " " << it -> homepps << " " << it -> homeadjFG << " " << it -> homeassist << " " << it -> hometo << " " << it -> homeapto << " " << it -> homesteals << " " << it -> homefouls << " " << it -> homestealPerTO << " " << it -> homestealPerFoul << " " << it -> homeblocks << " " << it -> homeblocksPerFoul << " ";
        afile << it -> awayfgm << " " << it -> awayfga << " " << it -> awayfgPer << " " << it -> awaytwoMade << " " << it -> awaytwoAtt << " " << it -> awaytwoPer << " " << it -> awaythreeMade << " " << it -> awaythreeAtt << " " << it -> awaythreePer << " " << it -> awayftm << " " << it -> awayfta << " " << it -> awayftPer << " " << it -> awayoffReb << " " << it -> awaydefReb << " " << it -> awaytotalReb << " " << it -> awaypps << " " << it -> awayadjFG << " " << it -> awayassist << " " << it -> awayto << " " << it -> awayapto << " " << it -> awaysteals << " " << it -> awayfouls << " " << it -> awaystealPerTO << " " << it -> awaystealPerFoul << " " << it -> awayblocks << " " << it -> awayblocksPerFoul << "\n";  
        if (it -> homePoints >= it -> awaypoints)
            afile << 1;
        else
            afile << 0;
        afile << "\n";
    }
    afile.close();
}

/**
 * Write the contents of the teams db table to a file usable by the ANN algo.
 */
void DBC::writeANNTeams(std::string filename)
{
    std::ofstream afile(filename.c_str());
    std::list <Team> teams = retrieveTeams();
    for(auto it = teams.begin(); it != teams.end(); it++)
    {
        afile << it -> name << "\n";
        afile  << it -> fgm << " " << it -> fga << " " << it -> fgPer << " " << it -> twoMade << " " << it -> twoAtt << " " << it -> twoPer << " " << it -> threeMade << " " << it -> threeAtt << " " << it -> threePer << " " << it -> ftm << " " << it -> fta << " " << it -> ftPer << " " << it -> offReb << " " << it -> defReb << " " << it -> totalReb << " " << it -> pps << " " << it -> adjFG << " " << it -> assist << " " << it -> to << " " << it -> apto << " " << it -> steals << " " << it -> fouls << " " << it -> stealPerTO << " " << it -> stealPerFoul << " " << it -> blocks << " " << it -> blocksPerFoul << "\n";
    }
    afile.close();

}

