/*
 * globalSequenceAlignment.h
 */

#ifndef __GLOBALSEQUENCEALIGNMENT_H__
#define __GLOBALSEQUENCEALIGNMENT_H__

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

vector<vector<struct cellule> > gsa(string &, string &, int &, int &, int &, int &);
vector<vector<string> > GSA(string &, string &, vector<vector<struct cellule> >, int, int);
bool readSequenceGSA(string &, string);
bool writeSequencesGSA(vector<vector<string> > &, string);
void printSequencesGSA(vector<vector<string> > &, int &);
void GSALauncher();
bool GSATryParse(string &, int &);
bool GSATryParseScore(string &, int &);
bool GSAGetScore(int &);
void GSAActionMenu();
void GSAActionOption(string &, string &, vector<vector<string> > &, int &, int &, int &, int &);
void GSAReadSequence(string &);
void GSASaveSequences(vector<vector<string> > &);
void GSARmRed(vector<vector<string> > &);

#endif