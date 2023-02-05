#pragma once
#include "my_random.h"
#include <string>
#include <vector>

namespace kapt0xa
{
	using std::string;
	using strings = std::vector<string>;
	using namespace std::string_literals;

	string MakeRandomWord(Randomizer& randomizer);
	strings MakeRandomWords(size_t count, Randomizer& randomizer);
	string MakeRandomPhrase(const strings& words, Randomizer& randomizer, size_t min_word_count = 1, size_t max_word_count = 4);
	strings MakeRandomPhrases(size_t count, const strings& words, Randomizer& randomizer, size_t min_word_count = 1, size_t max_word_count = 4);
}