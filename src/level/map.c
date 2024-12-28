#include "map.h"

void loadMap(Map *map, const char *filename);
void createMap(Map *map) {
    for (int x = 0; x < MAP_WIDTH; x++) {
        for (int y = 0; y < MAP_HEIGHT; y++) {
            map->tiles[x][y] = 0;
        }
    }
}

void addFloor(Map *map, int x, int y, int width, int tile) {
    for (int i = y; i < MAP_WIDTH || i < y+width; i++) {
        setTile(map, i, y, tile);
    }
}

void addWall(Map *map, int x, int y, int height, int tile) {
    for (int i = x; i < MAP_HEIGHT || i < x+height; i++) {
        setTile(map, x, i, tile);
    }
}

void setTile(Map *map, int x, int y, int tile) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        map->tiles[x][y] = tile;
    }
}
