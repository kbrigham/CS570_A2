//================================================================
// Name        : A2.cpp
// Author      : Katie Brigham MASC1420, Shawn Vega MASC1440
// Description : Assignment 2, CS570 Summer 2014
//================================================================
#include "A2.h"


using namespace std;
/*
This program shall simulate a process/thread accessing its pages during execution. 
which you shall create. This file shall be located in the same directory as the executable 
and shall contain a series of positive integers representing the pages (by it’s page number) 
which the process/thread is accessing as it performs it’s work. The limit of number of 
pages any process/thread may have is 99. The pages.txt file will contain a single line of 
text where each number is separated by a space character.
*/

int main(){
    const int PAGESIZE = 6;
    string fname = "pages.txt";
    char *fileName; 
    strncpy(fileName, fname.c_str(), strlen(fname.c_str()) + 1);
    
    vector<int> intVec;
    intVec = readFile(fileName);
    //for_each(intVec.begin(), intVec.end(), printInt);
//	printFaults((opt(str), lru(str), clk(str), fifo(str));
    //opt(intVec, SIZE);
    lru(intVec, PAGESIZE);
    clk(intVec, PAGESIZE);
    fifo(intVec, PAGESIZE);
}

void printInt(int i){
    cout << i << endl;
}

int promptUser(){
//Upon startup, prompt the user for the number of frames in main memory 
    return 3;
}
vector<int> readFile(char *filename){
    ifstream infile(filename);
    string line;
    getline(infile, line); //iterates each line in file
    istringstream strstr(line);
    vector<int> intVec;
    string word = "";
    while (getline(strstr,word, ' ')){ // this while loop helps skip blank spaces.
        int result = atoi(word.c_str());
        intVec.push_back(result);
    }

    return intVec;
}
void opt(const vector<int> &vec, const int SIZE){
    //print faults
    int faults = 0;
}

void lru(const vector<int> & vec, const int PAGESIZE){
    //int pageMem[PAGESIZE]; //frame
    deque<int> pageMem (PAGESIZE,0);
    int faults = 0; 
    const int VECSIZE = vec.size();
    //zeros(pageMem, PAGESIZE);
    
    int loc;
    for(int x = 0; x < VECSIZE; x++){
        //debug(vec[x],pageMem);
        if(dequeContains(vec[x], pageMem)){
            loc = dequeFind(vec[x], pageMem);
            //cout << "dequeSwap = 0," << loc << endl;
            dequeSwap(pageMem,0,loc);
        }
        else{
            faults++;
            //cout << "fault for " << vec[x] << endl;
            pageMem.pop_back();
            pageMem.push_front(vec[x]);
            //if(lastItem == PAGESIZE)
            //    lastItem = 0;
        }
    }
    cout << "lru faults = " << faults << endl;
}

void clkZeros(int pageMem[][2], int SIZE){
    for(int x = 0; x < SIZE; x++){
    pageMem[x][0] =0;
    pageMem[x][1] =0;
    }
}

void clk(const vector<int> &vec, const int PAGESIZE){
    int faults = 0;
    int lastItem = 0;
    int pageMem[PAGESIZE][2];
    //int clockFlag[PAGESIZE];
    int arrow = 0;
    const int VECSIZE = vec.size();
    
    clkZeros(pageMem, PAGESIZE);
    for(int x = 0; x < VECSIZE; x++){
        while(true){ 
            if(arrow == PAGESIZE)
                    arrow = 0;
            if(pageMem[arrow][0] == vec[x]){
                pageMem[arrow][1] = 1;
                arrow++;
                break;
            }
            else{
                if(pageMem[arrow][1] == 0){
                    faults++;
                    pageMem[arrow][0] = vec[x];
                    pageMem[arrow][1] = 1;
                    arrow++;
                    break;
                }
                pageMem[arrow][1] = 0;
            }
            arrow++;
        }
    }
    cout << "clk faults = " << faults << endl;
}

void fifo(const vector<int> &vec, const int PAGESIZE){
    int faults = 0;
    int lastItem = 0;
    int pageMem[PAGESIZE];
    const int VECSIZE = vec.size();
    
    zeros(pageMem, PAGESIZE);
    for(int x = 0; x < VECSIZE; x++){
        if(contains(vec[x], pageMem, PAGESIZE))
            continue;
        else{
            faults++;
            pageMem[lastItem++] = vec[x];
            if(lastItem == PAGESIZE)
                lastItem = 0;
        }
    }
    cout << "fifo faults = " << faults << endl;
}

int printFaults(int opt, int lru, int clk, int fifo){
//	cout << "The OPT Method Generates "<<opt<< " Page Faults. "<<endl;
//    cout << "The LRU Method Generates "<<lru<< " Page Faults. "<<endl;
//	cout << "The CLOCK Method Generates "<<clk<< " Page Faults. "<<endl;
//	cout << "The FIFO Method Generates "<<fifo<< " Page Faults. "<<endl;
}	

/////////////////////////////////////////////////////////////////////
// HELPER METHODS BELOW
/////////////////////////////////////////////////////////////////////

int dequeFind(const int VALUE,const deque<int> & deq){
    for(int x = 0; x < deq.size(); x++)
        if(deq[x] == VALUE)
            return x;
    return -1;
}

void dequeSwap(deque<int> & deq,const int loci,const int locj){
    int temp = deq[loci];
    deq[loci] = deq[locj];
    deq[locj] = temp;
}
void debug(const int checking,const deque<int> & deq){
    cout << "Checking for" << checking << "; ";
    for(int x = 0; x < deq.size(); x++){
        cout <<deq[x] << " ";
    }
    cout << endl;
}

bool dequeContains(const int VALUE,const deque<int> deq){
    for(int x = 0; x < deq.size(); x++)
        if(deq[x] == VALUE)
            return true;
    return false;
}

bool contains(const int VALUE,const int arr[], const int ARRSIZE){
    for(int x = 0; x < ARRSIZE; x++)
        if(arr[x] == VALUE)
            return true;
    return false;
}

void zeros(int *arr, const int SIZE){
for (int x = 0; x < SIZE; x++)
    arr[x] = 0;
}











