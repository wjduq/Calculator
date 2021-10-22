output: main2.o
	g++ main2.o -o output

main2.o: main2.cpp
	g++ -c main2.cpp

clean:
	rm* .o
