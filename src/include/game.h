#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "enemy.h"
#include "map.h"

typedef enum ScreenState {
    GAME_MENU,
    GAME_PLAYING,
    GAME_OVER
} ScreenState;

typedef struct GameState {
    ScreenState screen;
    Player player;
    Enemy enemies[MAX_ENEMIES];
    Map *map;
} GameState;

// static void runGame();

#endif // GAME_H