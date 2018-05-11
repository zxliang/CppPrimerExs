tester: main.o
	g++ -o tester main.o

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -std=c++11

clean:
	rm -f main.o tester
