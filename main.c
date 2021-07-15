//This contains the main function of the program. This will run the main function, which 
//sets the program into action. The main function will call the 3 functions that execute
//the 3 main parts I mentioned in outline.txt: Setting up the game, playing the game, and
//cleaning up the game.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char** argv){
  setup_game();
  play_game();
  cleanup_game();
  return 0;
}