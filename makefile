main: *.o
	g++ -std=c++98 -o main *.o

*.o: *.cpp
	g++ -c *.cpp

run: main
	./main
    
clean:
	rm *.o main