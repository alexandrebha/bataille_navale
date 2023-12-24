# Nom du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -g -fPIC `sdl2-config --cflags`

# Options de lien
LFLAGS = `sdl2-config --libs` -lSDL2_mixer

# Nom de la bibliothèque dynamique
LIB_NAME = monjeu
LIB = lib$(LIB_NAME).so

# Nom de l'exécutable
EXEC = main

# Fichiers source pour la bibliothèque et l'exécutable
LIB_SRCS = initialize.c display.c turn.c update.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Règle par défaut
all: $(LIB) $(EXEC)

# Règle pour créer la bibliothèque dynamique
$(LIB): $(LIB_OBJS)
	$(CC) -shared -o $@ $(LIB_OBJS)

# Règle pour créer l'exécutable
$(EXEC): $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $@ -L. -l$(LIB_NAME) $(LFLAGS)

# Règle pour les fichiers objet
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour vérifier les dépendances (SDL2 et SDL2_mixer)
check-dependencies:
	@command -v sdl2-config >/dev/null 2>&1 || { echo >&2 "SDL2 n'est pas installé. Veuillez installer SDL2 (libsdl2-dev)."; exit 1; }
	@echo "Toutes les dépendances sont satisfaites."

# Règle pour nettoyer les fichiers compilés
clean:
	rm -f $(LIB_OBJS) $(MAIN_OBJ) $(EXEC) $(LIB)
