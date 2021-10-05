//This file includes the functions that have to do with playing the game, such as displaying the current state of the board, getting inputted player moves, updating the board, and checking to see if someone won or there is a tie.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "play_game.h"

//Main function for playing the game. Starts out by displaying a welcome message, then continues to read in moves inputted by the player, update the board, display the board, and change turns until either someone has won or there is a tie. Finally, it declares the results of the game. 
void play_game(char*** game_board, char* game_pieces, int game_board_size, int* current_turn, char blank_character){
  int move_row, move_col;
  displayWelcomeMessage(*game_board, game_board_size);
  do{
    get_move_from_player(*game_board, game_board_size, *current_turn, &move_row, &move_col, blank_character);
    update_board(game_board, game_pieces, move_row, move_col, *current_turn);
    display_board(*game_board, game_board_size);
    if (!is_game_over(*game_board, game_board_size, blank_character)){
      change_turn(current_turn);
    }
  } while (!is_game_over(*game_board, game_board_size, blank_character));
  //When we exit the do-while loop, if a player has won, the current turn will be that player.
  declare_results_of_game(*game_board, game_board_size, blank_character, *current_turn);
}

//Displays the initialized board and a welcome message to signify the beginning of the game.
void displayWelcomeMessage(char** game_board, int game_board_size){
  printf("Welcome! Let's begin the game!\n");
  display_board(game_board, game_board_size);
  printf("Good luck!\n");
}

//Prints the current state of the board in grid format to the screen.
void display_board(char** game_board, int game_board_size){
  for (int display_row = 0; display_row < game_board_size; display_row++){
    printf("%d  ", display_row);//Write out the row numbers.
    for (int display_col = 0; display_col < game_board_size; display_col++){
      printf("%c ", game_board[display_row][display_col]);//First column of board will be printed 2 spaces after the row number to create separation.
    }
    printf("\n");
  }
  printf("   ");//First column of board will be printed after 3 spaces.
  for (int last_line_position = 0; last_line_position < game_board_size; last_line_position++){
    printf("%d ", last_line_position);//write out the column numbers.
  }
  printf("\n");
}

//Reads in input from player (in format: row# col#) and calls is_move_valid to check if the move is valid.
void get_move_from_player(char** game_board, int game_board_size, int current_turn, int* move_row, int* move_col, char blank_character){
  int num_args_read;
  printf("Player %d, please type in your move in the following format: row# col#\n", current_turn+1);
  do{
    printf("Remember, your row# and col# must be between 0 and %d: ", game_board_size-1);
    num_args_read = scanf("%d %d", move_row, move_col);
  } while(!is_move_valid(num_args_read, game_board, game_board_size, *move_row, *move_col, blank_character));
}

//Checks to see if the input the user typed in to make the move is of a valid format, then checks whether the spot on the board contains a blank character and whether the numbers entered in are within the size of the game board.
bool is_move_valid(int num_args_read, char** game_board, int game_board_size, int move_row, int move_col, char blank_character){
  if (isMoveFormatValid(num_args_read)){
    if (spot_taken(game_board, move_row, move_col, game_board_size, blank_character)){
      printf("That spot already has a player piece on it. Please choose a spot that contains the blank character (an 'e')\n");
      return false;
    }
    if (!in_range(move_row, move_col, game_board_size)){
      printf("The row and column number you entered is out of range of the size of the game board. Please make sure your row and column numbers are between 0 and %d\n", game_board_size-1);
      return false;
    }
    return true;
  }
  else{
    printf("The input you entered is not of a valid format. Remember, it must be of the following format: row# col#\n");
    return false;
  }
}

//makes sure the input move the user typed in has 2 arguments (a row and column number) and then checks to make sure there aren't any nonspace characters entered afterwards by reading to the newline character.
bool isMoveFormatValid(int num_args_read){
  bool num_args_correct = false;
  bool all_spaces_after = true;
  if (num_args_read == 2){
      num_args_correct = true;
  }
  char next_character;
  //read to the end of the line (newline character) to check for nonspace characters.
  do{
    scanf("%c", &next_character);
    if (!isspace(next_character)){
      all_spaces_after = false;
    }
  } while(next_character != '\n');
  return num_args_correct && all_spaces_after;
}

//Reads in input from player (in format: row# col#) and checks if this row/column is valid.
/*void get_move_from_player(char** game_board, int game_board_size, int current_turn, int* move_row, int* move_col, char blank_character){
  printf("Player %d, please type in your move in the following format: row# col#\n", current_turn+1);
  printf("Remember, your row# and col# must be between 0 and %d\n", game_board_size-1);
  do{
    scanf("%d %d", move_row, move_col);//No dereference because move_row and move_col were passed as pointers.
    if (in_range(*move_row, *move_col, game_board_size)){
      if (spot_taken(game_board, *move_row, *move_col, game_board_size, blank_character)){
        printf("That spot is already taken. Try again!\n");
      }
    }
    else{
      printf("That is not a valid move. Remember, your row# and col# must be between 0 and %d. Try again!\n", game_board_size-1);
    }
  } while((!in_range(*move_row, *move_col, game_board_size)) || (spot_taken(game_board, *move_row, *move_col, game_board_size, blank_character)));//Move must correspond to a currently empty spot on the board and be within the board (in range) to be valid.
}*/

