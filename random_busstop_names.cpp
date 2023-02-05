#include "random_busstop_names.h".h"
#include <unordered_set>
#include <cassert>

using std::move;

namespace kapt0xa
{
	
	const string consonant = "bcdfghjklmnprstvwxz"s;
	const string vocal = "aeioquy"s;

	char& MakeGrand(char& letter)
	{
		return letter += 'A' - 'a';
	}

	char RandomLetter(Randomizer& randomizer)
	{
		return RandomNum(static_cast<size_t>('a'), static_cast<size_t>('z'), randomizer);
	}

	char RandomGrandLetter(Randomizer& randomizer)
	{
		return RandomNum(static_cast<size_t>('A'), static_cast<size_t>('Z'), randomizer);
	}

	char RandomDigit(Randomizer& randomizer)
	{
		return RandomNum(static_cast<size_t>('0'), static_cast<size_t>('9'), randomizer);
	}

	char RandomPunctuator(Randomizer& randomizer)
	{
		return ChooseRandomVariant(ChanceWeights_u{ {' ', 3.}, {'-', 1.} }, randomizer);
	}

	size_t min_word_size = 3;
	size_t max_word_size = 10;
	size_t min_caps_size = 2;
	size_t max_caps_size = 5;
	size_t min_num_size = 1;
	size_t max_num_size = 3;

	using UniqueUnordStr = std::unordered_set<string>;

	string MakeFrazeologyBrick(Randomizer& randomizer)
	{
		string result;
		size_t size = ChooseRandomVariant(ChanceWeights_u{ {1, 0.5}, {2, 1.5}, {3, 1.}, {4, 0.25} }, randomizer);
		result.reserve(size);
		while (result.size() < size)
		{
			result.push_back(RandomElement(consonant, randomizer));
		}
		RandomElement(result, randomizer) = RandomElement(vocal, randomizer);
		return result;
	}

	string MakeRandomWord(Randomizer& randomizer)
	{
		string result;
		size_t size;

		size_t type = ChooseRandomVariant(ChanceWeights_u{ {0, 3.},{1, 2.},{2, 1.},{3, 1.} }, randomizer); // 0 - usual, 1 - Name, 2 - CAPS, 3 - number (4564)
		if (type == 2) // make capsed words shorter
		{
			size = RandomNum(min_caps_size, max_caps_size, randomizer);
		}
		else if (type == 3) // make numbers shorter
		{
			size = RandomNum(min_num_size, max_num_size, randomizer);
		}
		else // usual words or Names
		{
			size = RandomNum(min_word_size, max_word_size, randomizer);
		}

		result.reserve(size);

		for (; result.size() < size;)
		{
			switch (type)
			{
			case 0:
			case 1:
				result += MakeFrazeologyBrick(randomizer);
				break;
			case 2:
				result.push_back(RandomGrandLetter(randomizer));
				break;
			case 3:
				result.push_back(RandomDigit(randomizer));
				break;
			default:
				assert(false);
				break;
			}
		}
		if (type == 1)
		{
			MakeGrand(result.front());
		}
		return result;
	}

	strings MakeRandomWords(size_t count, Randomizer& randomizer)
	{
		strings result;
		result.reserve(count);
		for (; result.size() < count;)
		{
			result.push_back(MakeRandomWord(randomizer));
		}
		return result;
	}

	string MakeRandomPhrase(const strings& words, Randomizer& randomizer, size_t min_word_count, size_t max_word_count)
	{
		string result;

		size_t size = RandomNum(min_word_count, max_word_count, randomizer);
		result.reserve(size);

		bool first_loop = true;
		for (size_t i = 0; i < size; ++i)
		{
			if (first_loop)
			{
				first_loop = false;
			}
			else
			{
				result += RandomPunctuator(randomizer);
			}
			result += RandomElement(words, randomizer);
		}

		return result;
	}

	strings MakeRandomPhrases(size_t count, const strings& words, Randomizer& randomizer, size_t min_word_count, size_t max_word_count)
	{
		strings result;
		result.reserve(count);
		for (; result.size() < count;)
		{
			result.push_back(MakeRandomPhrase(words, randomizer));
		}
		return result;
	}
}