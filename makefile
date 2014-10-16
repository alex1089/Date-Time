all: test
	
test:
	g++490 -std=c++11 -Wall Date.cpp Time.cpp DateTime.cpp Employee.cpp CISP400V9AD4.cpp -o test

