#pragma once
#include "my_random.h"
#include "geo.h"
#include <vector>
#include <string>
#include <cmath>
#include <utility>

namespace kapt0xa
{
	using std::string;
	using strings = std::vector<string>;

	double RandomLatitude(Randomizer& randomizer = default_randomizer);
	double RandomLongitude(Randomizer& randomizer = default_randomizer);

	using Position = geo::Coordinates;
	using Positions = std::vector<Position>;

	Position RandomPosition(Randomizer& randomizer = default_randomizer);
	Positions RandomPositions(size_t count, Randomizer& randomizer = default_randomizer);
}