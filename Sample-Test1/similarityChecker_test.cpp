#include "pch.h"
#include <vector>
#include <string>
#include "../Project14/similarityChecker.cpp"

using namespace std;

class CheckerFixture : public testing::Test {
public:
	SimilarityChecker checker{ "ABCDEFGH" };
};


TEST_F(CheckerFixture, LengthTestSameLength) {
	string guess = "ABCDEFGH";
	
	EXPECT_EQ(checker.checkLength(guess), 60);
}

TEST_F(CheckerFixture, LengthTestDoubleGap) {
	string guess = "B";

	EXPECT_EQ(checker.checkLength(guess), 0);
}

TEST_F(CheckerFixture, LengthTestPartial) {
	string guess = "ABCDEF";

	EXPECT_EQ(checker.checkLength(guess), 40);
}