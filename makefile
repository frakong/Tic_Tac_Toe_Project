tic_tac_toe.out: main.o setup_game.o play_game.o cleanup_game.o 
	gcc -g -Wall -Werror -o tic_tac_toe.out main.o setup_game.o play_game.o cleanup_game.o

main.o: main.c setup_game.h play_game.h cleanup_game.h
	gcc -g -Wall -Werror -c main.c

setup_game.o: setup_game.c setup_game.h
	gcc -g -Wall -Werror -c setup_game.c

play_game.o: play_game.c play_game.h
	gcc -g -Wall -Werror -c play_game.c

cleanup_game.o: cleanup_game.c cleanup_game.h
	gcc -g -Wall -Werror -c cleanup_game.c

clean:
	rm -f *.o *.out
