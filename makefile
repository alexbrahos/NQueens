runMe: Queens.o main.o
	g++ Queens.o main.o -o runMe
Queens.o: Queens.cpp Queens.h
	g++ -c Queens.cpp
main.o: main.cpp Queens.h
	g++ -c main.cpp
clean:
	rm -f *.o
	rm runMe
run: runMe
	./runMe
