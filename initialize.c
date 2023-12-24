#include "initialize.h"

const int BOAT_SIZES[NUMBER_OF_BOATS] = {5, 4, 3, 3, 2};


/**
 * Initializes the game by setting up game boards and placing boats randomly.
 * @param game Pointer to the game structure to be initialized.
 */


void initializeGame(Game *game) {
  initializeGameBoard(&game->player1, BOARD_SIZE);
  initializeGameBoard(&game->player2, BOARD_SIZE);
  
  game->boats1 = (Boat*)malloc(NUMBER_OF_BOATS * sizeof(Boat));
  game->boats2 = (Boat*)malloc(NUMBER_OF_BOATS * sizeof(Boat));
  
  for (int i = 0; i < NUMBER_OF_BOATS; ++i) {
    game->boats1[i] = *createBoat(BOAT_SIZES[i], 0, 0, 'H');
    game->boats2[i] = *createBoat(BOAT_SIZES[i], 0, 0, 'H'); 
  }
  
  placeBoatsRandomlyOnPlayer(&game->player1, game->boats1, NUMBER_OF_BOATS);
  placeBoatsRandomlyOnPlayer(&game->player2, game->boats2, NUMBER_OF_BOATS);
}

/**
 * Initializes a game board with a specified size.
 * @param board Pointer to the game board to be initialized.
 * @param size Size of one side of the game board.
 */


void initializeGameBoard(GameBoard *board, int size) {
  board->size = size;
  board->matrix = (CellType**)malloc(size * sizeof(CellType*));
  for (int i = 0; i < size; i++) {
    board->matrix[i] = (CellType*)malloc(size * sizeof(CellType));
    for (int j = 0; j < size; j++) {
      board->matrix[i][j] = WATER;
    }
  }
}

/**
 * Creates a new boat with specified properties.
 * @param size Size of the boat.
 * @param x X-coordinate of the boat's reference position.
 * @param y Y-coordinate of the boat's reference position.
 * @param orientation Orientation of the boat ('H' for horizontal, 'V' for vertical).
 * @return Pointer to the newly created boat.
 */

Boat* createBoat(int size, int x, int y, char orientation) {
  Boat* newBoat = (Boat*)malloc(sizeof(Boat));
  if (newBoat != NULL) {
    newBoat->size = size;
    newBoat->x = x;
    newBoat->y = y;
    newBoat->orientation = orientation;
    newBoat->health = size;
  }
  return newBoat;
}


/**
 * Checks if a placement of a boat is valid on the game board.
 * @param board Pointer to the game board.
 * @param x X-coordinate for the placement.
 * @param y Y-coordinate for the placement.
 * @param size Size of the boat to be placed.
 * @param orientation Orientation of the boat.
 * @return True if the placement is valid, false otherwise.
 */

bool isValidPlacement(const GameBoard *board, int x, int y, int size, char orientation) {
  if (x < 0 || y < 0 || (orientation == 'H' && y + size - 1 >= board->size) || (orientation == 'V' && x + size - 1 >= board->size)) {
    return false;
  }
  for (int i = 0; i < size; ++i) {
    if (orientation == 'H' && board->matrix[x][y + i] != WATER) {
      return false;
    } else if (orientation == 'V' && board->matrix[x + i][y] != WATER) {
      return false;
    }
  }
  
  return true;
}


/**
 * Places boats randomly on a player's game board.
 * @param game Pointer to the game structure.
 */


void placeBoatsRandomly(Game *game) {
  placeBoatsRandomlyOnPlayer(&game->player1, game->boats1, NUMBER_OF_BOATS);
  placeBoatsRandomlyOnPlayer(&game->player2, game->boats2, NUMBER_OF_BOATS);
}


/**
 * Places boats randomly on a game board without overlapping.
 * @param board Pointer to the game board where boats will be placed.
 * @param boats Array of boats to be placed on the board.
 * @param numBoats Number of boats in the array.
 */


void placeBoatsRandomlyOnPlayer(GameBoard *board, Boat *boats, int numBoats) {
  for (int i = 0; i < numBoats; ++i) {
    int boatSize = boats[i].size;
    char orientation = (rand() % 2 == 0) ? 'H' : 'V';
    int x, y;
    
    do {
      if (orientation == 'H') {
	x = rand() % board->size;
	y = rand() % (board->size - boatSize + 1);
      } else {
	x = rand() % (board->size - boatSize + 1);
	y = rand() % board->size;
      }
    } while (!isValidPlacement(board, x, y, boatSize, orientation));
    
    boats[i] = *createBoat(boatSize, x, y, orientation);
    
    for (int j = 0; j < boatSize; ++j) {
      if (orientation == 'H') {
	board->matrix[x][y + j] = BOAT;
      } else { 
	board->matrix[x + j][y] = BOAT;
      }
    }
  }
}
