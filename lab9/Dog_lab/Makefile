current: DogArrayP_driver

Dog.o: Dog.cpp Dog.h
	g++  -Wall  -std=c++11  -c  Dog.cpp

Dog_driver.o: Dog.o Dog_driver.cpp Dog.h
	g++  -Wall  -std=c++11  -c  Dog_driver.cpp

Dog_driver: Dog_driver.o Dog.o
	g++  -Wall  -std=c++11  -o  Dog_driver  Dog_driver.o Dog.o

DogArrayP.o: DogArrayP.cpp DogArrayP.h Dog.h
	g++  -Wall -std=c++11 -c DogArrayP.cpp

DogArrayP_driver.o: DogArrayP.o DogArrayP_driver.cpp Dog.h DogArrayP.h
	g++ -Wall -std=c++11 -c DogArrayP_driver.cpp

DogArrayP_driver: DogArrayP_driver.o DogArrayP.o
	g++ -Wall -std=c++11 -o DogArrayP_driver DogArrayP_driver.o DogArrayP.o Dog.o

OwnedDog.o: OwnedDog.cpp OwnedDog.h Dog.h
	g++ -Wall -std=c++11 -c OwnedDog.cpp

OwnedDog_driver.o: OwnedDog.o OwnedDog_driver.cpp Dog.h OwnedDog.h
	g++ -Wall -std=c++11 -c OwnedDog_driver.cpp

OwnedDog_driver: OwnedDog_driver.o OwnedDog.o
	g++ -Wall -std=c++11 -o OwnedDog_driver OwnedDog_driver.o OwnedDog.o Dog.o