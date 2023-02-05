#pragma once

#include <string>
#include <vector>
#include <utility>
#include "geo.h"
#include "random_busstop_names.h"
#include "random_positions.h"

namespace kapt0xa
{

	struct Stop
	{
		string name;
		geo::Coordinates pos;
	};

	using Stops = vector<Stop>;
	Stops CombineNameAndPos(size_t count, const strings& names, const Positions& poss);
}