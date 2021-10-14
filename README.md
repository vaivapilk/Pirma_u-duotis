# Pirma_užduotis
Pirma užduotis VU kursui "Objektinis programavimas su C++"

Ši programa nuskaito studentų duomenis: vardą ir pavardę, n atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
Tuomet iš šių duomenų, suskaičiuoja galutinį balą pagal formulę:
**Galutinis = 0.4 * vidurkis + 0.6 * egzaminas**

# v0.1
Pirmai versijai, studento duomenis aprašyti, naudota struktūra, taip pat sukurtos keletos funkcijos patogumui. Tikrinimui, ar paleidus programą vartotojas įvedė reikiamas reikšmes, panaudota REGEX (regular expresion).
Papildymui, vietoj vidurkio galutinio balo skaičiavimui panaudota ir mediana. Išvedimas yra pasirinktinas vartotojui: Galutinis (Vid.) arba Galutinis (Med.)

Po dar vieno papildymo, kai namų darbų skaičius (n) yra nežinomas iš anksto, kodas pataisytas, naudojamas tradicinis dinaminis C masyvą mokinio pažymiams sudėti.

Pridėtas failas [v0.1_vector.cpp](https://github.com/vaivapilk/Pirma_uzduotis/blob/v0.1/v0.1_vector.cpp), programa veikia ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Šioje versijoje naudojamas std::vector tipo konteineris, taip pat kodas jau truputį aptvarkytas po pirmųjų bandymų.

Po dar vieno paildymo, v0.1_vector.cpp programoje galima pasirinkti, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai. Pirmoji versija baigta.

# v0.2
Toliau realizuojant v0.1_vector.cpp, iš jo sukurtas v0.2.cpp. Padarytas nuskaitymas iš failo "kursiokai.txt", kai nežinoma, kiek pažymių bei kiek studentų bus. Taip pat vis dar galima pasirinkti vartotojui, ar skaičiuoti vidurkį, ar medianą. Išvedimui padaromas rikiavimas pagal vardą.

# v0.3
v0.2 pataisyta ir pridėta galimybė vartotojui pasirinkti, ar bus vykdomas skaitymas iš failo, ar jis pats įves duomenis. Pataisytas galutinio pažymio skaičiavimas (dabar jis gali būti skaičiuojamas ir nuo medianos). Duomenų tipai perkelti į Header failus, taip pat sukurtas Header failas funkcijoms aprašyti. Funkcijos padalintos į kelis .cpp failus dėl tvarkos. Panaudotas išimčių valdymas "Exception opening/reading/closing file".

# v0.4
Toliau plečiant v0.3, sukurta generavimo funkcija, kurią iškvietus sugeneruojamas pasirinkto dydžio studentų ir jų pažymių sąrašas. Vardai ir pavardės generuojami šabloniškai "Vardas1, Vardas2" ir t.t. Sukurta rūšiavmo funkcija, kuri padalinta studentus į dvi kategorijas pagal pažymius (<5 ir priešingai). Surūšiuoti studentai išvedami į du naujus failus. Atliekama programos veikimo greičio (spartos) analizė. Pats vartotojas turi pasirinkti, kokio dydžio failas bus iš pradžių generuojamas. 
