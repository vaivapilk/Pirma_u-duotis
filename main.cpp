#include "pagalb_funkcijos.h"
#include "vart_ivedimas.h"

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
	list<studentas> grupe;
	list<studentas> moksliukai;
	list<studentas> nesimoke;

	vector<studentas> vgrupe;
	vector<studentas> vmoksliukai;
	vector<studentas> vnesimoke;

	int K; //studentu skaicius

	//pasirinkimas, ar ivesti rankiniu budu, ar is failo
	//vartotojo ivedimas vykdomas tik su list
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
		cout << endl;
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
		
		cout << "Iveskite kiek studentu norite faile: ";
		cin >> K;
		generavimas(K);
		Timer t;
		if (is_failo(grupe)) return 1;
		cout << K << " elementu nuskaitymas is failo naudojant LIST uztruko: " << t.elapsed() << endl;
		t.reset();
		if (vis_failo(vgrupe)) return 1;
		cout << K << " elementu nuskaitymas is failo naudojant VECTOR uztruko: " << t.elapsed() << endl;

	}

	cout << endl;
	Timer t;
	dalinimas(uzk, grupe, moksliukai, nesimoke); 
	cout << K << " elementu skirstymas i 2 grupes naudojant LIST uztruko: " << t.elapsed() << endl;
	t.reset();
	vdalinimas(uzk, vgrupe, vmoksliukai, vnesimoke);
	cout << K << " elementu skirstymas i 2 grupes naudojant VECTOR uztruko: " << t.elapsed() << endl;

	//isvedimas i faila su LIST
	std::ofstream d_m("rez_moksliukai.txt");
	std::ofstream d_n("rez_nesimoke.txt");

	t.reset();
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

	for (studentas st : moksliukai) {
		d_m << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			d_m << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	d_m.close();
	

	
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
	for (studentas st : nesimoke) {
		d_n << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			d_n << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			d_n << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	d_n.close();


	//isvedimas i faila su VECTOR
	std::ofstream vd_m("v_rez_moksliukai.txt");
	std::ofstream vd_n("v_rez_nesimoke.txt");

	
	vd_m << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

	if (uzk == 'v') {
		vd_m << setw(10) << "Galutinis (Vid.) " << endl;
	}
	if (uzk == 'm') {
		vd_m << setw(10) << "Galutinis (Med.) " << endl;
	}

	for (int i = 0; i < 50; i++)
		vd_m << "-";
	vd_m << endl;

	for (studentas st : vmoksliukai) {
		vd_m << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			vd_m << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			vd_m << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	vd_m.close();



	vd_n << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

	if (uzk == 'v') {
		vd_n << setw(10) << "Galutinis (Vid.) " << endl;
	}
	if (uzk == 'm') {
		vd_n << setw(10) << "Galutinis (Med.) " << endl;
	}

	for (int i = 0; i < 50; i++)
		vd_n << "-";
	vd_n << endl;
	for (studentas st : vnesimoke) {
		vd_n << setw(17) << left << st.pavard << setw(17) << st.vard;
		if (uzk == 'v') {
			vd_n << setw(10) << left << fixed << setprecision(2) << st.gal_v << endl;
		}
		if (uzk == 'm') {
			vd_n << setw(10) << left << fixed << setprecision(2) << st.gal_m << endl;
		}
	}
	vd_n.close();
	

	//remove("rez_moksliukai.txt");
	//remove("rez_nesimoke.txt");
}