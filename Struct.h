#pragma once
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
#include <fstream>
#include <chrono>

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
using std::getline;

struct studentas {
	string vard, pavard;
	vector <int> nd;
	int egz;
	float median;
	float gal_v;
	float gal_m;
};

class Timer {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
	Timer() : start{ std::chrono::high_resolution_clock::now() } {}
	void reset() {
		start = std::chrono::high_resolution_clock::now();
	}
	double elapsed() const {
		return std::chrono::duration<double>
			(std::chrono::high_resolution_clock::now() - start).count();
	}
};

