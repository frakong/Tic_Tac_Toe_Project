//The header file for setup_game.c
#ifndef SETUPGAME_H
  #define SETUPGAME_H
  void setup_game(int argc, char** argv, char*** game_board, char** game_pieces, int* game_board_size, int* current_turn, char blank_character);
  char** create_board(int argc, char** argv, int* game_board_size, char blank_character);
  void fetch_game_board_size(int argc, char** argv, int* game_board_size);
  char* get_players_and_pieces();
  int get_which_player_goes_first();
#endif