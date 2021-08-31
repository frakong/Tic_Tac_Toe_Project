//This file includes the functions to clean up the game by deallocating the memory space previously allocated for the game board and the array containing the game pieces (X and O).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "cleanup_game.h"

//This function frees up the memory space allocated to the arrays for the game pieces and the game board.
void cleanup_game(char** game_board, char* game_pieces, int game_board_size){
  cleanup_board(game_board, game_board_size);
  cleanup_game_pieces(game_pieces);
}

//Frees up the memory space allocated for the NxN game board.
void cleanup_board(char** game_board, int game_board_size){
  for (int row = 0; row < game_board_size; row++){
    free(game_board[row]);
  }
}

//Frees up the memory space allocated for the array that lists the game pieces.
void cleanup_game_pieces(char* game_pieces){
  free(game_pieces);
}