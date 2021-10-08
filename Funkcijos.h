#pragma once
#include "struct.h"

void clearInput();
bool compareFunction(string a, string b);
void printas(studentas& kin);
int words_in_a_string(char* str);
void skaitymas(studentas& kint, int paz_sk);
void tikrinam_regex(int& x);
void skaiciavimai(studentas& kint);
void isvedimas(vector<studentas>& grupe, char uzk, std::ofstream o);
void is_failo(vector<studentas>& grupe);
void pild(studentas& kint);
void pats_ivesiu(vector<studentas>& grupe);
void generavimas();
void dalinimas(char uzk, vector<studentas>& grupe, vector<studentas>& moksliukai, vector<studentas>& nesimoke);
