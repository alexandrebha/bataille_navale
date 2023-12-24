#include "turn.h"
#include "update.h"

/**
 * Handles the player's turn, allowing them to shoot at a specified location on the opponent's board.
 * @param opponentBoard Pointer to the opponent's game board.
 * @param opponentBoats Array of the opponent's boats.
 */

void playerTurn(GameBoard *opponentBoard, Boat *opponentBoats) {
  int shotX, shotY;
  bool validShot = false;
  while (!validShot) {
    printf("Votre tour. Entrez les coordonnées du tir (x y) : ");
    scanf("%d %d", &shotX, &shotY);
    if (shotX >= 0 && shotX < BOARD_SIZE && shotY >= 0 && shotY < BOARD_SIZE) {
      validShot = true;
      takeTurn(opponentBoard, opponentBoats, shotX, shotY);

    } else {
      printf("Coordonnées invalides. Veuillez entrer des coordonnées dans la plage [0, %d).\n", BOARD_SIZE);
    }
  }
}


/**
 * Executes a turn for a player or the computer, making a shot at the specified coordinates.
 * @param board Pointer to the game board on which the shot is taken.
 * @param boats Array of boats on the board.
 * @param x X-coordinate for the shot.
 * @param y Y-coordinate for the shot.
 */

 void takeTurn(GameBoard *board, Boat *boats, int x, int y) {
   if (x < 0 || x >= board->size || y < 0 || y >= board->size) {
     printf("Coordonnées invalides. Veuillez choisir des coordonnées dans la plage du plateau.\n");
     return;
   }
   switch (board->matrix[x][y]) {
   case WATER:
     printf("Tir dans l'eau à la position (%d, %d)!\n", x, y);
     board->matrix[x][y] = WATER_SHOT;
     playSound("plouf.wav");
     break;
   case BOAT:
   case WRECK:
     printf("Touché à la position (%d, %d)!\n", x, y);
     board->matrix[x][y] = WRECK;
     playSound("explosion.wav");
     for (int i = 0; i < NUMBER_OF_BOATS; ++i) {
       if (isBoatHit(&boats[i], x, y)) {
	 boats[i].health--;
	 if (boats[i].health == 0) {
	   printf("Bateau coulé !\n");
	 }
	 return;
       }
	  }
     break;
   case WATER_SHOT:
     printf("Vous avez déjà tiré à la position (%d, %d)!\n", x, y);
     break;
   }
 }

/**
 * Executes a turn for the computer (AI) player by selecting random coordinates to shoot at.
 * @param playerBoard Pointer to the player's game board.
 * @param playerBoats Array of the player's boats.
 */

void computerTurn(GameBoard *playerBoard, Boat *playerBoats) {
    int x, y;
    do {
        x = rand() % playerBoard->size;
        y = rand() % playerBoard->size;
    } while (playerBoard->matrix[x][y] == WATER_SHOT || playerBoard->matrix[x][y] == WRECK);

    takeTurn(playerBoard, playerBoats, x, y);
    printf("L'ordinateur a tiré à la position (%d, %d)\n", x, y);
}

void playSound(const char *filename) {
    Mix_Chunk *sound = Mix_LoadWAV(filename);
    if (!sound) {
        printf("Failed to load sound: %s\n", Mix_GetError());
        return;
    }

    Mix_PlayChannel(-1, sound, 0);
    while(Mix_Playing(-1) != 0);  // Attendre la fin de l'audio

    Mix_FreeChunk(sound);
}
