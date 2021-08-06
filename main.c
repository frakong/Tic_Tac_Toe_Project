//This contains the main function of the program. This will run the main function, which 
//sets the program into action. The main function will call the 3 functions that execute
//the 3 main parts I mentioned in outline.txt: Setting up the game, playing the game, and
//cleaning up the game.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup_game.h"
#include "play_game.h"
//#include "cleanup_game.h"

int main(int argc, char** argv){
  char** game_board;
  char* game_pieces;
  int game_board_size;
  int current_turn;
  char blank_character = 'e';
  

  setup_game(argc, argv, &game_board, &game_pieces, &game_board_size, &current_turn, blank_character);
  play_game(&game_board, game_pieces, game_board_size, &current_turn, blank_character);
  cleanup_game();
  return 0;
}