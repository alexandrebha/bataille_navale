#include "display.h"
#include "update.h"

/**
 * Prints the game board with various symbols representing the game state.
 * @param board The game board to be printed.
 * @param boats Array of boats.
 * @param showBoats Flag to indicate whether to show boats or not.
 * @param isUserBoard Flag to indicate if the board belongs to the user.
 */


void printBoard(GameBoard board, Boat *boats, int showBoats, bool isUserBoard) {
  const char* WATER_COLOR = "\x1b[36m";
  const char* BOAT_COLORS[] = {"\x1b[34m", "\x1b[31m", "\x1b[32m", "\x1b[35m", "\x1b[33m"};
  const char* RESET_COLOR = "\x1b[0m";
  
  printf("  ");
  for (int j = 0; j < board.size; j++) {
    printf("%2d", j);
  }
  printf("\n");
  
  for (int i = 0; i < board.size; i++) {
    printf("%2d ", i);
    for (int j = 0; j < board.size; j++) {
      CellType cell = board.matrix[i][j];
      Boat* boat = findBoat(boats, NUMBER_OF_BOATS, i, j);
      switch (cell) {
      case WATER:
	printf("%s~%s ", WATER_COLOR, RESET_COLOR);
	break;
      case WATER_SHOT:
	printf("O ");
	break;
      case BOAT:
	if (showBoats || isUserBoard) {
	  if (boat && boat->health == 0) {
	    const char* wreckSymbol = boat->orientation == 'V' ? "|" : "-";
	    printf("%s%s%s ", BOAT_COLORS[boat->size - 2], wreckSymbol, RESET_COLOR); 
	  } else {
	    printf("%sB%s ", BOAT_COLORS[boat->size - 2], RESET_COLOR); 
	  }
	} else {
	  printf("%s~%s ", WATER_COLOR, RESET_COLOR);
                    }
	break;
      case WRECK:
	if (boat && boat->health == 0) {
	  const char* wreckSymbol = boat->orientation == 'V' ? "|" : "-";
	  printf("%s%s%s ", BOAT_COLORS[boat->size - 2], wreckSymbol, RESET_COLOR);
	} else {
	  printf("X ");
	}
	break;
      }
    }
    printf("\n");
  }
}

/**
 * Displays the result of the game, showing who won or if the game ended unexpectedly.
 * @param game Pointer to the game structure containing the game's state.
 */

void displayGameResult(const Game *game) {
  if (checkGameOver(&game->player1)) {
    printf("L'ordinateur a gagné !\n");
  } else if (checkGameOver(&game->player2)) {
    printf("Vous avez gagné !\n");
  } else {
    printf("Le jeu est terminé de manière inattendue.\n");
  }
}

/**
 * Displays the game boards of both the player and the computer.
 * @param game Pointer to the game structure containing the game's state.
 */

void displayGameBoards(const Game *game) {
  printf("Votre plateau :\n");
  printBoard(game->player1, game->boats1, 1, true);
  
  printf("Plateau de l'ordinateur :\n");
  printBoard(game->player2, game->boats2, 0, false);
}
