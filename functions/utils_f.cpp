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

bool TryParse(string &input, int &output, int limit, int begin)
{
    try
    {
        output = stoi(input);
    }
    catch (invalid_argument)
    {
        return false;
    }
    return (output >= begin && output < limit);
}

bool backlog(int len, time_t scoring, time_t tracebacking, int num)
{
    // Read from the text file
    ofstream SequenceFile("logs/gsa.csv", ios_base::app);
    // Check if file exists and can be write
    if (SequenceFile.good())
    {
    // Write the sequences
    // save  sequence information to the file
    SequenceFile << to_string(len) << ";" << scoring << ";" << tracebacking << ";" << to_string(num) << endl;;
    // Close stream reader
    SequenceFile.close();

    return true;
    }
    return false;
}