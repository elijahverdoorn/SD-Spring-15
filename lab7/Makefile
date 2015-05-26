DVDArray.o:  DVDArray.cpp DVDArray.h
	g++ -g -Wall -std=c++11 -c DVDArray.cpp

DVDArrayDriver:  DVDArray.o DVDArrayDriver.o
	g++ -g -Wall -std=c++11 -o DVDArrayDriver DVDArray.o DVDArrayDriver.o

DVDArrayDriver.o: DVDArray.o DVDArray.cpp
	g++ -g -Wall -std=c++11 -c DVDArrayDriver.cpp