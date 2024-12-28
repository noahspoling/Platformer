#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "player.h"
#include "physicsBody.h"
#include "map.h"

typedef struct Enemy {
    PhysicsBody physics;
    bool onGround;
    int health;
    // Texture2D texture; //wil need to be a pointer to a texture
} Enemy;

void updateEnemy(Enemy *enemy, Player *player, Map *map);
#endif // ENEMY_H