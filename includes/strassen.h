/*
 * strassen.h
 */

#ifndef __STRASSEN_H__
#define __STRASSEN_H__


#include "matrix.h"

void StrassenLoadMatrix(Matrix &);
void StrassenSaveMatrix(Matrix &);
void StrassenActionOption(Matrix &, Matrix &, Matrix &);
void StrassenActionMenu();
bool StrassenTryParse(string &, int &);
void StrassenLauncher();

#endif