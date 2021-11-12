
#pragma once
#include "struct.h"

void clearInput();
bool compareFunction(string a, string b);
void printas(studentas& kin);
int words_in_a_string(char* str);
void tikrinam_regex(int& x);
void skaiciavimai(studentas& kint);
void isvedimas(list<studentas>& grupe, char uzk, std::ofstream o);
void skaitymas(studentas& kint, int paz_sk);
int is_failo(list<studentas>& grupe);
void generavimas(int K);
void dalinimas(char uzk, list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& nesimoke);
int vis_failo(vector<studentas>& vgrupe);
void vdalinimas(char uzk, vector<studentas>& vgrupe, vector<studentas>& vmoksliukai, vector<studentas>& vnesimoke);




