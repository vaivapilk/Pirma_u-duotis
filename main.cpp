#include "Funkcijos.h"

int main()
{
	vector<studentas> grupe;

	//pasirinkimas, ar ivesti rankiniu budu, ar is failo
	char u;
	cout << "Jei noresi ivesti pats parasykite 'p', jei is failo- 'f' ";
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

	if (u == 'p') {
		pats_ivesiu(grupe);
	}

	if (u == 'f') {
		if(is_failo(grupe)) return 1;
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

	//isvedimas
	isvedimas(grupe, uzk);
}