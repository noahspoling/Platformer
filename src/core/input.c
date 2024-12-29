#include "raylib.h"

#include "config.h"
#include "player.h"

void handlePlayerInput(Player *player)
{
    if (IsKeyDown(KEY_RIGHT)) {
        player->physics.speed.x += PLAYER_SPEED;
        player->physics.acceleration.x += PLAYER_ACCELERATION;

        if (player->physics.speed.x > MAX_PLAYER_SPEED) player->physics.speed.x = MAX_PLAYER_SPEED;
        // if (player->physics.acceleration.x > MAX_PLAYER_ACCELERATION) player->physics.acceleration.x = MAX_PLAYER_ACCELERATION;
    }
    if (IsKeyDown(KEY_LEFT)) {
        player->physics.speed.x -= PLAYER_SPEED;
        player->physics.acceleration.x -= PLAYER_ACCELERATION;

        if (player->physics.speed.x < -MAX_PLAYER_SPEED) player->physics.speed.x = -MAX_PLAYER_SPEED;
        // if (player->physics.acceleration.x < -MAX_PLAYER_ACCELERATION) player->physics.acceleration.x = -MAX_PLAYER_ACCELERATION;
    }

    if (IsKeyPressed(KEY_SPACE) && player->physics.collision.bottom)
    {
        player->physics.speed.y = -10;
        player->physics.collision.bottom = false;
    }

    if (IsKeyPressed(KEY_X) /* shootProjectile(player) **/);



}