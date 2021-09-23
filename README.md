# Pirma_užduotis
Pirma užduotis VU kursui "Objektinis programavimas su C++"

Ši programa nuskaito studentų duomenis: vardą ir pavardę. n atliktų namų darbų rezultatus (10-balėje sistemoje), o taip pat egzamino (egz) rezultatą.
Tuomet iš šių duomenų, suskaičiuoja galutinį balą pagal formulę:
**Galutinis = 0.4 * vidurkis + 0.6 * egzaminas**

Pirmai versijai, studento duomenis aprašyti, naudota struktūra, taip pat sukurtos keletos funkcijos patogumui. Tikrinimui, ar paleidus programą vartotojas įvedė reikiamas reikšmes, panaudota REGEX (regular expresion).
Papildymui, vietoj vidurkio galutinio balo skaičiavimui panaudota ir mediana. Išvedimas yra pasirinktinas vartotojui: Galutinis (Vid.) arba Galutinis (Med.)

Pridėtas failas [v0.1_vector.cpp](https://github.com/vaivapilk/Pirma_uzduotis/blob/v0.1/v0.1_vector.cpp), programa veikia ir tokiu atveju, kai namų darbų skaičius (n) yra nežinomas iš anksto, t.y. tik įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus. Šioje versijoje naudojamas std::vector tipo konteineris, taip pat kodas jau truputį aptvarkytas po pirmųjų bandymų.

Po dar vieno paildymo, v0.1_vector.cpp programoje galima pasirinkti, jog mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai
