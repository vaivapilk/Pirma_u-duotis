#include "pagalb_funkcijos.h"
std::ifstream f;

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


void isvedimas(list<studentas>& grupe, char uzk)
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
	for (studentas st : grupe) {
		printas(st);
		if (uzk == 'v') {
			cout << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			cout << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
}


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


int is_failo(list<studentas>& grupe)
{
	studentas stud;
	char str[256];
	f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {

		f.open("kursiokai_sugeneruoti1.txt");
		f.get(str, 256);
		int paz_sk = words_in_a_string(str) - 3;
		while (!f.eof()) {
			skaitymas(stud, paz_sk);
			skaiciavimai(stud);
			grupe.push_back(stud);
			stud.nd.clear();
		}
		f.close();
		f.clear();
	}

	catch (std::ifstream::failure e) {
		std::cout << "Exception opening/reading/closing file\n";
		return 1;
	}

	//rikiavimas
	/*sort(grupe.begin(), grupe.end(), [](studentas a, studentas b)
		{
			if (a.vard == b.vard) return a.pavard < b.pavard;
			else return a.vard < b.vard;
		});*/

	return 0;
}

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

int vis_failo(vector<studentas>& vgrupe)
{
	studentas stud;
	char str[256];
	f.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {

		f.open("kursiokai_sugeneruoti1.txt");
		f.get(str, 256);
		int paz_sk = words_in_a_string(str) - 3;
		while (!f.eof()) {
			skaitymas(stud, paz_sk);
			skaiciavimai(stud);
			vgrupe.push_back(stud);
			stud.nd.clear();
		}
		f.close();
	}

	catch (std::ifstream::failure e) {
		std::cout << "Exception opening/reading/closing file\n";
		return 1;
	}

	/*sort(vgrupe.begin(), vgrupe.end(), [](studentas a, studentas b)
		{
			if (a.vard == b.vard) return a.pavard < b.pavard;
			else return a.vard < b.vard;
		});*/

	return 0;
}
void vdalinimas(char uzk, vector<studentas>& vgrupe, vector<studentas>& vmoksliukai, vector<studentas>& vnesimoke)
{
	if (uzk == 'v')
	{
		for (studentas st : vgrupe)
		{
			if (st.gal_v < 5)
			{
				vnesimoke.push_back(st);
			}

			else
			{
				vmoksliukai.push_back(st);
			}
		}
	}
	if (uzk == 'm')
	{
		for (studentas st : vgrupe)
		{
			if (st.gal_m < 5)
			{
				vnesimoke.push_back(st);
			}

			else
			{
				vmoksliukai.push_back(st);
			}
		}
	}

}