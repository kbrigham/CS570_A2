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
    const int PAGESIZE = 5;
    string fname = "pages.txt";
    char *fileName; 
    strncpy(fileName, fname.c_str(), strlen(fname.c_str()) + 1);
    
    vector<int> intVec;
    intVec = readFile(fileName);
    //for_each(intVec.begin(), intVec.end(), printInt);
    opt(intVec, PAGESIZE);
    lru(intVec, PAGESIZE);
    clk(intVec, PAGESIZE);
    fifo(intVec, PAGESIZE);
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

void opt(const vector<int> &vec, const int PAGESIZE){
    int faults = 0;
    int lastItem = 0;
    int pageMem[PAGESIZE][2];
    int arrow = 0;
    const int VECSIZE = vec.size();
    //const int VECSIZE = 20;

    
    clkZeros(pageMem, PAGESIZE);
    for(int x = 0; x < VECSIZE; x++){
        int loc;
        decrement(pageMem, PAGESIZE);
        int nextInst= -1;
        //cout << "nextInst(-1) =" << nextInst << endl;

        loc = contains(vec[x],pageMem, PAGESIZE);
        
        //////////////////////////////////////////////////
        //debugger(vec[x],pageMem, PAGESIZE);
        //cout << "looking at " << vec[x] << endl;
        //////////////////////////////////////////////////
        
        if ( loc == -1){
            faults++;
            loc = findBest(pageMem, PAGESIZE);
            //cout << "loc = "<< loc << endl;
            pageMem[loc][0] = vec[x];
            //cout << "vec[x] = "<< vec[x] << endl;
            //cout << "PageMem[loc][0] = "<< pageMem[loc][0] << endl;
        }
        for(int s = x; s < VECSIZE - 1;){
        s++;
            //cout << " x =" << x << " s =" << s ;
            //cout << "nextInst =" << nextInst << endl;
            if((nextInst == -1) && (vec[s] == pageMem[loc][0])){
                //cout << "nextInst in for =" << s-x << endl;
                nextInst = s-x;
                }
        }
        //cout << "nextInst =" << nextInst << endl;
        pageMem[loc][1] = nextInst;
    }
    cout << "opt faults = " << faults << endl;
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

void clk(const vector<int> &vec, const int PAGESIZE){
    int faults = 0;
    int lastItem = 0;
    int pageMem[PAGESIZE][2];
    //int clockFlag[PAGESIZE];
    int arrow = 0;
    const int VECSIZE = vec.size();
    
    clkZeros(pageMem, PAGESIZE);
    for(int x = 0; x < VECSIZE; x++){
        int loc;
        if ( (loc = contains(vec[x],pageMem, PAGESIZE)) != -1){
            pageMem[loc][1] = 1;
        }
        else{
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

void clkZeros(int pageMem[][2], int SIZE){
    for(int x = 0; x < SIZE; x++){
    pageMem[x][0] =0;
    pageMem[x][1] =0;
    }
}

int contains(const int VALUE,const int arr[][2], const int ARRSIZE){
    for(int x = 0; x < ARRSIZE; x++)
        if(arr[x][0] == VALUE)
            return x;
    return -1;
}

void decrement(int pageMem[][2], int SIZE){
    for(int x = 0; x < SIZE; x++){
    pageMem[x][1]--;
    }
}

int findBest(int pageMem[][2], int SIZE){
    int high = 0;
    for(int x = 0; x < SIZE; x++){
    if(pageMem[x][1] < 0)
        return x;
    } 
    for(int x = 0; x < SIZE; x++){
        if(pageMem[x][1] > pageMem[high][1])
            high =x;
    }
    return high;
}

void debugger(const int VALUE,const int arr[][2], const int ARRSIZE){
    for(int x = 0; x < ARRSIZE; x++)
        cout << arr[x][0] << "," << arr[x][1] << " ";
    cout <<endl;
}

void printInt(int i){
    cout << i << endl;
}
