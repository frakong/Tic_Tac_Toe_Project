//The header file for play_game.c
#ifndef PLAYGAME_H
  #define PLAYGAME_H
  void play_game(char** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character);
  void displayWelcomeMessage(char** game_board, int game_board_size);
  void display_board(char** game_board, int game_board_size);
  void get_move_from_player(char** game_board, int game_board_size, int current_turn, int* move_row, int* move_col, char blank_character);
  bool is_move_valid(int num_args_read, char** game_board, int game_board_size, int move_row, int move_col, char blank_character);
  bool isMoveFormatValid(int num_args_read);
  bool spot_taken(char** game_board, int move_row, int move_col, int game_board_size, char blank_character);
  bool in_range(int move_row, int move_col, int game_board_size);
  void update_board(char** game_board, char* game_pieces, int move_row, int move_col, int current_turn);
  void change_turn(int* currentTurn);
  bool is_game_over(char** board, int game_board_size, char blank_character);
  bool someone_won(char** game_board, int game_board_size, char blank_character);
  bool won_row(char** game_board, int game_board_size, char blank_character);
  bool won_col(char** game_board, int game_board_size, char blank_character);
  bool all_same(char* row, int length_of_row);
  char** transpose_board(char** old_game_board, int game_board_size);
  bool won_diagonal(char** game_board, int game_board_size, char blank_character);
  bool won_left_diagonal(char** game_board, int game_board_size, char blank_character);
  bool won_right_diagonal(char** game_board, int game_board_size, char blank_character);
  bool is_tie(char** game_board, int game_board_size, char blank_character);
  void declare_results_of_game(char** game_board, int game_board_size, char blank_character, int current_turn);
#endif