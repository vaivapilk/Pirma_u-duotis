#include "funkciju.h"

void pild(studentas& kint) {
	cout << "Iveskite studento varda ir pavarde: ";
	cin >> kint.vard >> kint.pavard;

	//uzklausa, ar generuoti pazymius automatiskai, ar pats vartotojas ives
	char gen;
	while (true)
	{
		cout << "Jei norite, kad programa sugeneruotu pazymius bei egzamino rez automatiskai, parasykite 'a', jei ivesite pats- 'p' " << endl;
		cin >> gen;
		if (gen == 'a' || gen == 'p') {
			break;
		}
		else {
			cout << "Ivestis klaidinga, bandykite is naujo " << endl;
			clearInput();
		}
	}

	int x;
	if (gen == 'a')
	{
		cout << "Iveskite, kiek pazymiu norite sugeneruoti (egzamino pazymys taip pat bus sugeneruotas automatiskai): ";
		while (!(cin >> x))
		{
			cout << "Blogai ivedete, bandykite is naujo ";
			clearInput();
		}
		//random pazymiu generavimas
		int R = rand() % 10 + 1;
		for (int i = 0; i < x; i++)
		{
			kint.nd.push_back(R);
			R = rand() % 10 + 1;
		}
		kint.egz = R;
	}

	if (gen == 'p')
	{
		//pazymiu ivedimas, kai dar nenuspresta, kiek pazymiu bus
		cout << "Iveskite pazymius, kai nuspresite, kad jau ivedete visus (iki 10 pazymiu), parasykite 'q' ir spauskite enter " << endl;
		string input;
		regex integer("^([1-9]|1[0])$");
		while (true)
		{
			cin >> input;
			if (input == "q")
				break;
			if (regex_match(input, integer))
			{
				kint.nd.push_back(std::stoi(input));
			}
			else
			{
				cout << "Ivestis klaidinga! Pabandykite is naujo " << endl;
				clearInput();
			}
		}

		clearInput();
		cout << "Iveskite egzamino pazymi: " << endl;
		tikrinam_regex(kint.egz);
		clearInput();
	}

	typedef vector<int>::size_type int_vecSize;
	int_vecSize int_size = kint.nd.size();
	if (int_size == 0)
	{
		cout << "Privalote ivesti ND rezultatus. Bandykite is naujo. ";
	}
	else
	{
		skaiciavimai(kint);
	}
}


void pats_ivesiu(vector<studentas>& grupe)
{
	int stud_kiek;

	cout << "Iveskite, kiek bus studentu: " << endl;
	while (!(cin >> stud_kiek))
	{
		cout << "Blogai ivedete, bandykite is naujo ";
		clearInput();
	}


	studentas tempo;
	grupe.reserve(stud_kiek);

	for (int i = 0; i < stud_kiek; i++)
	{
		pild(tempo);
		grupe.push_back(tempo);
	}
}