#include "gener_dalin.h"

void generavimas(int K)
{

		std::ostringstream os;
		std::ofstream duomenys("kursiokai_sugeneruoti1.txt");
		int stud_kiek = K;
		int k = 1;
		string s;

		os << setw(17) << left << "Vardas " << setw(19) << "Pavarde " << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5"
			<< setw(5) << "ND6" << setw(5) << "ND7" << setw(5) << "ND8" << setw(5) << "ND9" << setw(5) << "ND10" << "Egz";

		duomenys << os.str(); 
		os.seekp(0);

		for (int i = 0; i < stud_kiek; i++)
		{
			s = std::to_string(k);
			os << endl << setw(17) << left << "Vardas" + s << setw(17) << "Pavarde" + s;
			int x = 11;
			//random pazymiu generavimas
			os << std::right;
			for (int j = 0; j < x; j++)
			{
				int R = rand() % 10 + 1;
				os << setw(5) << R;
			}
			k++;
			duomenys << os.str(); os.seekp(0);
		}

		duomenys.close();

}

void dalinimas(char uzk, list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (studentas st : grupe)
		{
			if (st.gal_v < 5)
			{
				nesimoke.push_back(st);
			}

			else
			{
				moksliukai.push_back(st);
			}
		}
	}
	if (uzk == 'm')
	{
		for (studentas st : grupe)
		{
			if (st.gal_m < 5)
			{
				nesimoke.push_back(st);
			}

			else
			{
				moksliukai.push_back(st);
			}
		}
	}



}