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
Skirtingų failų palyginimai:

![t1](https://user-images.githubusercontent.com/56174822/138706581-11e42d4f-aa4a-4b0f-9975-36634460ebff.PNG)
![t2](https://user-images.githubusercontent.com/56174822/138706655-1a9e1f78-0a46-44e8-bc42-1e86a003eebc.PNG)
![t3](https://user-images.githubusercontent.com/56174822/138706672-0b5f44de-4562-4700-a49a-b840df953c99.PNG)
![t4](https://user-images.githubusercontent.com/56174822/138706696-11c77c46-42c4-42c3-b933-0fa6ad46350d.PNG)

# v0.5
v0.4 pataisyta ir dabar duomenų failas yra generuojamas eilutėmis, kad būtų greičiau, taip pat sukurti header failai kiekvienam .cpp failui, kad būtų tvarkingiau. Šioje versijoje matuojamas duomenų nuskaitymo bei studentų rūšiavimo greitis naudojant list konteinerį (greitis lyginamas su vector konteineriu). Per VisualStudio padarytas Release x64.

Sistemos parametrai:
Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz   1.19 GHz, RAM 8,00 GB, ADATA 256GB.

**Vector** sparta:

![v1k](https://user-images.githubusercontent.com/56174822/140042340-2d8cb966-98d1-4953-bfb0-49acb1c444fa.PNG)
![v10k](https://user-images.githubusercontent.com/56174822/140042392-6ecc25c8-7d28-47c6-be7e-0f27dadb91af.PNG)
![v100k](https://user-images.githubusercontent.com/56174822/140042405-52322076-8526-4a57-96eb-1b319737809a.PNG)
![v1m](https://user-images.githubusercontent.com/56174822/140042430-9b4455c0-762e-4da2-8f3c-ea0d6b7359ed.PNG)
![v10m](https://user-images.githubusercontent.com/56174822/140042443-d8284411-ea7e-4825-9bee-a06760ebf938.PNG)

**List** sparta:

![l1k](https://user-images.githubusercontent.com/56174822/140042592-38837042-c565-4dd4-a3ab-9880232761d9.PNG)
![l10k](https://user-images.githubusercontent.com/56174822/140042610-2bf5ac89-5734-4cbe-a4e5-9c6d26d5c8c7.PNG)
![l100k](https://user-images.githubusercontent.com/56174822/140042632-49d92fd8-4b56-4304-a533-8ae51f81325c.PNG)
![l1m](https://user-images.githubusercontent.com/56174822/140042646-ffdeaccb-43e5-4dd2-b076-1b6a032362fe.PNG)
![l10m](https://user-images.githubusercontent.com/56174822/140042657-9a56191a-4c1b-4efd-9b2d-083f67563d07.PNG)


