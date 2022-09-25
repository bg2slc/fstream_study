all: 
	g++ main.cpp -ggdb -o run.bin
	./run.bin
compile:
	g++ main.cpp -ggdb -o run.bin
run:
	./run.bin
