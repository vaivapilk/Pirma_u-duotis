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

struct studentas {
    string vard, pavard;
    //nusprendziau, kad pazymiai gali buti tik sveikieji skaiciai
    vector <int> nd;
    int egz;
    float gal;
    float median;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void pild(studentas& kint) {
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vard >> kint.pavard;

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

    float sum = 0, vid = 0, med = 0;
    int x;

    if (gen == 'a')
    {
        //random pazymiu generavimas
        int R = rand() % 10 + 1;
        cout << "Iveskite, kiek pazymiu norite sugeneruoti (egzamino pazymys taip pat bus sugeneruotas automatiskai): ";
        while (!(cin >> x))
        {
            cout << "Blogai ivedete, bandykite is naujo ";
            clearInput();
        }

        for (int i = 0; i < x; i++)
        {
            kint.nd.push_back(R);
            R = rand() % 10 + 1;
            sum += x;
        }

        kint.egz = R;
    }

    if (gen == 'p')
    {
        //pazymiu ivedimas, kai dar nenuspresta, kiek pazymiu bus
        cout << "Iveskite pazymius, kai nuspresite, kad jau ivedete visus (iki 10 pazymiu), parasykite 'q' ir spauskite enter " << endl;
        while (cin >> x)
        {
            if (x > 10 || x < 1)
            {
                cout << "Pazymys negali buti daugiau uz 10! " << endl;
            }
            else
            {
                kint.nd.push_back(x);
                sum += x;
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
    vid = std::accumulate(kint.nd.begin(), kint.nd.end(), 0.0) / kint.nd.size();

    kint.gal = vid * 0.4 + kint.egz * 0.6;

    //medianos skaiciavimas
    typedef vector<float>::size_type vecSize;
    vecSize size = kint.nd.size();
    if (size == 0)
        throw std::domain_error("Negalima skaiciuot medianos tusciam vektoriui");
    sort(kint.nd.begin(), kint.nd.end());
    vecSize vidu = size / 2;
    if (size % 2 != 0)
        kint.median = kint.nd[vidu];
    else
        kint.median = (kint.nd[vidu] + kint.nd[vidu - 1]) / 2.0;

    kint.nd.clear();
}

void printas(studentas& kin) {
    cout << setw(15) << left << kin.pavard << setw(15) << kin.vard;
}


int main()
{
    int stud_kiek;

    cout << "Iveskite, kiek bus studentu: " << endl;
    while (!(cin >> stud_kiek))
    {
        cout << "Blogai ivedete, bandykite is naujo ";
        clearInput();
    }


    vector<studentas> grupe;
    studentas tempo;
    grupe.reserve(stud_kiek);

    for (int i = 0; i < stud_kiek; i++)
    {
        pild(tempo);
        grupe.push_back(tempo);
    }


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
    for (int i = 0; i < stud_kiek; i++) {
        printas(grupe[i]);
        if (uzk == 'v') {
            cout << setw(10) << left << fixed << setprecision(2) << grupe[i].gal << endl;
        }
        if (uzk == 'm') {
            cout << setw(10) << left << fixed << setprecision(2) << grupe[i].median << endl;
        }
    }
}
