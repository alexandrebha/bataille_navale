# Name of the compiler
CC = gcc

# Compilation options
CFLAGS = -Wall -g -fPIC `sdl2-config --cflags`

# Linking options
LFLAGS = `sdl2-config --libs` -lSDL2_mixer

# Name of the dynamic library
LIB_NAME = monjeu
LIB = lib$(LIB_NAME).so

# Name of the executable
EXEC = main

# Source files for the library and the executable
LIB_SRCS = initialize.c display.c turn.c update.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

MAIN_SRC = main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Default rule
all: $(LIB) $(EXEC)

# Rule to create the dynamic library
$(LIB): $(LIB_OBJS)
	$(CC) -shared -o $@ $(LIB_OBJS)

# Rule to create the executable
$(EXEC): $(MAIN_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $@ -L. -l$(LIB_NAME) $(LFLAGS)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to check dependencies (SDL2 and SDL2_mixer)
check-dependencies:
	@command -v sdl2-config >/dev/null 2>&1 || { echo >&2 "SDL2 is not installed. Please install SDL2 (libsdl2-dev)."; exit 1; }
	@echo "All dependencies are satisfied."

# Rule to clean up compiled files
clean:
	rm -f $(LIB_OBJS) $(MAIN_OBJ) $(EXEC) $(LIB)