//Checks if a certain row&column number on the game board already has an X or O on it.
bool spot_taken(char** game_board, int move_row, int move_col, int game_board_size, char blank_character){
  if (game_board[move_row][move_col] == blank_character){
    //Spot is not taken if a blank character occupies it.
    return false;
  }
  return true;
}

//Checks if a certain row and column number is within the dimensions of the board.
bool in_range(int move_row, int move_col, int game_board_size){
  if ((move_row >= 0) && (move_row < game_board_size) && (move_col >= 0) &&(move_col < game_board_size)){
    //row and column number must be between 0 and the size of the board.
    return true;
  }
  return false;
}

//Changes the entry at row move_row, column move_col on the board to the current player's piece.
void update_board(char*** game_board, char* game_pieces, int move_row, int move_col, int current_turn){
  *game_board[move_row][move_col] = game_pieces[current_turn];
}

//Changes the player whose turn it is to make a move. Right now, I assume there are only two players. In the future, I might modify this function so there can be more players.
void change_turn(int* currentTurn){
  if (*currentTurn == 0){
    *currentTurn = 1;
  }
  else{
    *currentTurn = 0;
  }
}

//Checks if there is either a tie or a player has won the game.
bool is_game_over(char** game_board, int game_board_size, char blank_character){
  if (someone_won(game_board, game_board_size, blank_character) || is_tie(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

//There are 3 ways to win a game: Fill any row, column, or main diagonal (left or right) on the board with your pieces. This checks for all 3 cases.
bool someone_won(char** game_board, int game_board_size, char blank_character){
  if (won_row(game_board, game_board_size, blank_character) || won_col(game_board, game_board_size, blank_character) || won_diagonal(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

//Checks each row of the game board by making sure that the first piece in any row is not a blank character and then checking to see if the other pieces on that row are the same as the first character.
bool won_row(char** game_board, int game_board_size, char blank_character){
  for (int row_number = 0; row_number < game_board_size; row_number++){
    if ((game_board[row_number][0] != blank_character) && all_same(game_board[row_number], game_board_size)){
      return true;
    }
  }
  return false;
}

//Checks each column of the game board by first transposing the board and then doing the same procedure as won_row.
bool won_col(char** game_board, int game_board_size, char blank_character){
  char** transposed_game_board = transpose_board(game_board, game_board_size);
  if (won_row(transposed_game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

//Checks whether all the elements in an array/row are equal to the first element in that array/row.
bool all_same(char* row, int length_of_row){
  for (int column = 0; column < length_of_row; column++){
    if (row[column] != row[0]){
      return false;
    }
  }
  return true;
}

//Transposes the old_game_board into new_game_board by switching the rows and columns of old_game_board(first column of old_game_board becomes new first row of new_game_board, etc.)
char** transpose_board(char** old_game_board, int game_board_size){
  char** new_game_board = calloc(game_board_size, sizeof(*new_game_board));
  for (int i = 0; i < game_board_size; i++){
    new_game_board[i] = calloc(game_board_size, sizeof(*new_game_board[i]));
    for (int j = 0; j < game_board_size; j++){
      new_game_board[i][j] = old_game_board[j][i];
    }
  }
  return new_game_board;
}

//Simply checks to see whether someone has won by filling the main left or main right diagonal on the game board.
bool won_diagonal(char** game_board, int game_board_size, char blank_character){
  if (won_left_diagonal(game_board, game_board_size, blank_character) || won_right_diagonal(game_board, game_board_size, blank_character)){
    return true;
  }
  return false;
}

//Checks to see whether someone has filled the main left diagonal of the board with their piece.
bool won_left_diagonal(char** game_board, int game_board_size, char blank_character){
  if (game_board[0][0] == blank_character){
    return false;
  }
  for (int position = 0; position < game_board_size; position++){
    if (game_board[position][position] != game_board[0][0]){
      return false;
    }
  }
  return true;
}

//Checks to see whether someone has filled the right main diagonal of the board with their piece.
bool won_right_diagonal(char** game_board, int game_board_size, char blank_character){
  if (game_board[0][game_board_size-1] == blank_character){
    return false;
  }
  for (int position = 0; position < game_board_size; position++){
    if (game_board[position][game_board_size-position-1] != game_board[0][game_board_size-1]){
      return false;
    }
  }
  return true;
}

//Checks to see whether there is a tie. This happens when all of the spots on the game board are no longer blank and no one has won yet.
bool is_tie(char** game_board, int game_board_size, char blank_character){
  if (someone_won(game_board, game_board_size, blank_character)){
    return false;
  }
  for (int row = 0; row < game_board_size; row++){
    for (int col = 0; col < game_board_size; col++){
      if (game_board[row][col]== blank_character){
        return false;
      }
    }
  }
  return true;
}

//This function executes at the end of the game, just before cleanup. It prints a message to the screen congratulating the player who won or declaring a tie.
void declare_results_of_game(char** game_board, int game_board_size, char blank_character, int current_turn){
  if (is_tie(game_board, game_board_size, blank_character)){
    printf("The game has ended in a tie. No one has won.");
  }
  else{
    printf("Congratulations, player %d, you have won!", current_turn+1);
  }
}
