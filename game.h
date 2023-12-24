#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "SDL.h"
#include <SDL_mixer.h>

/**
 * Enumeration for the types of cells on the game board.
 */
typedef enum {
    WATER,      ///< Represents water (empty cell).
    WATER_SHOT, ///< Represents water that has been shot at.
    BOAT,       ///< Represents a part of a boat.
    WRECK       ///< Represents a part of a destroyed boat.
} CellType;

/**
 * Structure representing each boat in the game.
 */
typedef struct {
  int size;          ///< Size of the boat.
  int x, y;          ///< Reference position (coordinates) of the boat.
  char orientation;  ///< Orientation of the boat ('H' for horizontal, 'V' for vertical).
  int health;        ///< Remaining health of the boat.
} Boat;

/**
 * Structure representing the game board.
 */
typedef struct {
  CellType **matrix; ///< Matrix representing the board.
  int size;          ///< Size of one side of the matrix.
} GameBoard;

/**
 * Structure representing the overall game state.
 */
typedef struct {
  GameBoard player1, player2; ///< Game boards for each player.
  Boat *boats1, *boats2;      ///< Arrays of boats for each player.
} Game;

// Constants for game configuration
#define NUMBER_OF_BOATS 5 ///< Number of boats in the game.
#define BOARD_SIZE 10     ///< Size of the game board.
#define MAX_BOAT_SIZE 5   ///< Maximum size of any boat.
#define MIN_BOAT_SIZE 2   ///< Minimum size of any boat.

#endif // GAME_H
