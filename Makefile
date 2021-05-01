build:
	g++ -c test.cpp
	g++ test.o -o AsciiMachine -lsfml-graphics -lsfml-window -lsfml-system -O3
run:
	./AsciiMachine