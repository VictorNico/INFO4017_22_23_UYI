/*
 * strassen.cpp
 */

#include <stdexcept>
#include "./includes/matrix.h"
#include "./includes/strassen.h"

using namespace std;

void StrassenLauncher()
{

    // welcome menu
    cout << "  WELCOME TO STRASSEN IMPLEMENTATION " << endl;
    cout << "  YOU'RE ABLE TO MULTIPLY TWO SQUARE MATRIX " << endl;
    cout << "  YOU JUST NEED TO ENTER PATH OF DIFFERENTS " << endl;
    cout << "  MATRIX WITH THE FOLLOWING STRUCTURE " << endl;
    cout << "  SQUARE_DIM " << endl;
    cout << "  ITEM_11,ITEM_12,...,ITEM_1SQUARE_DIM " << endl;
    cout << "  ITEM_21,ITEM_22,...,ITEM_2SQUARE_DIM " << endl;
    cout << "  ITEM_31,ITEM_32,...,ITEM_3SQUARE_DIM " << endl;
    cout << "  ITEM_SQUARE_DIM1,ITEM_SQUARE_DIM2,...,ITEM_SQUARE_DIMSQUARE_DIM " << endl;
    cout << "  LET'S START " << endl;

    // variables and constant declaration
    // bool flag = false;
    Matrix m1,m2,mf;

    StrassenActionOption(m1, m2, mf);
}

bool StrassenTryParse(string &input, int &output)
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

void StrassenActionMenu()
{
    cout << "\n\n  HIT THE NUMBER BEHIND THE ACTION TO LAUNCH " << endl;
    cout << "  1) LOAD MATRIX 1 " << endl;
    cout << "  2) LOAD MATRIX 2 " << endl;
    cout << "  3) PRINT MATRIX 1 " << endl;
    cout << "  4) PRINT MATRIX 2 " << endl;
    cout << "  5) STRASSEN(MATRIX1,MATRIX2) " << endl;
    cout << "  6) SAVE RESULT MATRIX " << endl;
    cout << "  7) PRINT RESULT MATRIX " << endl;
    cout << "  0) EXIT " << endl;
}

void StrassenActionOption(Matrix &m1, Matrix &m2, Matrix &mf)
{
    int option = -1;
    string action;
    do{
        // always show action option to users
        StrassenActionMenu();

        // get users option from command line
        // gettng path
        do
        {
            
            cout << "\n  CHOOSE YOUR ACTION " << endl;
            action = getPath();
            // cout << tryParse(action, option) << option << endl;
        } while (StrassenTryParse(action, option) == false);

        // custom action for each action choose
        switch (option)
        {
        case 0:
            // Exiting message
            cout << " THANKS FOR YOUR RELIABILITY AND GOOD BYE " << endl;
            break;
        case 1:
            // code load 1
            StrassenLoadMatrix(m1);
            break;
        case 2:
            // code load 2
            StrassenLoadMatrix(m2);
            break;
        case 3:
            // code print 1
            Matrix::printMatrix(m1);
            break;
        case 4:
            // code print 2
            Matrix::printMatrix(m2);
            break;
        case 5:
            // code strassen
            Matrix::PreActed(m1,m2);
            mf = Matrix::strasseMult(m1,m2); 
            break;
        case 6:
            // code save result
            StrassenSaveMatrix(mf);
            break;
        case 7:
            // code print result
            Matrix::printMatrix(mf);
            break;
        default:
            // code default
            break;
        }

    }while(option != 0);

    // Exiting message
}

void StrassenLoadMatrix(Matrix &m)
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
            path = getPath();
        } while (path.length() == 0);

        flag = Matrix::readMatrix(m, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);

}

void StrassenSaveMatrix(Matrix &m)
{

    string path;
    bool flag = false;
    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "\n  PLEASE HIT THE RESULT MATRIX PATH " << endl;
            path = getPath();
        } while (path.length() == 0);

        flag = Matrix::writeMatrix(m, path);
        flag ? cout << " PROCESS COMPLETED\n" : cout << " AND ERROR OCCUR\n";
    } while (flag == false);
}