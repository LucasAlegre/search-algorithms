all: Main.cpp
	g++ -std=c++11 -O3 -o main Main.cpp 

clean:
	rm -f *.o
	rm -f main
	rm -f *.csv