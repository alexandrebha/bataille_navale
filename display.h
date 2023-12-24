#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h" // Include game.h for common structures

/**
 * Displays the game board.
 * @param board The game board to display.
 * @param boats Array of boats.
 * @param showBoats Indicates whether the boats should be shown.
 * @param isUserBoard Indicates if it's the player's board.
 */

void printBoard(GameBoard board, Boat *boats, int showBoats, bool isUserBoard);

/**
 * Displays the result of the game.
 * @param game The current state of the game.
 */

void displayGameResult(const Game *game);

/**
 * Displays the game boards for both players.
 * @param game The current state of the game.
 */

void displayGameBoards(const Game *game);

#endif
