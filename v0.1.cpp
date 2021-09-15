#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <algorithm>

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

struct studentas {
    string vard, pavard;
    //nusprendziau, kad pazymiai gali buti tik sveikieji skaiciai
    int nd[10] = {};
    int egz;
    float gal;
    float median;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//tikrinam, ar tai sveikasis skaicius intervale [1;10], naudoju REGEX, kad tikrai nepraeitu tokie issireiskimai kaip "10aaa"
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
    int n;
    string nn;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vard >> kint.pavard;

    cout << "Kiek namu darbu bus? (1-10) " << endl;
    tikrinam_regex(n);

    cout << "Iveskite pazymius: " << endl;

    float sum = 0, vid = 0, med = 0;

    int a;
    for (int i = 0; i < n; i++) {
        tikrinam_regex(kint.nd[i]);
        a = kint.nd[i];
        sum += a;

    }
    vid = sum / n;

    cout << "Iveskite egzamino pazymi: " << endl;
    tikrinam_regex(kint.egz);
    kint.gal = vid * 0.4 + kint.egz * 0.6;

    //medianos skaiciavimas
    sort(kint.nd, kint.nd + n);
    if (n % 2 != 0)
        kint.median = kint.nd[n / 2];
    else
        kint.median = (kint.nd[(n - 1) / 2] + kint.nd[n / 2]) / 2.0;
}

void printas(studentas& kin) {
    cout << setw(15) << left << kin.pavard << setw(15) << kin.vard;
}


int main()
{
    int stud_kiek;
    string input;
    regex integer("^[1-9]$|^[1-9][0-9]$|^(100)$"); //patikriname, kad butu ivestas skaicius tarp 1-100 studentu skaiciui
    while (true)
    {
        cout << "Iveskite, kiek bus studentu: " << endl;
        cin >> input;
        if (regex_match(input, integer))
            break;
        else
        {
            cout << "Ivestis klaidinga, bandykite is naujo " << endl;
            clearInput();
        }
    }
    stud_kiek = std::stoi(input);

    studentas studentai[100]; //nusprendziau, kad max gali buti 100 studentu
    for (int i = 0; i < stud_kiek; i++)
        pild(studentai[i]);

    //medianos arba vidurkio uzklausa bei tikrinimas, kad ivesti teisingi simboliai
    char uzk;
    while (true)
    {
        cout << "Jei norite, kad butu suskaiciuotas vidurkis, parasykite 'v', o jei norite medianos - 'm'" << endl;
        cin >> uzk;
        if (uzk == 'v' || uzk == 'm'){
            break;
        }
        else {
            cout << "Ivestis klaidinga, bandykite is naujo " << endl;
            clearInput();
        }
    }

    //isvedimas
    cout << setw(15) << left << "Pavarde " << setw(15) << "Vardas ";

    if (uzk == 'v'){
        cout << setw(10) << "Galutinis (Vid.) " << endl;
    }
    if (uzk == 'm'){
        cout << setw(10) << "Galutinis (Med.) " << endl;
    }

    
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < stud_kiek; i++) {
        printas(studentai[i]);
        if (uzk == 'v'){
            cout << setw(10) << left << fixed << setprecision(2) << studentai[i].gal << endl;
        }
        if (uzk == 'm') {
            cout << setw(10) << left << fixed << setprecision(2) << studentai[i].median << endl;
        }
    }
}
