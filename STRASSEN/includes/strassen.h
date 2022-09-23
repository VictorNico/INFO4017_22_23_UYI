/*
 * strassen.h
 */

#ifndef __STRASSEN_H__
#define __STRASSEN_H__

#include <iostream>

#include "utils.h"

void LoadMatrix(Matrix &);
void SaveMatrix(Matrix &);
void ActionOption(Matrix &, Matrix &, Matrix &);
void ActionMenu();
bool tryParse(string &, int &);

#endif