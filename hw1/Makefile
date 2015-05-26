tryDog: tryDog.o Dog.o
	g++ -g -Wall -std=c++11 -o tryDog tryDog.o Dog.o

tryDog.o: tryDog.cpp Dog.h
	g++ -g -Wall -std=c++11 -c tryDog.cpp

Dog.o: Dog.cpp Dog.h
	g++ -g -Wall -std=c++11 -c Dog.cpp
