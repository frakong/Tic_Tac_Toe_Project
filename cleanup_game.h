//The header file for cleanup_game.c
#ifndef CLEANUP_GAME
  #define CLEANUP_GAME
  void cleanup_game(char** game_board, char* game_pieces, int game_board_size);
  void cleanup_board(char** game_board, int game_board_size);
  void cleanup_game_pieces(char* game_pieces);
#endif