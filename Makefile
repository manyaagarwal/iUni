.PHONY: main
main:
#1\
student.o: student.cpp student.h edit_details.h global_data.h
	g++ -pedantic-errors -std=c++11 -c student.cpp

#2\
edit_details.o: edit_details.cpp edit_details.h global_data.h
	g++ -pedantic-errors -std=c++11 -c edit_details.cpp

#3\
search_people.o: search_people.cpp search_people.h global_data.h
	g++ -pedantic-errors -std=c++11 -c search_people.cpp

#4\
global_data.o: global_data.cpp global_data.h
	g++ -pedantic-errors -std=c++11 -c global_data.cpp

#5\
main.o: main.cpp sign_in.h sign_up.h global_data.h search_people.h edit_details.h student.o
	g++ -pedantic-errors -std=c++11 -c main.cpp

#6\
sign_in.o: sign_in.h sign_in.cpp global_data.h
	g++ -pedantic-errors -std=c++11 -c sign_in.cpp

#7\
sign_up.o: sign_up.h sign_up.cpp global_data.h
	g++ -pedantic-errors -std=c++11 -c sign_up.cpp

#8\
instructor.o:
	g++ -pedantic-errors -std=c++11 -c instructor.cpp

#8\
main: main.o sign_in.o global_data.o search_people.o edit_details.o sign_up.o student.o
	g++ -pedantic-errors -std=c++11 main.o sign_in.o global_data.o search_people.o edit_details.o sign_up.o student.o instructor.o -o main
