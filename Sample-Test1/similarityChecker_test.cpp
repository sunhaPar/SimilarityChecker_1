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

TEST_F(CheckerFixture, AlphaTestSame) {
	string guess = "ABCDEFGH";

	EXPECT_EQ(checker.checkAlpha(guess), 40);
}


TEST_F(CheckerFixture, AlphaTestPatial) {
	string guess = "HAEDFG";

	EXPECT_EQ(checker.checkAlpha(guess), 30);
}

TEST_F(CheckerFixture, AlphaTestZero) {
	string guess = "ZZZZZ";

	EXPECT_EQ(checker.checkAlpha(guess), 0);
}


TEST_F(CheckerFixture, AlphaTestTotal1) {
	string guess = "ABCDEFGH";

	EXPECT_EQ(checker.checkAlpha(guess) + checker.checkLength(guess), 100);
}


TEST_F(CheckerFixture, AlphaTestTotal2) {
	string guess = "A";

	EXPECT_EQ(checker.checkAlpha(guess) + checker.checkLength(guess), 5);
}