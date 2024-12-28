#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

void drawPlayer(Player *player);
void drawMap(Map *map);
void drawEnemy(Enemy *enemy);

#endif // RENDERER_H