#pragma once

#include <random>
#include <ctime>
#include <vector>
#include <cassert>
#include <numeric>

namespace kapt0xa
{
	using Randomizer = std::mt19937_64;
	extern Randomizer default_randomizer;

	size_t RandomNum(size_t from, size_t to, Randomizer& randomizer);

	double RandomNum(double from, double to, Randomizer& randomizer);
	double RandomNum_safe(double from, double to, Randomizer& randomizer);

	template<typename Container>
	auto& RandomElement(Container& container, Randomizer& randomizer);

	template<typename Obj>
	struct ObjectAndProbabilityWeight
	{
		Obj obj;
		double weight;
	};

	template<typename Obj>
	using ChanceWeights = std::vector<ObjectAndProbabilityWeight<Obj>>;

	template<typename Obj>
	Obj ChooseRandomVariant(const ChanceWeights<Obj>& distribution, Randomizer& randomizer);

	using ChanceWeights_u = ChanceWeights<size_t>;
	using ChanceWeights_c = ChanceWeights<char>;
	
	//=================================================================================== vvv template implementations vvv

	template<typename Container>
	auto& RandomElement(Container& container, Randomizer& randomizer)
	{
		return container[randomizer() % container.size()];
	}

	template<typename Obj>
	Obj ChooseRandomVariant(const ChanceWeights<Obj>& distribution, Randomizer& randomizer)
	{
		assert(!distribution.empty());
		double summ_weight = accumulate(distribution.begin(), distribution.end(), 0.,
			[](const double& l, const auto& r)
			{
				assert(r.weight >= 0);
		return l + r.weight;
			});
		double picker = RandomNum(0., summ_weight, randomizer);
		Obj result = distribution.back().obj;
		any_of(distribution.begin(), distribution.end(),
			[&picker, &result](const auto& element)
			{
				assert(picker > 0);
		picker -= element.weight;
		if (picker <= 0)
		{
			result = element.obj;
			return true;
		}
		return false;
			});
		return result;
	}
}