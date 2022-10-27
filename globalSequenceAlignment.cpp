/*
 * globalSequenceAlignment.cpp
 */

#include "./includes/globalSequenceAlignment.h"

void GSALauncher()
{

    // welcome menu
    cout << "  WELCOME TO SEQUENCE GLOBAL ALIGNMENT IMPLEMENTATION " << endl;
    cout << "  YOU'RE ABLE TO GET LONGEST COMMON SUBSEQUENCES " << endl;
    cout << "  YOU JUST NEED TO ENTER PATH OF DIFFERENTS " << endl;
    cout << "  SEQUENCE WITH THE STRUCTURE OF TEXT " << endl;
    cout << "  DEFAULT " << endl;
    cout << "  MATCH = 2, MISMATCH = -1, GAP = -2 " << endl;
    cout << "  LET'S START " << endl;

    // GLOBAL MODULE VARIABLES
    string s1, s2;
    vector<vector<string> > sf;
    int match = 2, mismatch = -1, gap = -2;
    int score;
    GSAActionOption(s1, s2, sf, score, match, mismatch, gap);
}

bool GSATryParse(string &input, int &output)
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

void GSAActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) LOAD SEQUENCE 1 " << endl;
    cout << "  2) LOAD SEQUENCE 2 " << endl;
    cout << "  3) PRINT SEQUENCE 1 " << endl;
    cout << "  4) PRINT SEQUENCE 2 " << endl;
    cout << "  5) GSA(SEQUENCE1,SEQUENCE2) " << endl;
    cout << "  6) SAVE RESULT SUBSEQUENCE " << endl;
    cout << "  7) PRINT RESULT SUBSEQUENCE " << endl;
    cout << "  8) ARN GENERATOR " << endl;
    cout << "  0) EXIT " << endl;
}

void GSAActionOption(string &s1, string &s2, vector<vector<string> > &sf, int &score, int &match, int &mismatch, int &gap)
{
    int option = -1;
    string action;
    vector<vector<cellule> > PD;
    do
    {
        // always show action option to users
        GSAActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (TryParse(action, option, 9, 0) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY " << endl;
            break;
        case 1:
            // code load 1
            GSAReadSequence(s1);
            break;
        case 2:
            // code load 2
            GSAReadSequence(s2);
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
        {
            // code GSA
            // Get starting timepoint
            time_t start = time(0);
            PD = gsa(s1, s2, score, match, mismatch, gap);
            // Get ending timepoint
            time_t stop = time(0);
            // use duration cast method
            time_t duration = (stop * 1000 - start * 1000);
#ifdef DEBUG
            cout << s1.size() << "," << s2.size() << endl;
            cout << (start * 1000) << endl
                 << (stop * 1000) << endl;
#endif
            // Get starting timepoint
            time_t start1 = time(0);
            sf = GSA(s1, s2, PD, s1.size(), s2.size());
            // sf = GSAIteratif(s1, s2, PD);
            // Get ending timepoint
            time_t stop1 = time(0);
            // use duration cast method
            time_t duration1 = (stop1 * 1000 - start1 * 1000);
            // save logs
            backlog(s1.size(), s2.size(), duration, duration1, sf[0].size());
            // GSARmRed(sf);

#ifdef DEBUG
            cout << sf.size() << endl;
            cout << (start1 * 1000) << endl
                 << (stop1 * 1000) << endl;
#endif

            break;
        }
        case 6:
            // code save result
            GSASaveSequences(sf);
            break;
        case 7:
            // code print result
            printSequencesGSA(sf, score);
            break;
        case 8:
            // code print result
            GSAGeneratpr();
            break;
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}

void GSARmRed(vector<vector<string> > &sf){
    // remove redundancy
    set<string> a;
    set<string> c;
    set<string> b;
    for (int k1 = 0; k1 < sf[0].size(); k1++)
    {
        a.insert(sf[0][k1] + "," + sf[1][k1]);
    }

    set<string>::iterator it;

    for (it = a.begin(); it != a.end(); ++it)
    {
        string j = *it;
        size_t pos = j.find(",");
        b.insert(j.substr(0, pos));
        j.erase(0, pos + 1);
        c.insert(j);
    }
    // back to vectors
    sf[0].clear();
    sf[0].assign(b.begin(), b.end());
    sf[1].clear();
    sf[1].assign(c.begin(), c.end());
}

void GSAReadSequence(string &s)
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

        flag = readSequenceGSA(s, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}

void GSASaveSequences(vector<vector<string> > &s)
{

    string path;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE RESULT GSA PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        flag = writeSequencesGSA(s, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}

void GSAGeneratpr()
{

    string path;
    string input;
    int a;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE RESULT ARN PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        do
        {
            cout << "\n  PLEASE HIT THE LENGTH OF THE ARN " << endl;
            input = getInputUser();
        } while (TryParse(input, a, 10000, 1) == false);

        flag = GenADN(a,path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}