//================================================================
// Name        : A2.cpp
// Author      : Katie Brigham MASC1420, Shawn Vega MASC1440
// Description : Assignment 2, CS570 Summer 2014
//================================================================
#include "A2.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>

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
    string teststr;
    cout << "test";
    teststr = readFile("pages.txt");
	printFaults((opt(str), lru(str), clk(str), fifo(str));
	}


void promptUser(){
//Upon startup, prompt the user for the number of frames in main memory 
}
string readFile(char* filename){
    ifstream infile(filename);
    string line = "";
    getline(infile, line); //iterates each line in file
    stringstream strstr(line);
    string word = "";
    //while (getline(strstr,word, ' ')){ // this while loop helps skip blank spaces.
    int intResult;
    stringstream convert(word);
    if ( !(convert >> intResult) ){  // word is not in intResult
        intResult = 0;   // failed to convert
    }
          //  array[count1]= intResult; // stores all the seperate ints into our array to use.
          //  count1++;
    return "test";
}
void opt(string str){
//print faults
}
int lru(string str){
    int pageMem[50]={0};
    int lruFaults = 0; // variable that adds up the fault pages.
    int breakFlag = 0;

	for (int i=0; i<=(int)str.size(); i++){
		for (int j = 0; j <= frameSize -1; j++){
			if( pageMem[j] == 0 ){  //checks if empty 
				lruFaults++;
				pageMem[j] = array[i]; 
				breakFlag = 1;
				break; 
			}
			if( pageMem[j] == array[i]){ //checks if existing
				int t = pageMem[j];  // grab current element to promote
				int current = j;
				while(current != 0){
					pageMem[current] = pageMem[current-1];
					current--;
			}
			pageMem[0]=t;
			breakFlag = 1;
			break;  
			}
		}
		if(breakFlag == 0){
			int t = array[i];  // grab current element to put at top
			int current = frameSize -1;    //last pos in the array
			while(current != 0){
				pageMem[current] = pageMem[current-1];
				current--;
			}
			pageMem[0]=t;
			lruFaults++;
		}
	return lruFaults
	}

}


}
int clk(string str){
//return faults
}
int fifo(string str){
//return faults
}

int printFaults(int opt, int lru, int clk, int fifo){
}
	cout << "The OPT Method Generates "<<opt<< " Page Faults. "<<endl;
    cout << "The LRU Method Generates "<<lru<< " Page Faults. "<<endl;
	cout << "The CLOCK Method Generates "<<clk<< " Page Faults. "<<endl;
	cout << "The FIFO Method Generates "<<fifo<< " Page Faults. "<<endl;
}	
	












