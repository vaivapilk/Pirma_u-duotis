#include "funkciju.h"

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

//tikrinam, ar tai sveikasis skaicius intervale [1;10], del idomumo naudoju REGEX
void tikrinam_regex(int& x) {
	string input;
	regex integer("^([1-9]|1[0])$");
	while (true)
	{
		cin >> input;
		if (regex_match(input, integer))
			break;
		else
		{
			cout << "Ivestis klaidinga! Pabandykite is naujo " << endl;
			clearInput();
		}
	}
	x = std::stoi(input);
}

void skaiciavimai(studentas& kint)
{
	float vid = 0, med = 0;
	int x;
	vid = std::accumulate(kint.nd.begin(), kint.nd.end(), 0.0) / kint.nd.size();

	kint.gal_v = vid * 0.4 + kint.egz * 0.6;

	//medianos skaiciavimas
	typedef vector<int>::size_type int_vecSize;
	int_vecSize int_size = kint.nd.size();
	sort(kint.nd.begin(), kint.nd.end());
	int_vecSize vidu = int_size / 2;
	if (int_size % 2 != 0)
		med = kint.nd[vidu];
	else
		med = (kint.nd[vidu] + kint.nd[vidu - 1]) / 2.0;
	kint.gal_m = med * 0.4 + kint.egz * 0.6;
}


void isvedimas(vector<studentas>& grupe, char uzk)
{
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
			cout << setw(10) << left << fixed << setprecision(2) << grupe[i].gal_v << endl;
		}
		if (uzk == 'm') {
			cout << setw(10) << left << fixed << setprecision(2) << grupe[i].gal_m << endl;
		}
	}
}