#include "raylib.h"
#include "player.h"
#include "collision.h"

void updatePlayer(Player *player, Map *map) {

    // collider is used both for collision detection and rendering, but also allows use of old position in player->position when collision is detected
    player->physics.transform.collider.x += player->physics.speed.x;
    player->physics.transform.collider.y += player->physics.speed.y;

    if(!player->physics.collision.bottom) player->physics.speed.y += GRAVITY;

    checkPlayerCollision(player, map);
}