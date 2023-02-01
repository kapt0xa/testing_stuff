#include "random_string.h"
#include <fstream>

using namespace std;
using namespace kapt0xa;

int main()
{
	ofstream fout("random_busnames.txt");
	auto words = MakeRandomWords(1000);
	auto phrases = MakeRandomPhrases(5000, words);
	UnorderedUnique(phrases);
	SaveStrings(phrases, fout);
}