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
    change_turn(current_turn);
    display_board(*game_board, game_board_size);
  } while (!is_game_over(*game_board, game_board_size, blank_character));
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

void change_turn(int* currentTurn){
  if (*currentTurn == 0){
    *currentTurn = 1;
  }
  else{
    *currentTurn = 0;
  }
}

bool is_game_over(char** game_board, int game_board_size, char blank_character){
  if (someone_won(game_board, game_board_size, blank_character) || is_tie(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

bool someone_won(char** game_board, int game_board_size, char blank_character){
  if (won_row(game_board, game_board_size, blank_character) || won_column(game_board, game_board_size, blank_character) || won_diagonal(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

bool won_row(char** game_board, int game_board_size, char blank_character){
  for (int row_number = 0; row_number < game_board_size; row_number++){
    if ((game_board[row_number][0] != blank_character) && all_same(game_board[row_number], game_board_size)){
      return true;
    }
  }
  return false;
}

bool won_col(char** game_board, int game_board_size, char blank_character){
  char** transposed_game_board = transpose_board(game_board, game_board_size);
  if (won_row(transposed_game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

bool all_same(char* row, int length_of_row){
  for (int column = 0; column < length_of_row; column++){
    if (row[column] != row[0]){
      return false;
    }
  }
  return true;
}

char** transpose_board(char** old_game_board, int game_board_size){
  char** new_game_board = calloc(game_board_size, sizeof(*new_game_board));
  for (int i = 0; i < game_board_size; i++){
    new_game_board[i] = calloc(game_board_size, sizeof(*new_game_board[i]));
    for (int j = 0; j < game_board_size; j++){
      new_game_board[i][j] = old_game_board[j][i];
    }
  }
  return new_game_board;
}

bool won_diagonal(char** game_board, int game_board_size, char blank_character){
  if (won_left_diagonal(game_board, game_board_size, blank_character) || won_right_diagonal(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

bool won_left_diagonal(char** game_board, int game_board_size, char blank_character){
  if (game_board[0][0] == blank_character){
    return false;
  }
  for (int position = 0; position < game_board_size; position++){
    if (game_board[position][position] != game_board[0][0]){
      return false;
    }
  }
  return true;
}

bool won_right_diagonal(char** game_board, int game_board_size, char blank_character){
  if (game_board[0][game_board_size-1] == blank_character){
    return false;
  }
  for (int position = 0; position < game_board_size; position++){
    if (game_board[position][game_board_size-position-1] != game_board[0][position]){
      return false;
    }
  }
  return true;
}

bool is_tie(char** game_board, int game_board_size, char blank_character){
  if (someone_won(game_board, game_board_size, blank_character)){
    return false;
  }
  for (int row = 0; row < game_board_size; row++){
    for (int col = 0; col < game_board_size; col++){
      if (game_board[row][col]== blank_character){
        return false;
      }
    }
  }
  return true;
}
