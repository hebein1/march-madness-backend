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
    DBC db;
    std::list<Game> gameRecords = db.retrieveGames();
    std::list<Game>::iterator gameIt = gameRecords.begin();

    ASSERT_STREQ((gameIt -> teamA).c_str(), "Albany");
    ASSERT_STREQ((gameIt -> teamB).c_str(), "Siena");
    ASSERT_EQ(gameIt -> scoreA, 74);
    ASSERT_EQ(gameIt -> scoreB, 62);

    gameIt++;

    ASSERT_STREQ((gameIt -> teamA).c_str(), "Albany");
    ASSERT_STREQ((gameIt -> teamB).c_str(), "N.J.I.T.");
    ASSERT_EQ(gameIt -> scoreA, 71);
    ASSERT_EQ(gameIt -> scoreB, 65);

    gameIt++;

    ASSERT_STREQ((gameIt -> teamA).c_str(), "Albany");
    ASSERT_STREQ((gameIt -> teamB).c_str(), "Quinnipiac");
    ASSERT_EQ(gameIt -> scoreA, 69);
    ASSERT_EQ(gameIt -> scoreB, 79);
}

/**
 * NumberOfEntriesCheck
 * Verifies that we are only returning a list that is the length of the Games Table.
 */
TEST(Games, NumberOfEntriesCheck)
{
    DBC db;
    std::list<Game> gameRecords = db.retrieveGames();
    ASSERT_EQ(29, gameRecords.size());
}

/**
 * Tests we can programatically clear the database.
 */
TEST(DB, ClearDB)
{
    DBC db;
    db.clearDB();
    std::list<Game> gameRecords = db.retrieveGames();
    ASSERT_EQ(0, gameRecords.size());
    db.readESPN("sampleESPN.txt");
}

/**
 * Tests we can read data from text files generated from ESPN.
 */
TEST(DB, ReadESPN)
{
    DBC db;
    db.clearDB();
    db.readESPN("sampleESPN.txt");

    std::list<Game> gameRecords = db.retrieveGames();
    Game verifiedGame = gameRecords.front();
    ASSERT_STREQ(verifiedGame.teamA.c_str(), "Albany");
    ASSERT_STREQ(verifiedGame.teamB.c_str(), "Siena");
    ASSERT_EQ(verifiedGame.scoreA, 74);
    ASSERT_EQ(verifiedGame.scoreB, 62);
}

/**
 * Tests we can write out the ANN file from the DB.
 */
TEST(DB, WriteANN)
{
    DBC db;
    db.writeANN("testANN.txt");
    std::ifstream annfile("testANN.txt");
    std::string line;

    getline(annfile, line); 
    ASSERT_STREQ(line.c_str(), "29 2 1");

    getline(annfile, line);
    ASSERT_STREQ(line.c_str(), "74 62");

    getline(annfile, line);
    ASSERT_STREQ(line.c_str(), "1");

    annfile.close();

}

/**
 *  Tests we can write out the C5 file from the DB.
 */
TEST(DB, WriteC5)
{
    DBC db;
    db.writeC5("testC5.txt");
    std::ifstream c5file("testC5.txt");
    std::string line;

    getline(c5file, line); 
    ASSERT_STREQ(line.c_str(), "74,62,A"); 

    c5file.close();
}
