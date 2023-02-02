#include "random_busstop_names.h"
#include "save_load.h"

using namespace std;
using namespace kapt0xa;

int main()
{
	ofstream fout("random_object_names.txt");
	auto words = MakeRandomWords(1000, default_randomizer);
	auto phrases = MakeRandomPhrases(5000, words, default_randomizer);
	UnorderedUnique(phrases);
	SaveStrings(phrases, fout);
}