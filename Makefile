all: main.exe

main.exe: main.cc
	g++ main.cc -o main.exe

run: main.exe 
	./main.exe
