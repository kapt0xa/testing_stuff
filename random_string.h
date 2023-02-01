#pragma once

#include <string>
#include <random>
#include <iostream>
#include <vector>
#include <ctime>

namespace kapt0xa
{
	using std::string;
	using std::ostream;
	using std::istream;
	using strings = std::vector<string>;
	using namespace std::string_literals;
	using Randomizer = std::mt19937_64;

	extern Randomizer default_randomizer;
	struct AvailableChars
	{
		const string alphabet = "abcdefghijklmnopqrstuvwxyz"s;
		const string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
		const string digits = "0123456789"s;
		const string punctuators = "      -"s;

		char RandomLetter(Randomizer& randomizer) const;
		char RandomGrandLetter(Randomizer& randomizer) const;
		char RandomDigit(Randomizer& randomizer) const;
		char RandomPunctuator(Randomizer& randomizer) const;

	} const default_available_chars;

	string MakeRandomWord(Randomizer& randomizer = default_randomizer, size_t min_size = 4, size_t max_size = 10, const AvailableChars& letters = default_available_chars);
	strings MakeRandomWords(size_t count, Randomizer& randomizer = default_randomizer, size_t min_size = 4, size_t max_size = 10, const AvailableChars& letters = default_available_chars);
	string MakeRandomPhrase(const strings& words, size_t min_word_count = 1, size_t max_word_count = 4, Randomizer& randomizer = default_randomizer, const AvailableChars& letters = default_available_chars);
	strings MakeRandomPhrases(size_t count, const strings& words, size_t min_word_count = 1, size_t max_word_count = 4, Randomizer& randomizer = default_randomizer, const AvailableChars& letters = default_available_chars);
	strings LoadStrings(istream& in);
	void SaveStrings(const strings& data, ostream& out);
	strings& UnorderedUnique(strings& data);
}