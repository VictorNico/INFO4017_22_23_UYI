/*
 * utils.h
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

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
    static bool readMatrix(Matrix &, char *);
    static bool writeMatrix(const Matrix &, char *);
    /* PUBLIC GUI FUNCTIONS
    ********************************/
    static void printMatrix(Matrix);

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
char *getPath();
/* PUBLIC MATRIX DIMENSION FUNCTIONS
 ********************************/

#endif