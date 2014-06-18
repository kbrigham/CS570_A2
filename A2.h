//================================================================
// Name        : A2.h
// Author      : Katie Brigham MASC1420, Shawn Vega MASC1440
// Description : Assignment 2, CS570 Summer 2014
//================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm> //for_each

#include <deque> // might use

using namespace std;

void printInt(int);
int promptUser();
vector<int> readFile(char*);
void opt(const vector<int> &, const int);
void lru(const vector<int> &, const int);
void clk(const vector<int> &, const int);
void fifo(const vector<int> &, const int);
void zeros(int*, const int);
bool contains(const int,const int[], const int);
bool dequeContains(const int,const deque<int>);
void debug(const int,const deque<int> &);
void dequeSwap(deque<int> &,const int,const int);
int dequeFind(const int,const deque<int> &);
void printFaults();
