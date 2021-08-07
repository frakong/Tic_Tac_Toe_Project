//This file includes the functions that have to do with playing the game, such as displaying the current state of the board, getting inputted player moves, updating the board, and checking to see if someone won or there is a tie.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "play_game.h"

void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character){
  int move_row, move_col;
  displayWelcomeMessage(*game_board, game_board_size);
  do{
    get_move_from_player(*game_board, game_board_size, *current_turn, &move_row, &move_col, blank_character);
    update_board(game_board, game_pieces, move_row, move_col, *current_turn);
    change_turn();
    display_board(*game_board, game_board_size);
  } while (!is_game_over());
  declare_results_of_game();
}

void displayWelcomeMessage(char** game_board, int game_board_size){
  printf("Welcome! Let's begin the game!");
  display_board(game_board, game_board_size);
  printf("Good luck!");
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

void get_move_from_player(char** game_board, int game_board_size, int current_turn, int* move_row, int* move_col, char blank_character){
  printf("Player %d, please type in your move in the following format: row# col#", current_turn+1);
  printf("Remember, your row# and col# must be between 0 and %d", game_board_size-1);
  do{
    sscanf("%d %d", move_row, move_col);
    if (in_range(*move_row, *move_col, game_board_size)){
      if (spot_taken(game_board, *move_row, *move_col, game_board_size, blank_character)){
        printf("That spot is already taken. Try again!");
      }
    }
    else{
      printf("That is not a valid move. Remeber, your row# and col# must be between 0 and %d", game_board_size-1);
    }
  } while((!in_range(*move_row, *move_col, game_board_size)) || (spot_taken(game_board, *move_row, *move_col, game_board_size, blank_character)));
}

bool spot_taken(char** game_board, int move_row, int move_col, int game_board_size, char blank_character){
  if (game_board[move_row][move_col] == blank_character){
    return false;
  }
  return true;
}

bool in_range(int move_row, int move_col, int game_board_size){
  if ((move_row >= 0) && (move_row < game_board_size) && (move_col >= 0) &&(move_col < game_board_size)){
    return true;
  }
  return false;
}

void update_board(char*** game_board, char* game_pieces, int move_row, int move_col, int current_turn){
  *game_board[move_row][move_col] = game_pieces[current_turn];
}