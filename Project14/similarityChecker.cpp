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

	double checkLength(const string& guess)
	{
		if (guess.size() == target.size()) return MaxLengthScore;

		return getLengthScore(guess);
	}

private:
	double getLengthScore(const string& guess)
	{
		double small = 0;
		double gap = 0;
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

		return (double)(MaxLengthScore * (small - gap) / small);
	}

	string target;

};