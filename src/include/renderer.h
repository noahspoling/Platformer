#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include "renderState.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

void drawPlayer(Player *player, RenderState *renderState);
void drawMap(Map *map, RenderState *renderState);
void drawEnemy(Enemy *enemy, RenderState *renderState);

#endif // RENDERER_H