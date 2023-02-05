#include "random_busstop_names.h"
#include "random_positions.h"
#include "save_load.h"

using namespace std;
using namespace kapt0xa;

void CreateRandomObjectNames()
{
	ofstream fout("random_object_names.txt");
	auto words = MakeRandomWords(5000, default_randomizer);
	auto phrases = MakeRandomPhrases(11000, words, default_randomizer);
	UnorderedUnique(phrases);
	SaveStrings(phrases, fout);
}

void CreateRandomGeoPisitions()
{
	ofstream fout("random_geopositions.txt");
	auto positions = RandomPositions(10000, default_randomizer);
	SaveNumPairs(positions, fout);
}

int main()
{
	CreateRandomObjectNames();
	CreateRandomGeoPisitions();
}