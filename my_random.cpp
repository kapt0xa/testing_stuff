#include "my_random.h"

namespace kapt0xa
{
	using std::max;
	using std::min;
	using std::accumulate;
	using std::any_of;

	Randomizer default_randomizer(std::time(0));

	size_t RandomNum(size_t from, size_t to, Randomizer& randomizer)
	{
		assert(from < to);
		size_t devider = to - from + 1;
		assert(devider != 0);
		return from + randomizer() % devider;
	}

	double RandomNum(double from, double to, Randomizer& randomizer)
	{
		assert(Randomizer::min() == 0);
		return (static_cast<double>(randomizer())/Randomizer::max()) * (to - from) + from;
	}

	double RandomNum_safe(double from, double to, Randomizer& randomizer)
	{
		assert(to >= from);
		double result = RandomNum(from, to, randomizer);
		result = max(result, from);
		result = min(result, to);
		return result;
	}
}