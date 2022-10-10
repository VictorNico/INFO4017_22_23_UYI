/*
 * utils.cpp
 */

#include "../includes/utils.h"
/* PUBLIC GUI FUNCTIONS
 ********************************/
string getInputUser()
{
    string ch;
    getline(cin, ch);
    return ch;
}
/* PUBLIC MATRIX DIMENSION FUNCTIONS
 ********************************/

double **CreateMultiArray(int size)
{
    double **p = new double *[size];
    for (int i = 0; i < size; ++i)
    {
        p[i] = new double[size];
    }
    return p;
}

int nextPowOfTwo(int size)
{
    return pow(2, ceil(log2(size)));
}

bool isPowOfTwo(int size)
{
    if (size == 0)
    {
        return false;
    }
    return (ceil(log2(size)) == floor(log2(size)));
}