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
#include "cleanup_game.h"

//This is the main function that will run the game, is also the function that the executable will run. It initializes the important variables for the game and calls the three main functions to set up the game, play the game, and clean up the game once the game is over.
int main(int argc, char** argv){
  char** game_board;//This is how we represent the game board, as a double character pointer. It will be an NxN grid, with N being the number of rows/columns on the board.
  char* game_pieces;//This pointer represents an array containing the pieces the players will use to play this game: X and O.
  int game_board_size;//This is the size of the game board that the user will input. For example, if the user inputs 3, then the size of the board will be 3x3.
  int current_turn;//Indicates whose turn it is to place their game piece on the board. If it's 0, it's player 1's turn. If it's 1, it's player 2's turn.
  char blank_character = 'e';//Every spot on the board that does not yet have an X or O on it is an empty space and will be filled by this character. In the future, I plan on letting the user decide what the blank character should be.
  

  setup_game(argc, argv, &game_board, &game_pieces, &game_board_size, &current_turn, blank_character);
  play_game(&game_board, game_pieces, game_board_size, &current_turn, blank_character);
  cleanup_game(game_board, game_pieces, game_board_size);
  return 0;
}