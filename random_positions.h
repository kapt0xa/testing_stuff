#pragma once
#include "my_random.h"
#include <vector>
#include <cmath>

namespace kapt0xa
{
	double RandomLatitude(Randomizer& randomizer = default_randomizer);
	double RandomLongitude(Randomizer& randomizer = default_randomizer);

	struct Position
	{
		double lat;
		double lng;
	};
	using Positions = std::vector<Position>;

	Position RandomPosition(Randomizer& randomizer = default_randomizer);
	Positions RandomPositions(size_t count, Randomizer& randomizer = default_randomizer);

}