all: 
	g++ main.cpp -g -o run.bin
	./run.bin
compile:
	g++ main.cpp -g -o run.bin
run:
	./run.bin
