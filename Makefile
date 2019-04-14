main.o: main.cpp sign_in.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

sign_in.o: sign_in.h sign_in.cpp
	g++ -pedantic-errors -std=c++11 -c sign_in.cpp

main: main.o sign_in.o
	g++ -pedantic-errors -std=c++11 main.o sign_in.o -o main
