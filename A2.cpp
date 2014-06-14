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
    vector<int> intVec;
    intVec = readFile("pages.txt");
    for_each(intVec.begin(), intVec.end(), printInt);
//	printFaults((opt(str), lru(str), clk(str), fifo(str));
}

void printInt(int i){
    cout << i << endl;
}

void promptUser(){
//Upon startup, prompt the user for the number of frames in main memory 
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
void opt(string str){
//print faults
}
int lru(int* array, int length){
    int pageMem[50]={0}; //frame
    int lruFaults = 0; 

	for (int i=0; i<=length; i++){					//for all ints in array 
		for (int j = 0; j <= length -1; j++){		
			if( pageMem[j] == 0 ){  				//checks if empty 
				lruFaults++;
				pageMem[j] = array[i]; 	
				break; 
			}
			if( pageMem[j] == array[i]){ 			//compare to check if existing
				int t = pageMem[j];  
				int current = j;
				while(current != 0){
					pageMem[current] = pageMem[current-1];
					current--;
					}
				pageMem[0]=t;
				break;  
			}
			else{
				int t = array[i];  			// grab current element to put at top
				int current = length -1;    //last pos in the array
				while(current != 0){
					pageMem[current] = pageMem[current-1];
					current--;
				}
			pageMem[0]=t;
			lruFaults++;
			}

		}
	return lruFaults;
	}
}

int clk(string str){
//return faults
}
int fifo(string str){
//return faults
}

int printFaults(int opt, int lru, int clk, int fifo){
//	cout << "The OPT Method Generates "<<opt<< " Page Faults. "<<endl;
//    cout << "The LRU Method Generates "<<lru<< " Page Faults. "<<endl;
//	cout << "The CLOCK Method Generates "<<clk<< " Page Faults. "<<endl;
//	cout << "The FIFO Method Generates "<<fifo<< " Page Faults. "<<endl;
}	
	












