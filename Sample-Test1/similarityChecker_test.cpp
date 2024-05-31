#include "pch.h"
#include <vector>
#include <string>
#include "../Project14/similarityChecker.cpp"

using namespace std;

class CheckerFixture : public testing::Test {
public:
	SimilarityChecker checker{ "ABCDE" };
};


TEST_F(CheckerFixture, LengthTestSameLength) {
	string guess = "DEFGY";
	
	int ret = checker.checkLength(guess);
	EXPECT_EQ(ret, 60);
}

TEST_F(CheckerFixture, LengthTestDoubleGap) {
	string guess = "B";

	int ret = checker.checkLength(guess);
	EXPECT_EQ(ret, 0);
}

TEST_F(CheckerFixture, LengthTestPartial) {
	string guess = "ABC";

	int ret = checker.checkLength(guess);
	EXPECT_EQ(ret, 20);
}