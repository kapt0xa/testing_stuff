#pragma once

#include "random_stops.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

namespace kapt0xa
{
	using std::ostream;
	using std::istream;
	using std::ofstream;
	using std::ifstream;
	using std::fstream;

	using strings = std::vector<std::string>;
	using NumPair = std::pair<double, double>;
	using NumPairs = std::vector<NumPair>;

	strings LoadStrings(istream& in);
	void SaveStrings(const strings& data, ostream& out);

	NumPairs LoadNumPairs(istream& in);
	void SaveNumPairs(const NumPairs& data, ostream& out);
}