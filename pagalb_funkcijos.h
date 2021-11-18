
#pragma once
#include "struct.h"

extern std::ifstream f;
extern vector<studentas> vnesimoke2;
extern list<studentas> lnesimoke2;

void clearInput();
void generavimas(int K);
int words_in_a_string(char* str);
void skaitymas(studentas& kint, int paz_sk);
void skaiciavimai(studentas& kint);
int lis_failo(list<studentas>& grupe);
int vis_failo(vector<studentas>& grupe);
void ldalinimas(char uzk, list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& nesimoke);
void vdalinimas(char uzk, vector<studentas>& grupe, vector<studentas>& moksliukai, vector<studentas>& nesimoke);
void ldalinimas2(char uzk, list<studentas>& grupe);
void vdalinimas2(char uzk, vector<studentas>& grupe);
void lisvedimas_i_faila(char uzk, string falo_vardas, list<studentas>& studentai);
void visvedimas_i_faila(char uzk, string falo_vardas, vector<studentas>& studentai);


