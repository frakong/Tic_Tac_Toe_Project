//This file includes the functions that have to do with playing the game, such as displaying the current state of the board, getting inputted player moves, updating the board, and checking to see if someone won or there is a tie.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "play_game.h"

void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character){
  int moveRow, moveCol;
  display_board(*game_board, game_board_size);
  do{
    get_move_from_player();
    update_board();
    display_board(*game_board, game_board_size);
  } while (!is_game_over());
  declare_results_of_game();
}

void display_board(char** game_board, int game_board_size){
  for (int display_row = 0; display_row < game_board_size; display_row++){
    printf("%d  ", display_row);
    for (int display_col = 0; display_col < game_board_size; display_col++){
      printf("%c ", game_board[display_row][display_col]);
    }
    printf("\n");
  }
  printf("   ");
  for (int last_line_position = 0; last_line_position < game_board_size; last_line_position++){
    printf("%d ", last_line_position);
  }
  printf("\n");
}