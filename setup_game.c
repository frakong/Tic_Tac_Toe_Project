//This file includes the functions that have to do with setting up the overall game, including setting up the board, assigning a piece to each player, and establishing which player goes first.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup_game.h"

void setup_game(int argc, char** argv, char*** game_board, char** game_pieces, int* game_board_size, int* current_turn, char blank_character){
  create_board();
  get_players_and_pieces();
  get_which_player_goes_first();
}
