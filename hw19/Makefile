DVDdriver: DVD.o DVDdriver.o
	g++ -g -Wall -std=c++11 -o DVDdriver DVD.o DVDdriver.o

DVD.o: DVD.cpp DVDdriver.o
	g++ -g -Wall -std=c++11 -c DVD.cpp

DVDdriver.o: DVD.o DVDdriver.cpp
	g++ -g -Wall -std=c++11 -c DVDdriver.cpp