#include "random_positions.h"
#include <sstream>
#include <cassert>

namespace kapt0xa
{
	using namespace std;
	double normalising_coefficient = 90. / asin(1);

	double RandomLatitude(Randomizer& randomizer)
	{
		double result = asin(RandomNum_safe(-1., 1., randomizer)) * normalising_coefficient;
		assert(result <= 90. && result >= -90.);
		return result;
	}

	double RandomLongitude(Randomizer& randomizer)
	{
		return RandomNum_safe(-180., 180., randomizer);
	}

	Position RandomPosition(Randomizer& randomizer)
	{
		return {RandomLatitude(randomizer), RandomLongitude(randomizer)};
	}

	Positions RandomPositions(size_t count, Randomizer& randomizer)
	{
		Positions result;

		result.reserve(count);
		while (result.size() < count)
		{
			result.push_back(RandomPosition(randomizer));
		}

		return result;
	}
}