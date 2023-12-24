#include "update.h"

/**
 * Checks if a specific boat is still alive (i.e., not destroyed).
 * @param boat Pointer to the boat structure.
 * @return Non-zero if the boat is still alive, zero otherwise.
 */

int isBoatAlive(Boat *boat) {
  return boat->health > 0;
}

/**
 * Finds the size of a boat at a given position.
 * @param boats Array of boats.
 * @param numBoats Number of boats in the array.
 * @param x X-coordinate to check.
 * @param y Y-coordinate to check.
 * @return Size of the boat at the given coordinates, or 0 if no boat is found.
 */

int findBoatSize(Boat *boats, int numBoats, int x, int y) {
  for (int i = 0; i < numBoats; i++) {
    Boat boat = boats[i];
    for (int j = 0; j < boat.size; j++) {
      int boatX = boat.x;
      int boatY = boat.y;
      if (boat.orientation == 'H') {
	boatY += j;
      } else {
	boatX += j;
      }
      if (boatX == x && boatY == y) {
	return boat.size;
      }
    }
  }
  return 0;
}

/**
 * Checks if a specific boat is hit at given coordinates.
 * @param boat Pointer to the boat structure.
 * @param x X-coordinate for the hit check.
 * @param y Y-coordinate for the hit check.
 * @return True if the boat is hit at the given coordinates, false otherwise.
 */

bool isBoatHit(Boat *boat, int x, int y) {
  for (int i = 0; i < boat->size; ++i) {
    int boatX = boat->x;
    int boatY = boat->y;
    if (boat->orientation == 'H') {
      boatY += i;
    } else {
      boatX += i;
    }
    if (boatX == x && boatY == y) {
      return true;
    }
  }
  return false;
}

/**
 * Checks if all boats on a game board have been sunk, indicating the end of the game.
 * @param board Pointer to the game board.
 * @return Non-zero if the game is over (all boats sunk), zero otherwise.
 */

int checkGameOver(const GameBoard *board) {
  for (int i = 0; i < board->size; ++i) {
    for (int j = 0; j < board->size; ++j) {
      if (board->matrix[i][j] == BOAT) {
	return 0; 
      }
    }
  }
  return 1;
}

/**
 * Updates the game state, such as switching the current player.
 * @param game Pointer to the game structure.
 * @param currentPlayer Pointer to the current player indicator.
 */

void updateGame(Game *game, int *currentPlayer) {
  *currentPlayer = (*currentPlayer == 1) ? 2 : 1;
  if (checkGameOver(&game->player1)) {
    printf("L'ordinateur a gagné !\n");
    }
  else if (checkGameOver(&game->player2)) {
    printf("Vous avez gagné !\n");
  }
}

/**
 * Finds a boat at a given position.
 * @param boats Array of boats.
 * @param numBoats Number of boats in the array.
 * @param x X-coordinate to check.
 * @param y Y-coordinate to check.
 * @return Pointer to the boat at the given coordinates, or NULL if no boat is found.
 */

Boat* findBoat(Boat *boats, int numBoats, int x, int y) {
  for (int i = 0; i < numBoats; i++) {
    Boat *boat = &boats[i];
    for (int j = 0; j < boat->size; j++) {
      int boatX = boat->x;
      int boatY = boat->y;
      if (boat->orientation == 'H') {
	boatY += j;
      }
      else if (boat->orientation == 'V') {
	boatX += j;
      }
      if (boatX == x && boatY == y) {
	return boat;
      }
    }
  }
  return NULL;
}

/**
 * Frees allocated resources for the game, such as memory for game boards and boats.
 * @param game Pointer to the game structure.
 */

void freeGameResources(Game *game) {
    for (int i = 0; i < game->player1.size; i++) free(game->player1.matrix[i]);
    for (int i = 0; i < game->player2.size; i++) free(game->player2.matrix[i]);
    free(game->player1.matrix);
    free(game->player2.matrix);
    free(game->boats1);
    free(game->boats2);
}
