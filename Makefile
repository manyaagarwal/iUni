.PHONY: main
main:
	touch UserInfo.txt

	touch CourseInfo.txt

	g++ -pedantic-errors -std=c++11 -c student.cpp

	g++ -pedantic-errors -std=c++11 -c edit_details.cpp

	g++ -pedantic-errors -std=c++11 -c search_people.cpp

	g++ -pedantic-errors -std=c++11 -c global_data.cpp

	g++ -pedantic-errors -std=c++11 -c main.cpp

	g++ -pedantic-errors -std=c++11 -c sign_in.cpp

	g++ -pedantic-errors -std=c++11 -c sign_up.cpp

	g++ -pedantic-errors -std=c++11 -c instructor.cpp

	g++ -pedantic-errors -std=c++11 -c courses.cpp

	g++ -pedantic-errors -std=c++11 -c assignments.cpp

	g++ -pedantic-errors -std=c++11 -c instructor_course.cpp

	g++ -pedantic-errors -std=c++11 -c student_course.cpp

	g++ -pedantic-errors -std=c++11 main.o sign_in.o global_data.o search_people.o edit_details.o sign_up.o student.o instructor.o courses.o assignments.o instructor_course.o student_course.o -o main
