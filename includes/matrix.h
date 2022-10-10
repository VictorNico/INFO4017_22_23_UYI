/*
 * utils.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
class Matrix
{
public:
    Matrix(int, int);
    Matrix(double **, int, int);
    Matrix();
    ~Matrix();
    Matrix(const Matrix &);
    Matrix(const Matrix &, int);
    Matrix &operator=(const Matrix &);

    inline double &operator()(int x, int y) { return p[x][y]; }

    Matrix &operator+=(const Matrix &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(double);
    Matrix &operator/=(double);
    Matrix operator^(int);

    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, Matrix &);

    void swapRows(int, int);
    Matrix transpose();

    static Matrix createIdentity(int);
    static Matrix strasseMult(Matrix, Matrix);
    static Matrix solve(Matrix, Matrix);
    static Matrix bandSolve(Matrix, Matrix, int);

    /* PUBLIC FILES FUNCTIONS
    ********************************/
    static bool readMatrix(Matrix &, string);
    static bool writeMatrix(const Matrix &, string);
    /* PUBLIC GUI FUNCTIONS
    ********************************/
    static void printMatrix(Matrix);
    static void PreActed(Matrix &, Matrix &);

    // functions on vectors
    static double dotProduct(Matrix, Matrix);

    // functions on augmented matrices
    static Matrix augment(Matrix, Matrix);
    Matrix gaussianEliminate();
    Matrix rowReduceFromGaussian();
    void readSolutionsFromRREF(std::ostream &os);
    Matrix inverse();

private:
    int rows_, cols_;
    double **p;

    void allocSpace();
    Matrix expHelper(const Matrix &, int);
};

Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, double);
Matrix operator*(double, const Matrix &);
Matrix operator/(const Matrix &, double);

/* PUBLIC GUI FUNCTIONS
 ********************************/
string getPath();
/* PUBLIC MATRIX DIMENSION FUNCTIONS
 ********************************/
double **CreateMultiArray(int);
int nextPowOfTwo(int);
bool isPowOfTwo(int);



#endif