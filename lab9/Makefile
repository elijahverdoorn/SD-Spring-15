current: proto-draw

OPTS = -Wall -g -std=c++11
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

proto-draw: proto-draw.o Shape.o Rectangle.o Circle.o
	g++ $(OPTS) -o proto-draw Shape.o Rectangle.o Circle.o proto-draw.o $(LIBS)

proto-draw.o: proto-draw.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-draw.cpp

clean:
	rm -f *.o proto-draw

Rectangledriver:  Rectangle.o RectangleDriver.o Shape.o
	g++ -g -Wall -std=c++11 -o RectangleDriver Rectangle.o RectangleDriver.o Shape.o

Rectangle.o: Rectangle.cpp Shape.h ColorPoint.h Rectangle.h
	g++ -g -Wall -std=c++11 -c Rectangle.cpp

Shape.o: Shape.cpp Shape.h ColorPoint.h
	g++ -g -Wall -std=c++11 -c Shape.cpp

CircleDriver: Circle.o CircleDriver.o Shape.o
	g++ -g -Wall -std=c++11 -o CircleDriver Circle.o CircleDriver.o Shape.o

Circle.o: Circle.cpp Shape.h ColorPoint.h Circle.h
	g++ -g -Wall -std=c++11 -c Circle.cpp

ShapeDriver2: Rectangle.o Circle.o Shape.o ShapeDriver2.o
	g++ -g -Wall -std=c++11 -o ShapeDriver2 Circle.o Shape.o Rectangle.o ShapeDriver2.o

ColorPoint.o: ColorPoint.h
	g++ -g -Wall -std=c++11 -c ColorPoint.cpp

ColorPoint.h: