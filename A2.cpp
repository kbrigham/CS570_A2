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
    const int SIZE = 5;
    
    vector<int> intVec;
    intVec = readFile("pages.txt");
    for_each(intVec.begin(), intVec.end(), printInt);
//	printFaults((opt(str), lru(str), clk(str), fifo(str));
    //opt(intVec, SIZE);
    //lru(intVec);
    //clk(intVec);
    fifo(intVec, SIZE);
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
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    //for testing only
    //line = "1 2 3 4 5 6 7 8 9 10 11 12"; //uncomment for testing
    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////
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
    int pageMem[PAGESIZE]; //frame
    int lruFaults = 0; 
    int length = vec.size();
    zeros(pageMem, PAGESIZE);
    
	for (int i=0; i<=length; i++){					//for all ints in array 
		for (int j = 0; j <= length -1; j++){		
			if( pageMem[j] == 0 ){  				//checks if empty 
				lruFaults++;
				//pageMem[j] = array[i]; 	
				break; 
			}
			//if( pageMem[j] == array[i]){ 			//compare to check if existing
				int t = pageMem[j];  
				//int current = j;
				//while(current != 0){
					//pageMem[current] = pageMem[current-1];
					//current--;
					//}
				//pageMem[0]=t;
				//break;  
			//}
			//else{
				//int t = array[i];  			// grab current element to put at top
				//int current = length -1;    //last pos in the array
				//while(current != 0){
					//pageMem[current] = pageMem[current-1];
					//current--;
				//}
			//pageMem[0]=t;
			lruFaults++;
			//}
            
		}
	//return lruFaults;
    }
}

void clk(const vector<int> &vec, const int SIZE){
//return faults
}

bool contains(const int VALUE,const int arr[], const int ARRSIZE){
    for(int x = 0; x < ARRSIZE; x++)
        if(arr[x] == VALUE)
            return true;
    return false;
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
    cout << "faults = " << faults << endl;
}

int printFaults(int opt, int lru, int clk, int fifo){
//	cout << "The OPT Method Generates "<<opt<< " Page Faults. "<<endl;
//    cout << "The LRU Method Generates "<<lru<< " Page Faults. "<<endl;
//	cout << "The CLOCK Method Generates "<<clk<< " Page Faults. "<<endl;
//	cout << "The FIFO Method Generates "<<fifo<< " Page Faults. "<<endl;
}	

void zeros(int *arr, const int SIZE){
for (int x = 0; x < SIZE; x++)
    arr[x] = 0;
}











