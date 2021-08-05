//This file includes the functions that have to do with setting up the overall game, including setting up the board, assigning a piece to each player, and establishing which player goes first.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup_game.h"

void setup_game(int argc, char** argv, char*** game_board, char** game_pieces, int* game_board_size, int* current_turn, char blank_character){
  *game_board = create_board(argc, argv, game_board_size, blank_character);
  *game_pieces = get_players_and_pieces();
  *current_turn = get_which_player_goes_first();
}

char** create_board(int argc, char** argv, int* game_board_size, char blank_character){
  char** board;
  fetch_game_board_size(argc, argv, game_board_size);
  board = calloc(*game_board_size, sizeof(*board));//*board = first element in the array.
  for (int i = 0; i < *game_board_size; i++){
    board[i] = calloc(*game_board_size, sizeof(*board[i]));
    for (int j = 0; j < *game_board_size; j++){
      board[i][j] = blank_character;
    }
  }
  return board;
}

void fetch_game_board_size(int argc, char** argv, int* game_board_size){
  if (argc == 2){
    sscanf(argv[1], "%d", game_board_size);
    //We read in the second parameter on the command line (first is the executable),
    // convert it to an integer, and store it as the variable game_board_size.
    //NOTE: We do game_board_size and not &game_board_size because the parameter 
    //game_board_size is already an integer pointer. 
  }
  else if (argc == 1){
    printf("You must enter a number indicating the size you want the Tic Tac Toe board.\n");
    exit(EXIT_FAILURE);
  }
  else{
    printf("You entered too many arguments. There should only be one argument indicating the size of the board.\n");
    exit(EXIT_FAILURE);
  }
}

