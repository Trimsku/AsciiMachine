

build:
	g++ -c test.cpp
	g++ test.o -o AsciiMachine -lsfml-graphics -lsfml-window -lsfml-system -O3 -std=c++17 -lX11
	mv ./AsciiMachine ./bin
run:
	./bin/AsciiMachine
clean:
	rm ./bin/*

build_global:
	g++ global_source_build.cpp -o build_global -lsfml-graphics -lsfml-window -lsfml-system -lX11

run_global:
	./build_global

clean_global:
	rm build_global
#git-init:
#	git add .
#	git commit -m "Create makefile, delete 'register' and Thanks for Myateghnik"
#	git push -u origin main
