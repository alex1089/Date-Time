all: test
	
test: Date.o Time.o DateTime.o main.o
	g++490 -std=c++11 -Wall Date.o Time.o DataTime.o CISP400V9AD4.o -o test
Date.o:
	g++490 -std=c++11 -Wall  -c Date.cpp
Time.o: 
	g++490 -std=c++11 -Wall  -c Time.cpp
DateTime.o:
	g++490 -std=c++11 -Wall -c DateTime.cpp
main.o:
	g++490 -std=c++11 -Wall -c CISP400V9AD4.cpp


