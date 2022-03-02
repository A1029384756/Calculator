all: Calculator clean

Calculator: main.o Calculator.o
	@g++ -o Calculator main.o Calculator.o

test: testing.o Calculator.o
	@g++ -o test testing.o Calculator.o
	@./test
	@rm test
	@rm -f *.o

main.o:	main.cpp
	@g++ -c main.cpp

testing.o: testing.cpp
	@g++ -c testing.cpp

Calculator.o: Calculator.hpp Calculator.cpp
	@g++ -c Calculator.cpp

clean:
	@rm -f *.o