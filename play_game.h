//The header file for play_game.c
#ifndef PLAYGAME_H
  #define PLAYGAME_H
  void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character);
  void displayWelcomeMessage(char** game_board, int game_board_size);
  void display_board(char** game_board, int game_board_size);
  void get_move_from_player(char** game_board, int game_board_size, int current_turn, int* move_row, int* move_col, char blank_character);
  bool spot_taken(char** game_board, int move_row, int move_col, int game_board_size, char blank_character);
  bool in_range(int move_row, int move_col, int game_board_size);
  void update_board(char*** game_board, char* game_pieces, int move_row, int move_col, int current_turn);

#endif