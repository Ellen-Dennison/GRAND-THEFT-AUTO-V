main: *.o
	g++ -std=c++11 -o main *.o

*.o: *.cpp FACTORY/*.cpp DECORATOR/*.cpp COMPOSITE/*.cpp
	g++ -c *.cpp FACTORY/*.cpp DECORATOR/*.cpp COMPOSITE/*.cpp

run: main
	./main
    
clean:
	rm *.o main


valgrind:
	valgrind --leak-check=yes --track-origins=yes ./main