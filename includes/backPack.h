/*
 * backPack.h
 */

#ifndef __BACKPACK_H__
#define __BACKPACK_H__

#include "utils.h"

/*
    abstract structure use to save path and current lcs
*/
struct cellule
{
    struct element o; // the current element in the cell
    int weight; // weight result of adding
    /* 
        store here the status of the object
        true means that the object can be added to the back pack
        false else
     */
    bool status;
};

struct element
{
    int v; // the value of the object 
    int p; // the weight of the object.
};

vector<vector<struct cellule> > bp(vector<struct element> &, int, int &);
vector<element> BP(vector<vector<struct cellule> >);
bool readBackPack(vector<struct element> &, string);
bool writeBackPack(vector<struct element> &, string);
void printBackPack(vector<struct element> &, int &);
void BPLauncher();
bool BPTryParse(string &, int &);
bool BPTryParseWeight(string &, int &);
void BPActionMenu();
void BPActionOption(string &, string &, vector<string> &, int &);
void BPReadBackPack(string &);
void BPSaveBackPack(vector<string> &);

#endif