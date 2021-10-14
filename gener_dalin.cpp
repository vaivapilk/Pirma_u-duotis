#include "funkciju.h"

void generavimas(int K)
{
	std::ofstream duomenys("kursiokai_sugeneruoti1.txt");
	int stud_kiek = K;
	int k = 1;
	string s;
	duomenys << setw(17) << left << "Vardas " << setw(17) << "Pavarde " << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5"
		<< setw(5) << "ND6" << setw(5) << "ND7" << setw(5) << "ND8" << setw(5) << "ND9" << setw(5) << "ND10" << setw(5) << "Egz";

	for (int i = 0; i < stud_kiek; i++)
	{
		s = std::to_string(k);
		duomenys << endl << setw(17) << left << "Vardas" + s << setw(17) << "Pavarde" + s;
		int x = 11;
		//random pazymiu generavimas
		duomenys << std::right;
		for (int j = 0; j < x; j++)
		{
			int R = rand() % 10 + 1;
			duomenys << setw(5) << R;
		}
		k++;

	}
	duomenys.close();

}

void dalinimas(char uzk, vector<studentas>& grupe, vector<studentas>& moksliukai, vector<studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (int i = 0; i < grupe.size(); i++)
		{
			if (grupe[i].gal_v < 5)
			{
				nesimoke.push_back(grupe[i]);
			}

			else
			{
				moksliukai.push_back(grupe[i]);
			}
		}
	}
	if (uzk == 'm')
	{
		for (int i = 0; i < grupe.size(); i++)
		{
			if (grupe[i].gal_m < 5)
			{
				nesimoke.push_back(grupe[i]);
			}

			else
			{
				moksliukai.push_back(grupe[i]);
			}
		}
	}



}
