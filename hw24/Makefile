current: Menu_driver

MenuItem_driver: MenuItem_driver.o Menu.h MenuItem.h
	g++ -g -Wall -std=c++11 -o MenuItem_driver MenuItem_driver.o Menu.o MenuItem.o

MenuItem.o: MenuItem.h Menu.h MenuItem.cpp
	g++ -g -Wall -std=c++11 -c MenuItem.cpp

MenuItem_driver.o: Menu.o MenuItem_driver.cpp MenuItem.h Menu.h 
	g++ -g -Wall -std=c++11 -c MenuItem_driver.cpp

Menu_driver: Menu_driver.o Menu.o MenuItem.h Menu.h Menu.cpp
	g++ -g -Wall -std=c++11 -o Menu_driver Menu.o MenuItem.o Menu_driver.o

Menu.o: Menu.h
	g++ -g -Wall -std=c++11 -c Menu.cpp

Menu_driver.o: Menu_driver.cpp Menu.h MenuItem.h
	g++ -g -Wall -std=c++11 -c Menu_driver.cpp