#include "save_load.h"
#include <cassert>
#include <sstream>
#include <iomanip>

namespace kapt0xa
{
	using namespace std;

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

	NumPairs LoadNumPairs(istream& in)
	{
		NumPairs result;
		size_t count;
		in >> count;
		result.reserve(count);
		while (result.size() < count)
		{
			string line;
			getline(in, line);
			stringstream line_to_read(line);
			NumPair nums;
			line_to_read >> nums.first >> nums.second;
			result.push_back(move(nums));
		}
		return result;
	}

	void SaveNumPairs(const NumPairs& data, ostream& out)
	{
		out << data.size() << setprecision(16) << '\n';
		for (const NumPair& nums : data)
		{
			out << nums.first << ' ' << nums.second << '\n';
		}
	}
}