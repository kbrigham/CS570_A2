###########################################################
# File Name     : makefile
# Author        : Katie Brigham, Shawn Vega
# Class Accounts: masc,1420, masc1440
# Class         : CS 570, Summer 2014
# Assignment    : Assignment 2
# Description   : Programming Assignment 2 in C++
###########################################################
EXEC =A2.exe
CC =g++
SOURCES=A2.cpp
FLAGS=

$(EXEC): 
	$(CC) -o $(EXEC) $(SOURCES) $(FLAGS)
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

#######################[ EOF: Makefile ]###################