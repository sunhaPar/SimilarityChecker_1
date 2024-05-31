#include <string>

using namespace std;

const int MaxLengthScore = 60;
const int MaxAlphaScore = 40;

const int InitValue = 0;
const int TargetValue = 1;

class SimilarityChecker {
public:
	explicit SimilarityChecker(const string& target)
		:target(target)
	{
		memset(alpha, 0, sizeof(alpha));
		totalAlphaCnt = getAlphaCount(target, InitValue);		
	}

	int checkLength(const string& guess)
	{
		if (guess.size() == target.size()) return MaxLengthScore;

		return getLengthScore(guess);
	}

	int checkAlpha(const string& guess)
	{
		int sameCnt = getAlphaCount(guess, TargetValue);

		return  (MaxAlphaScore * sameCnt / totalAlphaCnt);
	}

private:
	int getLengthScore(const string& guess)
	{
		int small = 0;
		int gap = 0;
		if (guess.size() > target.size())
		{
			gap = guess.size() - target.size();
			small = target.size();
		}
		else
		{
			gap = target.size() - guess.size();
			small = guess.size();
		}

		if (gap >= small)   return 0;  //double Gap

		return (MaxLengthScore * (small - gap) / small);
	}

	int getAlphaCount(const string& str, int validValue)
	{
		int result = 0;
		for (char targetC : str)
		{
			if (alpha[targetC - 'A'] == validValue)
			{
				alpha[targetC - 'A'] ++;
				result++;
			}
		}
		return result;
	}

	string target;
	int alpha[26] = {};
	int totalAlphaCnt = 0;
};