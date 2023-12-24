#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "game.h" // Include game.h for common structures

void initializeGameBoard(GameBoard *board, int size);
Boat* createBoat(int size, int x, int y, char orientation);
void initializeGame(Game *game);
void placeBoatsRandomlyOnPlayer(GameBoard *board, Boat *boats, int numBoats);
void placeBoatsRandomly(Game* game);
bool isValidPlacement(const GameBoard *board, int x, int y, int size, char orientation);

#endif
