/*
 * lcs.cpp
 */

#include "./includes/lcs.h"

void LCSLauncher()
{

    // welcome menu
    cout << "  WELCOME TO LCS IMPLEMENTATION " << endl;
    cout << "  YOU'RE ABLE TO GET LONGEST COMMON SUBSEQUENCES " << endl;
    cout << "  YOU JUST NEED TO ENTER PATH OF DIFFERENTS " << endl;
    cout << "  SEQUENCE WITH THE STRUCTURE OF TEXT " << endl;
    cout << "  LET'S START " << endl;

    // GLOBAL MODULE VARIABLES 
    string s1,s2;
    vector<string> sf;
    int _lcs;
    LCSActionOption(s1,s2,sf,_lcs);
}

bool LCSTryParse(string &input, int &output)
{
    try
    {
        output = stoi(input);
    }
    catch (invalid_argument)
    {
        return false;
    }
    return (output >= 0 && output < 8);
}

void LCSActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) LOAD SEQUENCE 1 " << endl;
    cout << "  2) LOAD SEQUENCE 2 " << endl;
    cout << "  3) PRINT SEQUENCE 1 " << endl;
    cout << "  4) PRINT SEQUENCE 2 " << endl;
    cout << "  5) LCS(SEQUENCE1,SEQUENCE2) " << endl;
    cout << "  6) SAVE RESULT SUBSEQUENCE " << endl;
    cout << "  7) PRINT RESULT SUBSEQUENCE " << endl;
    cout << "  0) EXIT " << endl;
}

void LCSActionOption(string &s1, string &s2, vector<string> &sf, int &lng)
{
    int option = -1;
    string action;
    vector<vector<cellule> > PD;
    do
    {
        // always show action option to users
        LCSActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (LCSTryParse(action, option) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY " << endl;
            break;
        case 1:
            // code load 1
            LCSReadSequence(s1);
            break;
        case 2:
            // code load 2
            LCSReadSequence(s2);
            break;
        case 3:
            // code print 1
            cout << "seq1: " << s1 << endl;
            break;
        case 4:
            // code print 2
            cout << "seq2: " << s2 << endl;
            break;
        case 5:
            // code lcs
            PD = lcs(s1, s2, lng);
            #ifdef DEBUG
            cout << s1.size() << "," <<s2.size() << endl;
            #endif
            sf = LCS(s1,s2,PD,s1.size(),s2.size());
            #ifdef DEBUG
            cout << sf.size() << endl;
            #endif
            break;
        case 6:
            // code save result
            LCSSaveSequences(sf);
            break;
        case 7:
            // code print result
            printSequences(sf, lng);
            break;
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}

void LCSReadSequence(string &s)
{

    string path;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE SEQUENCE PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        flag = readSequence(s, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}

void LCSSaveSequences(vector<string> &s)
{

    string path;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE RESULT LCS PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        flag = writeSequences(s, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}