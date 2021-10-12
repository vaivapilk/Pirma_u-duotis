#include "Funkcijos.h"

std::ifstream f;

void skaitymas(studentas& kint, int paz_sk)
{

	int k;
	f >> kint.vard >> kint.pavard;
	for (int i = 0; i < paz_sk; i++)
	{
		f >> k;
		kint.nd.push_back(k);
	}
	f >> kint.egz;

}

int is_failo(vector<studentas>& grupe)
{
	studentas stud;
	char str[256];
    f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {

        f.open("kursiokai.txt");
        f.get(str, 256);
        int paz_sk = words_in_a_string(str) - 3;
        while (!f.eof()) {
            skaitymas(stud, paz_sk);
            skaiciavimai(stud);
            grupe.push_back(stud);
            stud.nd.clear();
        }
        f.close();
    }

    catch (std::ifstream::failure e) {
        std::cout << "Exception opening/reading/closing file\n";
        return 1;
    }

    sort(grupe.begin(), grupe.end(), [](studentas a, studentas b)
        {
            if (a.vard == b.vard) return a.pavard < b.pavard;
            else return a.vard < b.vard;
        });

    return 0;
}