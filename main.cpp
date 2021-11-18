#include "pagalb_funkcijos.h"
#include "vart_ivedimas.h"

std::ifstream f;
vector<studentas> vnesimoke2;
list<studentas> lnesimoke2;

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
	list<studentas> lgrupe;
	list<studentas> lmoksliukai;
	list<studentas> lnesimoke;
	
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
		cout << "Jei norite, kad galutinis balas butu suskaiciuotas pagal vidurki, parasykite 'v', o jei norite pagal mediana - 'm' ";
		cin >> uzk;
		cout << endl;
		if (uzk == 'v' || uzk == 'm') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}

	if (u == 'p') {
		pats_ivesiu(lgrupe);
	}

	if (u == 'f') {
		cout << "Iveskite kiek studentu norite faile: ";
		cin >> K;
		generavimas(K);
		if (lis_failo(lgrupe)) return 1;
		//if (vis_failo(vgrupe)) return 1;
	}

	cout << endl;
	cout << "1 strategija: skirstymas i du naujus konteinerius: " << endl;
	
	Timer t;
	ldalinimas(uzk, lgrupe, lmoksliukai, lnesimoke); 
	cout << K << " elementu skirstymas i 2 grupes naudojant LIST uztruko: " << t.elapsed() << endl;
	
	lisvedimas_i_faila(uzk, "rez_moksliukai_list", lmoksliukai);
	lisvedimas_i_faila(uzk, "rez_nesimoke_list", lnesimoke);
	lmoksliukai.clear(); lnesimoke.clear();

	cout << "2 strategija: naudojimas vieno naujo konteinerio: " << endl;

	t.reset();
	ldalinimas2(uzk, lgrupe);
	cout << K << " elementu skirstymas i 2 grupes naudojant LIST uztruko: " << t.elapsed() << endl;

	lisvedimas_i_faila(uzk, "rez_moksliukai_list2", lgrupe);
	lisvedimas_i_faila(uzk, "rez_nesimoke_list2", lnesimoke2);
	lgrupe.clear(); lnesimoke2.clear();
	
	if (u == 'f') {
		if (vis_failo(vgrupe)) return 1;
	}
	cout << "1 strategija: skirstymas i du naujus konteinerius: " << endl;

	t.reset();
	vdalinimas(uzk, vgrupe, vmoksliukai, vnesimoke);
	cout << K << " elementu skirstymas i 2 grupes naudojant VECTOR uztruko: " << t.elapsed() << endl;

	visvedimas_i_faila(uzk, "rez_moksliukai_vect", vmoksliukai);
	visvedimas_i_faila(uzk, "rez_nesimoke_vect", vnesimoke);
	vmoksliukai.clear(); vmoksliukai.shrink_to_fit(); vnesimoke.clear(); vnesimoke.shrink_to_fit();

	cout << "2 strategija: naudojimas vieno naujo konteinerio: " << endl;
	
	t.reset();
	vdalinimas2(uzk, vgrupe);
	cout << K << " elementu skirstymas i 2 grupes naudojant VECTOR uztruko: " << t.elapsed() << endl;
	
	visvedimas_i_faila(uzk, "rez_moksliukai_vect2", vgrupe);
	visvedimas_i_faila(uzk, "rez_nesimoke_vect2", vnesimoke2);

}