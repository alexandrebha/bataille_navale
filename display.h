#ifndef DISPLAY_H
#define DISPLAY_H

#include "game.h" // Include game.h for common structures

/**
 * Affiche le plateau de jeu.
 * @param board Le plateau de jeu à afficher.
 * @param boats Tableau des bateaux.
 * @param showBoats Indique si les bateaux doivent être montrés.
 * @param isUserBoard Indique si c'est le plateau du joueur.
 */
void printBoard(GameBoard board, Boat *boats, int showBoats, bool isUserBoard);

/**
 * Affiche le résultat du jeu.
 * @param game L'état actuel du jeu.
 */
void displayGameResult(const Game *game);

/**
 * Affiche les plateaux de jeu pour les deux joueurs.
 * @param game L'état actuel du jeu.
 */
void displayGameBoards(const Game *game);

#endif
