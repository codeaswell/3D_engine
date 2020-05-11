build:
	gcc -std=c99 ./src/*.c -lSDL2 -o engine;

run:
	./engine;

clean:
	rm engine;
