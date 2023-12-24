#ifndef TURN_H
#define TURN_H

#include "game.h" // game.h is included for common structures

/**
 * Executes a turn for the player, allowing them to shoot at a specified location.
 * @param board Pointer to the opponent's game board.
 * @param boats Pointer to the array of the opponent's boats.
 * @param x The x-coordinate of the shot.
 * @param y The y-coordinate of the shot.
 */
void takeTurn(GameBoard *board, Boat *boats, int x, int y);

/**
 * Executes a turn for the computer (AI) player.
 * @param playerBoard Pointer to the player's game board.
 * @param playerBoats Pointer to the array of the player's boats.
 */
void computerTurn(GameBoard *playerBoard, Boat *playerBoats);

/**
 * Handles the player's turn, including getting user input for the shot's coordinates.
 * @param opponentBoard Pointer to the opponent's game board.
 * @param opponentBoats Pointer to the array of the opponent's boats.
 */
void playerTurn(GameBoard *opponentBoard, Boat *opponentBoats);


void playSound(const char* filename);

#endif // TURN_H


