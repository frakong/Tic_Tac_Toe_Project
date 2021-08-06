//This file includes the functions that have to do with playing the game, such as displaying the current state of the board, getting inputted player moves, updating the board, and checking to see if someone won or there is a tie.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "play_game.h"

void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character){
  int moveRow, moveCol;
  display_board();
  do{
    get_move_from_player();
    update_board();
    display_board();
  } while (!is_game_over());
  declare_results_of_game();
}