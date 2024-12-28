#ifndef COLLISION_H
#define COLLISION_H

#include "player.h"
#include "map.h"
#include "enemy.h"


void checkMooreNeighborhood(Player *player, Map *map);
void checkPlayerCollision(Player *player, Map *map);
void checkEnemyPlayerCollision(Enemy *enemy, Player *player);
void checkEnemyCollision(Enemy *enemy, Map *map);


#endif // COLLISION_H