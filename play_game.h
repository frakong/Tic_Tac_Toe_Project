//The header file for play_game.c
#ifndef PLAYGAME_H
  #define PLAYGAME_H
  void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character);
  void display_board(char** game_board, int game_board_size);

#endif