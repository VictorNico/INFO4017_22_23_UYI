/*
 * utils.h
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// #define DEBUG

/* PUBLIC GUI FUNCTIONS
 ********************************/
string getInputUser();
/* PUBLIC MATRIX DIMENSION FUNCTIONS
 ********************************/
double **CreateMultiArray(int);
int nextPowOfTwo(int);
bool isPowOfTwo(int);

#endif