show: build print

debug: main.cpp logic.cpp
	g++ -g main.cpp logic.cpp -o main.debug

build: main.o logic.o
	g++ main.o logic.o -o game-life -lsfml-graphics -lsfml-window -lsfml-system

rebuild: clean build

logic.o: logic.cpp logic.hpp
	g++ -c logic.cpp

main.o: main.cpp logic.hpp
	g++ -c main.cpp

print:
	./game-life

clean:
	rm -r .debug* game-life