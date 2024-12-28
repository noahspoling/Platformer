#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "physicsBody.h"
#include "map.h"

typedef struct Player {
    PhysicsBody physics;
    int health;
    // bool onGround;
    int jumpTimer;
    Texture2D texture;
} Player;

void updatePlayer(Player *player, Map *map);

#endif // PLAYER_H