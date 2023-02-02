#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace kapt0xa
{
	using std::ostream;
	using std::istream;
	using std::ofstream;
	using std::ifstream;
	using std::fstream;

	using strings = std::vector<std::string>;

	strings LoadStrings(istream& in);
	void SaveStrings(const strings& data, ostream& out);
}