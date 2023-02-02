#include "save_load.h"
#include <cassert>

namespace kapt0xa
{
	using std::string;
	using std::getline;

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
}