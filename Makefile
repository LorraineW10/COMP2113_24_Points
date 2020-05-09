FLAGS = -pedantic-errors -std=c++11
game.o: game.cpp game.h
	g++ $(FLAGS) -c $<
main.o: main.cpp game.h
	g++ $(FLAGS) -c $<
main: game.o main.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main game.o main.o game.tgz
tar:
	tar -czvf game.tgz *.cpp *.h
.PHONY: clean tar
