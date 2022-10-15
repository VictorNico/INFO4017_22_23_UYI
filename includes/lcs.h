/*
 * lcs.h
 */

#ifndef __LCS_H__
#define __LCS_H__

#include "utils.h"

#ifndef __CELLULE_H__
#define __CELLULE_H__
/*
    abstract structure use to save path and current lcs
*/
struct cellule
{
    int v;
    /* 
        store here the direction from where we are coming.
        < for i,j-1 or left-to-right direction
        ^ for i-1,j or top-to-down direction 
        ˇ for i-1,j-1 or top-let-to-bottom-right direction 
         from no-where
     */
    vector<string> arrows;
};
#endif

vector<vector<struct cellule> > lcs(string &, string &, int &);
vector<string> LCS(string &, string &, vector<vector<struct cellule> >, int, int);
bool readSequence(string &, string); 
bool writeSequences(vector<string> &, string);
void printSequences(vector<string> &, int &);
void LCSLauncher(); 
bool LCSTryParse(string &, int &);
void LCSActionMenu();
void LCSActionOption(string &, string &, vector<string> &, int &);
void LCSReadSequence(string &);
void LCSSaveSequences(vector<string> &);

#endif