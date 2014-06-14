###########################################################
# File Name     : makefile
# Author        : Katie Brigham, Shawn Vega
# Class Accounts: masc,1420, masc1440
# Class         : CS 570, Summer 2014
# Assignment    : Assignment 1
# Description   : Programming Assignment 1 in C++
###########################################################
EXEC =sem
CC =g++
SOURCES=A1.cpp
FLAGS= -lpthread -lposix4

$(EXEC): 
	$(CC) -o $(EXEC) $(SOURCES) $(FLAGS)
	rm -f *.o

clean:
	rm -f *.o core a.out $(EXEC)

#######################[ EOF: Makefile ]###################