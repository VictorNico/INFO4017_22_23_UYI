/*
 * CCTP1.cpp
 */

#include "./includes/cctp1.h"

void CCTPLauncher()
{

    // welcome menu
    cout << "  WELCOME TO CC|TP 1 IMPLEMENTATION " << endl;
    cout << "  YOU'RE ABLE TO THE BUILD THE CLASSES AND USE " << endl;
    cout << "  CLOCKS AND PERSON ENTITIES ARE OUR INTEREST " << endl;
    cout << "  LET'S START " << endl;

    // PROCESS VARIABLES
    Clocks c1(13,45);
    cout << c1.printClocks();

    Clocks c2(c1);
    c2.addM();
    cout << c2.printClocks();


    string n = "djsnjkds";
    Person p1(n);
    Person p2(n);
    p2.AddClock(c2);
    Person p3(n);
    p3.AddClock(c2);

    cout << p3.askHour();
    cout << p2.askHour();
    p2.removeClock();
    p3.AddClock(c2);
    cout << p2.askHour();
    cout << "end";

    // dynamic version
    /* vector<Clocks> clocks;
    vector<Person> persons;
    CCTPActionOption(clocks, persons); */
}

/* void CCTPActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) CREATE A CLOCKs " << endl;
    cout << "  2) CLONE A CLOCKs " << endl;
    cout << "  3) PRINT A CLOCKs  " << endl;
    cout << "  4) PRINT ALL CLOCKS  " << endl;
    cout << "  0) EXIT " << endl;
}

void CCTPActionOption(vector<Clocks> &c,vector<Person> &p)
{
    int option = -1;
    string action;
    do
    {
        // always show action option to users
        CCTPActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (TryParse(action, option, 5, 0) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY AND GOOD BYE " << endl;
            break;
        case 1:
            // CHROMATIC IMAGE GEN
            CreateClocks(c);
            break;
        case 2:
            // code load
            CloneClocks(c);
            break;
        case 3:
            // code print 1
            PrintAClocks(c);
            break;
        case 4:
            // computing
            PrintAllClocks(c);
            break;
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}


void CreateClocks(vector<Clocks> &c)
{
    int m,h;
    string path,input;
    // load first matrix
    cout << "Clocks Creation...." << endl;
    // gettng first param
    do
    {
        cout << "\n  PLEASE HIT THE MINUTE OF THE CLOCKs " << endl;
        path = getInputUser();
    } while (TryParse(path, m, 60, 0) == false);

    do
    {
        cout << "\n  PLEASE HIT THE MINUTE OF THE CLOCKs " << endl;
        input = getInputUser();
    } while (TryParse(input, h, 24, 0) == false);
    Clocks *clock = new Clocks(h,m);
    c.push_back(*clock);
}

void CloneClocks(vector<Clocks> &c)
{
    int index;
    int l = static_cast<int>(c.size());
    string path;
    // load first matrix
    cout << "Clocks Clone...." << endl;
    // gettng first param
    do
    {
        cout << "\n  PLEASE HIT THE INDEX OF THE CLOCKs " << endl;
        path = getInputUser();
    } while (TryParse(path, index, l, 0) == false);
    Clocks *n = new Clocks(c[index]);
    c.push_back(*n);
}

void PrintAClocks(vector<Clocks> &c)
{
    int index;
    int l = static_cast<int>(c.size());
    string path;
    // load first matrix
    cout << "Clocks Clone...." << endl;
    // gettng first param
    do
    {
        cout << "\n  PLEASE HIT THE INDEX OF THE CLOCKs " << endl;
        path = getInputUser();
    } while (TryParse(path, index, l, 0) == false);
    c[index].printClocks();
}

void PrintAllClocks(vector<Clocks> &c)
{
    int f = static_cast<int>(c.size());
    for (int i = 0; i<f; i++){
        cout << "Clocks n°" << i << "";
        c[i].printClocks();
    }
} */