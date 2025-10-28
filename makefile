main: *.o
	g++ -std=c++98 -o main *.o

*.o: *.cpp FACTORY/*.cpp DECORATOR/*.cpp
	g++ -c *.cpp FACTORY/*.cpp DECORATOR/*.cpp

run: main
	./main
    
clean:
	rm *.o main


valgrind:
	valgrind --leak-check=yes --track-origins=yes ./main