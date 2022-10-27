/*
 * pgcb_f.cpp
 */

#include "../includes/pgcb.h"

bool Matrix::GenMonochroneImageMatrix(int len, string path)
{
    // Create the martix with dimension
    Matrix A(len, len);
    // load matrix information from the file
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int index = (int)(rand() % 2);
            A.p[i][j] = index;
        }
    }
    return Matrix::writeMatrix(A, path);
    return false;
}

void PGCBRunner(Matrix &_m, int &_l, int &_x, int &_y)
{
    // Create the matrix of dynamic programmation
    int _size = _m.getRows();
    Matrix PGCB(_size, _size);
    _l = 0;
    // fullfil the matrix
    for (int x = 0; x < _size; x++)
    {
        for (int y = 0; y < _size; y++)
        {
            if(_m.getVal(x,y) != 1){
                if(x == 0 || y == 0){
                    PGCB.setVal(x,y,1);
                    if (_l <= 1)
                    {
                        _l = 1;
                        _x = x;
                        _y = y;
                    }
                }
                else{
                    int k = 1 + min(
                                    PGCB.getVal(x - 1, y - 1),
                                    min(
                                        PGCB.getVal(x, y - 1),
                                        PGCB.getVal(x - 1, y)));
                    PGCB.setVal(x,y,k);
                    // if the _l < k, save the new highest white square solution
                    if(_l <= k){
                        _l = k;
                        _x = x;
                        _y = y;
                    }

                }
            }
        }
    }
}

void PGCBPrintResult(Matrix &_m, int &_pgcb, int &_x, int &_y)
{

    // Write the matrix DIMENSION
    cout << "Image Matrix DIMENSION : " << _m.getRows() << endl;
    cout << "Image Matrix PGCB : " << _pgcb << endl;
    cout << "Image Matrix PGCB (X,Y) : (" << _x << "," << _y << ")" << endl;
    cout << "Image Matrix Content :" << endl;
    // save  matrix information from the file
    for (int i = 0; i < _m.getRows(); i++)
    {
        for (int j = 0; j < _m.getRows(); j++)
        {
            // If is the last row info
            if (j == _m.getRows() - 1)
            {
                if (i <= _x && i >= (_x - _pgcb / 2) && j <= _y && j >= (_y - _pgcb / 2))
                {
                    cout << "\033[1;31m" << _m.getVal(i, j) << "\033[0m" << endl;
                }else{
                    cout << _m.getVal(i, j) << endl;
                }
            } // Else
            else
            {
                if (i <= _x && i >= (_x - _pgcb/2) && j <= _y && j >= (_y - _pgcb / 2))
                {
                    cout << "\033[1;31m" << _m.getVal(i, j) << "\033[0m" << ',';
                }
                else
                {
                    cout << _m.getVal(i, j) << ',';
                }
            }
        }
    }
}

