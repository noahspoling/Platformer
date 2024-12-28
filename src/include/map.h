#ifndef MAP_H
#define MAP_H

#include "raylib.h"
#include "config.h"

typedef struct Map {
    int tiles[MAP_WIDTH][MAP_HEIGHT];
    Texture2D tileset;
} Map;

void loadMap(Map *map, const char *filename);
void createMap(Map *map);
void addFloor(Map *map, int x, int y, int width, int tile);
void addWall(Map *map, int x, int y, int height, int tile);
void setTile(Map *map, int x, int y, int tile);

#endif // MAP_H