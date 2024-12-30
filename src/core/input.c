#include "raylib.h"

#include "config.h"
#include "player.h"

void handlePlayerInput(Player *player, float deltaTime)
{
    if (IsKeyDown(KEY_RIGHT)) {
        // if the player is not moving, set the base speed to PLAYER_SPEED
        if(player->physics.speed.x < PLAYER_SPEED) {
            player->physics.speed.x = PLAYER_SPEED; 
        }
        else { //otherwise, just increase the acceleration if on the ground
            if(player->physics.collision.bottom) {
                player->physics.acceleration.x += PLAYER_ACCELERATION;
            }
            


        }
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

    // decelerates the player by two times the acceleration 
    if(!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT)) {
        if(player->physics.acceleration.x > 0) player->physics.acceleration.x -= PLAYER_ACCELERATION * (deltaTime * 2);
        if(player->physics.acceleration.x < 0) player->physics.acceleration.x += PLAYER_ACCELERATION * (deltaTime * 2);
    }

    if (IsKeyPressed(KEY_X) /* shootProjectile(player) **/);



}