main: *.o
	g++ -std=c++98 -o main *.o

*.o: *.cpp FACTORY/*.cpp
	g++ -c *.cpp FACTORY/*.cpp

run: main
	./main
    
clean:
	rm *.o main