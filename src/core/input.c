#include "raylib.h"

#include "config.h"
#include "player.h"

void handlePlayerInput(Player *player)
{
    if (IsKeyDown(KEY_RIGHT)) player->physics.speed.x += PLAYER_SPEED;
    if (IsKeyDown(KEY_LEFT)) player->physics.speed.x -= PLAYER_SPEED;
    // if (IsKeyDown(KEY_UP)) player->speed.y -= PLAYER_SPEED;
    // if (IsKeyDown(KEY_DOWN)) player->speed.y += PLAYER_SPEED;

    if (IsKeyPressed(KEY_SPACE) && player->physics.collision.bottom)
    {
        player->physics.speed.y = -10;
        player->physics.collision.bottom = false;
    }

    if (IsKeyPressed(KEY_X) /* shootProjectile(player) **/);



}