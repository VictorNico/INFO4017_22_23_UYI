/*
 * strassen.h
 */

#ifndef __STRASSEN_H__
#define __STRASSEN_H__

#include "matrix.h"

class strassen: public Matrix
{
public:
    static Matrix strassenMultiply(Matrix, Matrix);
    

}

#endif