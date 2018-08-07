/*
 * Merge.h
 *
 *  Created on: 2018Äê5ÔÂ9ÈÕ
 *      Author: Administrator
 */

#ifndef DEAL_H_
#define DEAL_H_

#include "Data.h"
#include <vector>
#include <deque>
#include <iostream>

void Reset(int data [SCALE][SCALE], GINFO  & info);

void DealRight( int data [SCALE][SCALE] );
void DealLeft( int data [SCALE][SCALE] );
void DealUp( int data [SCALE][SCALE] );
void DealDown( int data [SCALE][SCALE] );

void DealInput(int data [SCALE][SCALE], GINFO  & info );
void DealInfo(int data [SCALE][SCALE], GINFO  & info);
void DealData(DIRCT dir,int data [SCALE][SCALE], GINFO  & info );

string GetDirtString( DIRCT  dir);
string GetAreaString( AREA  area);
AREA GetTheArea(DIRCT dir, bool bClear =false );

void GenerateNewEle(int data [SCALE][SCALE],DIRCT dir);
void InsertCorner(  AREA area ,  int data [SCALE][SCALE]);

void ClearZero( vector<int> & aim);
void Merge(vector<int> & aim);
void Merge2(vector<int> & aim);
void  TestMerge();
void Print( vector<int> & aim );

void inital( int data [SCALE][SCALE]  );

#endif /* 2048_MERGE_H_ */
