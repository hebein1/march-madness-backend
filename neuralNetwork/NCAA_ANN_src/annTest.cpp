#include <iostream>
#include "ncaa_train.h"
#include "gtest/gtest.h"

TEST(ANN, checkNetworkCreation)
{
	ASSERT_TRUE(createNetwork(3, 2, 4, 1));
}
