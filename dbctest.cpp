#include "dbc.h"
#include "gtest/gtest.h"
#include <iostream>

/**
 * EntryCheck
 * Verifies that we are retrieving the correct data from the Games Table.
 */
TEST(Games, EntryCheck)
{
    std::list<Game> gameRecords = retrieveGames();
    std::list<Game>::iterator gameIt = gameRecords.begin();

    ASSERT_STREQ("Duke", (gameIt -> teamA).c_str());
    ASSERT_STREQ("Georgia Tech", (gameIt -> teamB).c_str());
    ASSERT_EQ(68, gameIt -> scoreA);
    ASSERT_EQ(51, gameIt -> scoreB);
    ASSERT_STREQ("2014", (gameIt -> year).c_str());
    ASSERT_STREQ("02", (gameIt -> month).c_str());
    ASSERT_STREQ("18", (gameIt -> day).c_str());

    gameIt++;

    ASSERT_STREQ("Texas", (gameIt -> teamA).c_str());
    ASSERT_STREQ("Iowa State", (gameIt -> teamB).c_str());
    ASSERT_EQ(76, gameIt -> scoreA);
    ASSERT_EQ(85, gameIt -> scoreB);
    ASSERT_STREQ("2014", (gameIt -> year).c_str());
    ASSERT_STREQ("02", (gameIt -> month).c_str());
    ASSERT_STREQ("18", (gameIt -> day).c_str());

    gameIt++;

    ASSERT_STREQ("Virginia", (gameIt -> teamA).c_str());
    ASSERT_STREQ("Virginia Tech", (gameIt -> teamB).c_str());
    ASSERT_EQ(57, gameIt -> scoreA);
    ASSERT_EQ(53, gameIt -> scoreB);
    ASSERT_STREQ("2014", (gameIt -> year).c_str());
    ASSERT_STREQ("02", (gameIt -> month).c_str());
    ASSERT_STREQ("18", (gameIt -> day).c_str());
}

/**
 * NumberOfEntriesCheck
 * Verifies that we are only returning a list that is the length of the Games Table.
 */
TEST(Games, NumberOfEntriesCheck)
{
    std::list<Game> gameRecords = retrieveGames();
    ASSERT_EQ(3, gameRecords.size());
}
