//This file includes the functions that have to do with setting up the overall game, including setting up the board, assigning a piece to each player, and establishing which player goes first.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup_game.h"

//This function allocates memory space for the game board and the array containing the game pieces (X and O), as well as establishing which player goes first.
void setup_game(int argc, char** argv, char*** game_board, char** game_pieces, int* game_board_size, int* current_turn, char blank_character){
  *game_board = create_board(argc, argv, game_board_size, blank_character);
  *game_pieces = get_players_and_pieces();
  *current_turn = get_which_player_goes_first();
}

//This function gets the user input for the size of the board, then allocates enough memory space for this board and sets every space on the board to the blank character. Finally, it returns this newly created board.
char** create_board(int argc, char** argv, int* game_board_size, char blank_character){
  char** board;
  fetch_game_board_size(argc, argv, game_board_size);
  board = calloc(*game_board_size, sizeof(*board));
  for (int i = 0; i < *game_board_size; i++){
    board[i] = calloc(*game_board_size, sizeof(*board[i]));
    for (int j = 0; j < *game_board_size; j++){
      board[i][j] = blank_character;
    }
  }
  return board;
}

//For now, this function will only check to make sure the user inputted one argument when he/she ran the program on the command line: The size of the board. It doesn't check whether this argument is a number or not, so in the future I plan on adding to this function to ensure more stringent error checking.
void fetch_game_board_size(int argc, char** argv, int* game_board_size){
  if (argc == 2){
    int num_args_read;
    num_args_read = sscanf(argv[1], "%d ", game_board_size);
    if (num_args_read == 1){
      if (*game_board_size <= 0){
        printf("ERROR! The game board size must be greater than 0. \n");
        exit(EXIT_FAILURE);
      }
    }
    else{
      printf("ERROR! The game board size you entered must be an integer number. \n");
      exit(EXIT_FAILURE);
    }
  }
  else{
    printf("You should only input 1 argument: The dimensions of the board\n");
    printf("Ending program\n");
    exit(EXIT_FAILURE);
  }
}

//This function simply allocates memory space for the array storing the game pieces. It will only consist of two pieces: X and O. Thus, player 1 will get X and player 2 will get O. In the future, I may implement a random generator that will randomly assign a piece to each player.
char* get_players_and_pieces(){
  char* player_pieces = calloc(2, sizeof(*player_pieces));
  player_pieces[0] = 'X';
  player_pieces[1] = 'O';
  return player_pieces;
}

//We are establishing that the player who has the X piece will go first. In the future, the selection may be random.
int get_which_player_goes_first(){
  return 0;
}

