/*
 * setup.cpp
 */

#include "./includes/globalSequenceAlignment.h"
#include "./includes/strassen.h"
#include "./includes/pgcb.h"
#include "./includes/lcs.h"
#include "./includes/tsp.h"
#include "./includes/cctp1.h"
#include "./includes/setup.h"

int main()
{

    // welcome menu
    cout << "  \t\tINFO4017 INF DEPTINF UYI " << endl;
    cout << "  WELCOME TO OUR CLEAR STRUCTURE CODE " << endl;
    cout << "  GO " << endl;

    MainActionOption();

    return 0;
}

bool MainTryParse(string &input, int &output)
{
    try
    {
        output = stoi(input);
    }
    catch (invalid_argument)
    {
        return false;
    }
    return (output >= 0 && output < 7);
}

void MainActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) STRASSEN " << endl;
    cout << "  2) LCS " << endl;
    cout << "  3) SEQUENCE GLOBAL ALIGNMENT " << endl;
    cout << "  4) PGCB " << endl;
    cout << "  5) TSP USING SA " << endl;
    cout << "  6) CC|TP " << endl;
    cout << "  0) EXIT " << endl;
}

void MainActionOption()
{
    int option = -1;
    string action;
    do
    {
        // always show action option to users
        MainActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (MainTryParse(action, option) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY AND GOOD BYE " << endl;
            break;
        case 1:
            // code load strassen
            StrassenLauncher();
            break;
        case 2:
            // code load lcs
            LCSLauncher(); 
            break;
        case 3:
            // code load gsa
            GSALauncher();
            break;
        case 4:
            // code load pgcb
            PGCBLauncher(); 
            break;
        case 5:
            // code load pgcb
            TSPLauncher(); 
            break;
        case 6:
            // code load pgcb
            CCTPLauncher();
            break;
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}
