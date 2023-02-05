#include "random_stops.h"
#include <numeric>
#include <iterator>

using namespace std;

namespace kapt0xa
{
	Stops CombineNameAndPos(size_t count, const strings& names, const Positions& poss)
	{
		assert(names.size() >= count && poss.size() >= count);
		Stops result;
		result.reserve(count);
		transform(names.begin(), names.begin() + count, poss.begin(), back_inserter(result));
		return result;
	}
}
