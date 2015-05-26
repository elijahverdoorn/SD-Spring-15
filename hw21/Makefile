DVDArrayP.o:  DVDArrayP.cpp DVDArrayP.h
	g++ -g -Wall -std=c++11 -c DVDArrayP.cpp

DVDArrayPDriver:  DVDArrayP.o DVDArrayPDriver.o
	g++ -g -Wall -std=c++11 -o DVDArrayPDriver DVDArrayP.o DVDArrayPDriver.o

DVDArrayPDriver.o: DVDArrayP.o DVDArrayP.cpp
	g++ -g -Wall -std=c++11 -c DVDArrayPDriver.cpp