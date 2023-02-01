#include "random_string.h"
#include <unordered_set>
#include <cassert>

using std::move;

namespace kapt0xa
{
	using UniqueUnordStr = std::unordered_set<string>;
	using std::getline;

	Randomizer default_randomizer(std::time(0));

	template<typename Container>
	auto RandomElement(const Container& container, Randomizer& randomizer)
	{
		return container[randomizer() % container.size()];
	}

	size_t RandomNum(size_t from, size_t to, Randomizer& randomizer)
	{
		assert(from < to);
		assert((to - from + 1) != 0);
		return from + randomizer() % (to - from + 1);
	}

	string MakeRandomWord(Randomizer& randomizer, size_t min_size, size_t max_size, const AvailableChars& letters)
	{
		string result;
		size_t size = RandomNum(min_size, max_size, randomizer);

		size_t type = RandomNum(0, 3, randomizer); // 0 - usual, 1 - Name, 2 - CAPS, 3 - number (4564)
		if (type == 2) // make capsed words shorter
		{
			size /= 2;
			size += 1;
		}
		if (type == 3) // make numbers shorter
		{
			size /= 3;
			size += 1;
		}

		result.reserve(size);

		for (; result.size() < size;)
		{
			switch (type)
			{
			case 0:
				result.push_back(letters.RandomLetter(randomizer));
				break;
			case 1:
				result.push_back(letters.RandomGrandLetter(randomizer));
				type = 0;
				break;
			case 2:
				result.push_back(letters.RandomGrandLetter(randomizer));
				break;
			case 3:
				result.push_back(letters.RandomDigit(randomizer));
				break;
			default:
				assert(false);
				break;
			}
		}
		return result;
	}

	strings MakeRandomWords(size_t count, Randomizer& randomizer, size_t min_size, size_t max_size, const AvailableChars& letters)
	{
		strings result;
		result.reserve(count);
		for (; result.size() < count;)
		{
			result.push_back(MakeRandomWord(randomizer, min_size, max_size, letters));
		}
		return result;
	}

	string MakeRandomPhrase(const strings& words, size_t min_word_count, size_t max_word_count, Randomizer& randomizer, const AvailableChars& letters)
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
				result += letters.RandomPunctuator(randomizer);
			}
			result += RandomElement(words, randomizer);
		}

		return result;
	}

	strings MakeRandomPhrases(size_t count, const strings& words, size_t min_word_count, size_t max_word_count, Randomizer& randomizer, const AvailableChars& letters)
	{
		strings result;
		result.reserve(count);
		for (; result.size() < count;)
		{
			result.push_back(MakeRandomPhrase(words, min_word_count, max_word_count, randomizer, letters));
		}
		return result;
	}

	strings LoadStrings(istream& in)
	{
		strings result;
		size_t count;
		in >> count;
		result.reserve(count);
		while (result.size() < count)
		{
			string line;
			getline(in, line);
			result.push_back(move(line));
		}
		return result;
	}

	void SaveStrings(const strings& data, ostream& out)
	{
		out << data.size() << '\n';
		for (const string& frame : data)
		{
			out << frame << '\n';
		}
	}

	strings& UnorderedUnique(strings& data)
	{
		UniqueUnordStr unique;
		for (string& word : data)
		{
			unique.insert(move(word));
		}

		data.clear();
		data.reserve(unique.size());

		for (const string& word_raw : unique)
		{
			data.push_back(move(const_cast<string&>(word_raw)));
		}

		return data;
	}

	char AvailableChars::RandomLetter(Randomizer& randomizer) const
	{
		return RandomElement(alphabet, randomizer);
	}

	char AvailableChars::RandomGrandLetter(Randomizer& randomizer) const
	{
		return RandomElement(caps, randomizer);
	}

	char AvailableChars::RandomDigit(Randomizer& randomizer) const
	{
		return RandomElement(digits, randomizer);
	}

	char AvailableChars::RandomPunctuator(Randomizer& randomizer) const
	{
		return RandomElement(punctuators, randomizer);
	}
}