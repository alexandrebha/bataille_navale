#ifndef UPDATE_H
#define UPDATE_H

#include "game.h" // Include game.h for common structures

/**
 * Checks if a boat is still alive (not destroyed).
 * @param boat Pointer to the boat structure.
 * @return Returns non-zero if the boat is alive, zero otherwise.
 */
int isBoatAlive(Boat *boat);

/**
 * Checks if a specific boat is hit at given coordinates.
 * @param boat Pointer to the boat structure.
 * @param x The x-coordinate for the check.
 * @param y The y-coordinate for the check.
 * @return Returns true if the boat is hit at the given coordinates, false otherwise.
 */
bool isBoatHit(Boat *boat, int x, int y);

/**
 * Checks if the game is over (i.e., if all boats of a player are destroyed).
 * @param board Pointer to the game board structure.
 * @return Returns non-zero if the game is over, zero otherwise.
 */
int checkGameOver(const GameBoard* board);

/**
 * Updates the game state, such as changing the current player.
 * @param game Pointer to the game structure.
 * @param currentPlayer Pointer to the current player indicator.
 */
void updateGame(Game *game, int *currentPlayer);

/**
 * Finds the size of the boat at given coordinates.
 * @param boats Array of boats.
 * @param numBoats Number of boats in the array.
 * @param x The x-coordinate to check.
 * @param y The y-coordinate to check.
 * @return Returns the size of the boat at the given coordinates, or 0 if no boat is found.
 */
int findBoatSize(Boat *boats, int numBoats, int x, int y);

/**
 * Finds the boat at given coordinates.
 * @param boats Array of boats.
 * @param numBoats Number of boats in the array.
 * @param x The x-coordinate to check.
 * @param y The y-coordinate to check.
 * @return Returns a pointer to the boat at the given coordinates, or NULL if no boat is found.
 */
Boat* findBoat(Boat *boats, int numBoats, int x, int y);

void freeGameResources(Game *game);

#endif // UPDATE_H
