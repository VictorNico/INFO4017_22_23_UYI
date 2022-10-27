/*
 * pgcb.h
 */

#ifndef __PGCB_H__
#define __PGCB_H__

#include "matrix.h"

void PGCBLoadMatrix(Matrix &);
void PGCBActionOption(Matrix &, int &, int &, int &);
void PGCBActionMenu();
void PGCBLauncher();
void PGCBLoadMatrix(Matrix &);
void PGCBGenerator();
void PGCBRunner(Matrix &, int &, int &, int &);
void PGCBPrintResult(Matrix &, int &, int &, int &);

#endif