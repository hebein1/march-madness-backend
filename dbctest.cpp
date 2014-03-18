#include "dbc.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>

/**
 * EntryCheck
 * Verifies that we are retrieving the correct data from the Games Table.
 */
TEST(Games, EntryCheck)
{
    DBC db("gamesTest.db");
    std::list<Game> gameRecords = db.retrieveGames();

    Game testGame = gameRecords.front();

    ASSERT_EQ(testGame.homefgm, 20);
    ASSERT_EQ(testGame.homefga, 51);
    ASSERT_EQ(testGame.awayfgm, 24);
    ASSERT_EQ(testGame.awayfga, 52);
}

/**
 * NumberOfEntriesCheck
 * Verifies that we are only returning a list that is the length of the Games Table.
 */
TEST(Games, NumberOfEntriesCheck)
{
    DBC db("gamesTest.db");
    std::list<Game> gameRecords = db.retrieveGames();
    ASSERT_EQ(88, gameRecords.size());
}

/**
 * EntryCheck
 * Verifies that we are retrieving the correct data from the Teams Table.
 */
TEST(Teams, EntryCheck)
{
    DBC db("teamsTest.db");
    std::list<Team> teamRecords = db.retrieveTeams();
    
    Team testTeam = teamRecords.front();

    ASSERT_STREQ(testTeam.name.c_str(), "Vermont");
    ASSERT_EQ((int) testTeam.fgm, (int) 23.0);
    ASSERT_EQ((int) testTeam.blocksPerFoul, (int) 4.28);
}

/**
 * NumberOfEntriesCheck
 * Verifies that we are only returning a list that is the length of the Teams Table.
 */
TEST(Teams, NumberOfEntriesCheck)
{
    DBC db("teamsTest.db");
    std::list<Team> teamRecords = db.retrieveTeams();
    ASSERT_EQ(351, teamRecords.size());
}

/**
 * Tests we can write out the ANN game & teams files from the DB.
 */
TEST(DB, WriteANN)
{
    DBC teamsdb("teamsTest.db");
    DBC gamesdb("gamesTest.db");

    gamesdb.writeANN("ANNGames.txt");
    teamsdb.writeANNTeams("ANNTeams.txt");

    std::ifstream gamesFile("ANNGames.txt");
    std::ifstream teamsFile("ANNTeams.txt");
    std::string line;

    getline(gamesFile, line);
    ASSERT_STREQ(line.c_str(), "88 52 1");

    getline(gamesFile, line);
    ASSERT_STREQ(line.c_str(), "20 51 0.392157 16 34 0.470588 4 17 0.235294 20 29 0.689655 6 22 28 1.2549 0.431373 11 9 1.22222 6 26 0.666667 0.230769 7 0.269231 24 52 0.461538 18 36 0.5 6 16 0.375 20 30 0.666667 11 30 41 1.42308 0.519231 10 14 0.714286 3 22 0.214286 0.136364 4 0.181818");

    getline(gamesFile, line);
    ASSERT_STREQ(line.c_str(), "0");

    getline(teamsFile, line);
    ASSERT_STREQ(line.c_str(), "Vermont");

    getline(teamsFile, line);
    ASSERT_STREQ(line.c_str(), "23 50 0.469 18 36 0.498 5 14 0.399 17 24 0.731 10 24.8 34.8 1.4 0.527 13 11.9 1.09 7 0 18.5625 0.59 0.38 4.28");

    gamesFile.close();
    teamsFile.close();

}

/**
 *  Tests we can write out the C5 game & teams files from the DB.
 */
TEST(DB, WriteC5)
{
    DBC teamsdb("teamsTest.db");
    DBC gamesdb("gamesTest.db");

    gamesdb.writeC5("C5Games.txt");
    teamsdb.writeC5Teams("C5Teams.txt");

    std::ifstream gamesFile("C5Games.txt");
    std::ifstream teamsFile("C5Teams.txt");
    std::string line;

    getline(gamesFile, line);
    ASSERT_STREQ(line.c_str(), "20,51,0.392157,16,34,0.470588,4,17,0.235294,20,29,0.689655,6,22,28,1.2549,0.431373,11,9,1.22222,6,26,0.666667,0.230769,7,0.269231,24,52,0.461538,18,36,0.5,6,16,0.375,20,30,0.666667,11,30,41,1.42308,0.519231,10,14,0.714286,3,22,0.214286,0.136364,4,0.181818,B");

    getline(teamsFile, line);
    ASSERT_STREQ(line.c_str(), "Vermont,23,50,0.469,18,36,0.498,5,14,0.399,17,24,0.731,10,24.8,34.8,1.4,0.527,13,11.9,1.09,7,0,18.5625,0.59,0.38,4.28");

    gamesFile.close();
    teamsFile.close();
}
