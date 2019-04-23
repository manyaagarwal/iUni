edit_details.o: edit_details.cpp edit_details.h useful_functions.h
	g++ -pedantic-errors -std=c++11 -c edit_details.cpp

search_people.o: search_people.cpp search_people.h useful_functions.h
	g++ -pedantic-errors -std=c++11 -c search_people.cpp

useful_functions.o: useful_functions.cpp useful_functions.h
	g++ -pedantic-errors -std=c++11 -c useful_functions.cpp

main.o: main.cpp sign_in.h sign_up.h useful_functions.h search_people.h edit_details.h
	g++ -pedantic-errors -std=c++11 -c main.cpp

sign_in.o: sign_in.h sign_in.cpp useful_functions.h
	g++ -pedantic-errors -std=c++11 -c sign_in.cpp

sign_up.o: sign_up.h sign_up.cpp useful_functions.h
	g++ -pedantic-errors -std=c++11 -c sign_up.cpp

main: main.o sign_in.o sign_up.o useful_functions.o search_people.o
	g++ -pedantic-errors -std=c++11 main.o sign_in.o useful_functions.o search_people.o edit_details.o sign_up.o -o main
