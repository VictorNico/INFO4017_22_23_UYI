/*
 * strassen.cpp
 */

#include <stdexcept>
#include "./includes/utils.h"

using namespace std;

int main(){


    // welcome menu
    cout << "  \t\tINFO4017 INF DEPTINF UYI " << endl;
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
    string input1;
    bool flag = false;
    Matrix m1,m2;

    // load first matrix
    do
    {
        // gettng path
        do
        {
            cout << "  PLEASE HIT THE FIRST MATRIX PATH " << endl;
            input1 = getPath();
        } while (input1.length() > 0);

        flag = Matrix::readMatrix(m1, input1);
    } while (flag == true);

    Matrix::printMatrix(m1);
    return 0;
}