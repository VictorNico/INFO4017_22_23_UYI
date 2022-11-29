/*
 * utils.h
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <ctime>

#define DEBUG

using namespace std;
using namespace std::chrono;

// #define DEBUG

/* PUBLIC GUI FUNCTIONS
 ********************************/
string getInputUser();
/* PUBLIC MATRIX DIMENSION FUNCTIONS
 ********************************/
double **CreateMultiArray(int);
int nextPowOfTwo(int);
bool isPowOfTwo(int);
bool TryParse(string &, int &, int, int);
bool backlog(int,int, time_t, time_t, int);
bool writeStream(string, string);
#endif