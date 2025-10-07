CC = g++
CFLAGS = -I C:/raylib/include -L C:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm

all:
	$(CC) main.cpp unit.cpp -o game.exe $(CFLAGS)
