show: build print

debug: main.cpp logic.cpp
	g++ -g main.cpp logic.cpp -o main.debug

build: main.o logic.o
	g++ main.o logic.o -o result.out

rebuild: clean build

logic.o: logic.cpp logic.hpp
	g++ -c logic.cpp

main.o: main.cpp logic.hpp
	g++ -c main.cpp

print:
	./result.out

clean:
	rm -r *.out *.debug*