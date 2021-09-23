#include <string>
#include <iostream>
#include <iomanip>
#include <regex>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::sort;
using std::setw;
using std::left;
using std::fixed;
using std::setfill;
using std::regex;
using std::regex_match;
using std::vector;
using std::getline;

std::ifstream f;

struct studentas {
	string vard, pavard;
	vector <int> nd;
	int egz;
	float gal;
	float median;
};

void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool compareFunction(string a, string b)
{ 
	return a < b; 
}

void printas(studentas& kin) {
	cout << setw(15) << left << kin.pavard << setw(15) << kin.vard;
}

int words_in_a_string(char* str)
{
	int count = 0;
	int temp = 0;
	while (*str) {
		if (*str == ' ' || *str == '\n' || *str == '\t') {
			temp = 0;
		}
		else if (temp == 0) {
			temp = 1;
			count++;
		}
		++str;
	}
	return count;
}

void skaitymas(studentas& kint, int paz_sk)
{
	
	int k;

	/*std::ifstream f;
	f.open("kursiokai.txt");
	f.get(str, 256);
	int paz_sk = words_in_a_string(str) - 3; */
	f >> kint.vard >> kint.pavard;
	for (int i = 0; i < paz_sk; i++)
	{
		f >> k;
		kint.nd.push_back(k);
	}
	f >> kint.egz;

}

void skaiciavimai(studentas& kint)
{
	float vid = 0, med = 0;
	int x;
	vid = std::accumulate(kint.nd.begin(), kint.nd.end(), 0.0) / kint.nd.size();

	kint.gal = vid * 0.4 + kint.egz * 0.6;

	//medianos skaiciavimas
	typedef vector<int>::size_type int_vecSize;
	int_vecSize int_size = kint.nd.size();
	sort(kint.nd.begin(), kint.nd.end());
	int_vecSize vidu = int_size / 2;
	if (int_size % 2 != 0)
		kint.median = kint.nd[vidu];
	else
		kint.median = (kint.nd[vidu] + kint.nd[vidu - 1]) / 2.0;
}

int main()
{
	int stud_kiek;
	char str[256];
	vector<studentas> grupe;
	studentas stud;

	
	f.open("kursiokai.txt");
	f.get(str, 256);
	int paz_sk = words_in_a_string(str) - 3;

	while (f)
	{
		if (!f.eof()) {
			skaitymas(stud, paz_sk);
			skaiciavimai(stud);
			grupe.push_back(stud);
			stud.nd.clear();
		}
		else break;
	}
	sort(grupe.begin(), grupe.end(), [](studentas a, studentas b)
		{
			if (a.vard == b.vard) return a.pavard < b.pavard;
			else return a.vard < b.vard;
		});

	
	//medianos arba vidurkio uzklausa bei tikrinimas, kad ivesti teisingi simboliai
	char uzk;
	while (true)
	{
		cout << "Jei norite, kad butu suskaiciuotas vidurkis, parasykite 'v', o jei norite medianos - 'm'" << endl;
		cin >> uzk;
		if (uzk == 'v' || uzk == 'm') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}

	//isvedimas
	cout << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

	if (uzk == 'v') {
		cout << setw(10) << "Galutinis (Vid.) " << endl;
	}
	if (uzk == 'm') {
		cout << setw(10) << "Galutinis (Med.) " << endl;
	}

	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < grupe.size(); i++) {
		printas(grupe[i]);
		if (uzk == 'v') {
			cout << setw(10) << left << fixed << setprecision(2) << grupe[i].gal << endl;
		}
		if (uzk == 'm') {
			cout << setw(10) << left << fixed << setprecision(2) << grupe[i].median << endl;
		}
	}
}
