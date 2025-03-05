all:
	gcc -c ./src/tabuleiro.c -I ./include -o ./obj/tabuleiro.o
	cc -c ./src/jogador.c -I ./include -o ./obj/jogador.o
	gcc ./app/Main.c ./obj/*.o -I ./include -o ./bin/app

run:
	./bin/app