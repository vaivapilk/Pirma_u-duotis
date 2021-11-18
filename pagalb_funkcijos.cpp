#include "pagalb_funkcijos.h"

void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int lis_failo(list<studentas>& grupe)
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

void ldalinimas(char uzk, list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (studentas st : grupe)
		{
			if (st.gal_v < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}
	if (uzk == 'm')
	{
		for (studentas st : grupe)
		{
			if (st.gal_m < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}

}

void vdalinimas(char uzk, vector<studentas>& grupe, vector<studentas>& moksliukai, vector<studentas>& nesimoke)
{
	if (uzk == 'v')
	{
		for (studentas st : grupe)
		{
			if (st.gal_v < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}
	if (uzk == 'm')
	{
		for (studentas st : grupe)
		{
			if (st.gal_m < 5)
				nesimoke.push_back(st);
			else
				moksliukai.push_back(st);
		}
	}

}

void ldalinimas2(char uzk, list<studentas>& grupe)
{
	if (uzk == 'v')  
	{
		for (studentas st : grupe)
		{
			grupe.erase(remove_if(begin(grupe), end(grupe), [](const auto& x)
				{
					if (x.gal_v >= 5) return false;
					else
					{
						lnesimoke2.push_back(x);
						return true;
					}
				}), end(grupe));
		}
	}
	if (uzk == 'm')
	{
		for (studentas st : grupe)
		{
			grupe.erase(remove_if(begin(grupe), end(grupe), [](const auto& x)
				{
					if (x.gal_m >= 5) return false;
					else
					{
						lnesimoke2.push_back(x);
						return true;
					}
				}), end(grupe));
		}
	}
}

void vdalinimas2(char uzk, vector<studentas>& vgrupe)
{
	if (uzk == 'v')
	{
		auto gend = partition(begin(vgrupe), end(vgrupe), [](const auto& x) {return (x.gal_v >= 5) == 1; });
		vnesimoke2.resize(end(vgrupe)- gend);
		copy(gend, end(vgrupe), begin(vnesimoke2));
		vgrupe.erase(gend, end(vgrupe));
	}
	if (uzk == 'm')
	{
		auto gend = partition(begin(vgrupe), end(vgrupe), [](const auto& x) {return (x.gal_m >= 5) == 1; });
		vnesimoke2.resize(end(vgrupe) - gend);
		copy(gend, end(vgrupe), begin(vnesimoke2));
		vgrupe.erase(gend, end(vgrupe));
	}
}

void lisvedimas_i_faila(char uzk, string failo_vardas, list<studentas>& studentai)
{
	std::ofstream d_m(failo_vardas+".txt");
	if (uzk == 'v') {
		d_m << setw(10) << "Galutinis (Vid.) "+ failo_vardas << endl;
	}
	if (uzk == 'm') {
		d_m << setw(10) << "Galutinis (Med.) "+ failo_vardas << endl;
	}

	for (int i = 0; i < 50; i++)
		d_m << "-";
	d_m << endl;

	for (studentas st : studentai) {
		d_m << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	d_m.close();

}

void visvedimas_i_faila(char uzk, string failo_vardas, vector<studentas>& studentai)
{
	std::ofstream d_m(failo_vardas + ".txt");
	if (uzk == 'v') {
		d_m << setw(10) << "Galutinis (Vid.) " + failo_vardas << endl;
	}
	if (uzk == 'm') {
		d_m << setw(10) << "Galutinis (Med.) " + failo_vardas << endl;
	}

	for (int i = 0; i < 50; i++)
		d_m << "-";
	d_m << endl;

	for (studentas st : studentai) {
		d_m << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	d_m.close();