#include "funkciju.h"

class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};

int main()
{
	vector<studentas> grupe;
	vector<studentas> moksliukai;
	vector<studentas> nesimoke;
	int K = 10;

	//pasirinkimas, ar ivesti rankiniu budu, ar is failo
	char u;
	while (true)
	{
		cout << "Jei noresi ivesti pats parasykite 'p', jei is failo- 'f' ";
		cin >> u;
		if (u == 'p' || u == 'f') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}

	char uzk;
	while (true)
	{
		cout << "Jei norite, kad galutinis balas butu suskaiciuotas pagal vidurki, parasykite 'v', o jei norite pagal mediana - 'm'" << endl;
		cin >> uzk;
		if (uzk == 'v' || uzk == 'm') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}

	if (u == 'p') {
		pats_ivesiu(grupe);
	}

	if (u == 'f') {
		
		Timer t;
		//generavimas(K);
		cout << K << " elementu generavimas kuriant faila uztruko: " << t.elapsed() << endl;
		Timer tt;
		if (is_failo(grupe)) return 1;
		cout << K << " elementu nuskaitymas is failo uztruko: " << tt.elapsed() << endl;
	}

	Timer ttt;
	dalinimas(uzk, grupe, moksliukai, nesimoke); 
	cout << K << " elementu skirstymas i 2 grupes uztruko: " << ttt.elapsed() << endl;


	std::ofstream d_m("rez_moksliukai.txt");
	std::ofstream d_n("rez_nesimoke.txt");

	Timer t1;
	d_m << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

	if (uzk == 'v') {
		d_m << setw(10) << "Galutinis (Vid.) " << endl;
	}
	if (uzk == 'm') {
		d_m << setw(10) << "Galutinis (Med.) " << endl;
	}

	for (int i = 0; i < 50; i++)
		d_m << "-";
	d_m << endl;

	for (int i = 0; i < moksliukai.size(); i++) {
		d_m << setw(17) << left << moksliukai[i].pavard << setw(17) << moksliukai[i].vard;
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << moksliukai[i].gal_v << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << moksliukai[i].gal_m << endl;
		}
	}
	d_m.close();
	cout << K << " elementu moksliuku grupes irasymas i faila uztruko: " << t1.elapsed() << endl;

	Timer t2;
	d_n << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

	if (uzk == 'v') {
		d_n << setw(10) << "Galutinis (Vid.) " << endl;
	}
	if (uzk == 'm') {
		d_n << setw(10) << "Galutinis (Med.) " << endl;
	}

	for (int i = 0; i < 50; i++)
		d_n << "-";
	d_n << endl;
	for (int i = 0; i < nesimoke.size(); i++) {
		d_n << setw(17) << left << nesimoke[i].pavard << setw(17) << nesimoke[i].vard;
		if (uzk == 'v') {
			d_n << setw(10) << left << fixed << setprecision(2) << nesimoke[i].gal_v << endl;
		}
		if (uzk == 'm') {
			d_n << setw(10) << left << fixed << setprecision(2) << nesimoke[i].gal_m << endl;
		}
	}
	d_n.close();
	cout << K << " elementu nesimokiusiu grupes irasymas i faila uztruko: " << t2.elapsed() << endl;

	//remove("rez_moksliukai.txt");
	//remove("rez_nesimoke.txt");
}