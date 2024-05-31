#include <string>

using namespace std;

const int MaxLengthScore = 60;
const int MaxAlphaScore = 40;

class SimilarityChecker {
public:
	explicit SimilarityChecker(const string& target)
		:target(target)
	{

	}

	int checkLength(const string& guess)
	{
		if (guess.size() == target.size()) return MaxLengthScore;

		return getLenghScore(guess);
	}

private:
	int getLenghScore(const string& guess)
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

	string target;

};