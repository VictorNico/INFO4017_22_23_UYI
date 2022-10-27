/*
 * PGCB.cpp
 */

#include "./includes/pgcb.h"

void PGCBLauncher()
{

    // welcome menu
    cout << "  WELCOME TO PGCB IMPLEMENTATION " << endl;
    cout << "  YOU'RE ABLE TO THE HIGHEST WHITE SQUARE INSIDE AN IMAGE " << endl;
    cout << "  YOU JUST NEED TO ENTER PATH OF DIFFERENTS " << endl;
    cout << "  MATRIX WITH THE FOLLOWING STRUCTURE " << endl;
    cout << "  SQUARE_DIM " << endl;
    cout << "  ITEM_11,ITEM_12,...,ITEM_1SQUARE_DIM " << endl;
    cout << "  ITEM_21,ITEM_22,...,ITEM_2SQUARE_DIM " << endl;
    cout << "  ITEM_31,ITEM_32,...,ITEM_3SQUARE_DIM " << endl;
    cout << "  ITEM_SQUARE_DIM1,ITEM_SQUARE_DIM2,...,ITEM_SQUARE_DIMSQUARE_DIM " << endl;
    cout << "  EACH ITEM CAN BE 0 OR 1 " << endl;
    cout << "  LET'S START " << endl;

    // variables and constant declaration
    Matrix m1;
    int len, index_x, index_y;

    PGCBActionOption(m1, len, index_x, index_y);
}

void PGCBActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) GENERATE RANDOM IMAGE " << endl;
    cout << "  2) LOAD IMAGE " << endl;
    cout << "  3) PRINT RESULT  " << endl;
    cout << "  4) PGCB (IMAGE) " << endl;
    cout << "  0) EXIT " << endl;
}

void PGCBActionOption(Matrix &m1, int &len, int &index_x, int &index_y)
{
    int option = -1;
    string action;
    do
    {
        // always show action option to users
        PGCBActionMenu();

        // get users option from command line
        // gettng path
        do
        {

            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getInputUser();
            // cout << tryParse(action, option) << option << endl;
        } while (TryParse(action, option,5,0) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY AND GOOD BYE " << endl;
            break;
        case 1:
            // CHROMATIC IMAGE GEN
            PGCBGenerator();
            break;
        case 2:
            // code load
            PGCBLoadMatrix(m1);
            break;
        case 3:
            // code print 1
            PGCBPrintResult(m1, len, index_x, index_y);
            break;
        case 4:
            // computing
            if(m1.getRows() == 0){
                cout << "\n please first load the chromatic image matrix" << endl;
                break;
            }
            PGCBRunner(m1, len, index_x, index_y); 
            break;
        default:
            // code default
            break;
        }

    } while (option != 0);

    // Exiting message
}

void PGCBLoadMatrix(Matrix &m)
{

    string path;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE FIRST MATRIX PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        flag = Matrix::readMatrix(m, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}

void PGCBGenerator()
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
            cout << "\n  PLEASE HIT THE MONOCHROME IMAGE PATH " << endl;
            path = getInputUser();
        } while (path.length() == 0);

        do
        {
            cout << "\n  PLEASE HIT THE SQUARE DIM " << endl;
            input = getInputUser();
        } while (TryParse(input, a, 10000, 1) == false);

        flag = Matrix::GenMonochroneImageMatrix(a, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}