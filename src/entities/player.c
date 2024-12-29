#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "collision.h"

Player createPlayer(Vector2 position, Texture2D texture, int t) {
    Player player;
    player.physics.transform.position = position;
    player.physics.transform.collider = (Rectangle){ position.x, position.y, 32, 32 };
    player.physics.speed = (Vector2){ 0, 0 };
    player.physics.collision = (CollisionBox){ false, false, false, false };
    player.health = 100;
    player.texture = texture;
    return player;
}

void updatePlayer(Player *player, Map *map) {
    if(!player->physics.collision.bottom) player->physics.speed.y += GRAVITY;
    // collider is used both for collision detection and rendering, but also allows use of old position in player->position when collision is detected
    player->physics.transform.collider.x = player->physics.transform.position.x + player->physics.speed.x;
    player->physics.transform.collider.y = player->physics.transform.position.y + player->physics.speed.y;

    checkPlayerCollision(player, map);

    Vector2 targetPosition = player->physics.transform.position;

    if (player->physics.collision.bottom || player->physics.transform.collider.y /*+ player->physics.transform.collider.height */> MAP_HEIGHT * TILE_SIZE) {
        TraceLog(LOG_INFO, "Player collided with bottom");
        if(player->physics.speed.y > 0) player->physics.speed.y = 0;
        targetPosition.y = player->physics.transform.collider.y; //reset collider to original position
    }
    if (player->physics.collision.top || player->physics.transform.collider.y < 0 ) {
        TraceLog(LOG_INFO, "Player collided with top");
        if(player->physics.speed.y < 0) player->physics.speed.y = 0;
        targetPosition.y = player->physics.transform.collider.y;
    }
    if (player->physics.collision.left || player->physics.transform.collider.x < 0) {
        TraceLog(LOG_INFO, "Player collided with left");
        if(player->physics.speed.x < 0) player->physics.speed.x = 0;
        targetPosition.x = player->physics.transform.collider.x;
    }
    if (player->physics.collision.right || player->physics.transform.collider.x + player->physics.transform.collider.width > MAP_WIDTH * TILE_SIZE) {
        TraceLog(LOG_INFO, "Player collided with right");
        if(player->physics.speed.x > 0) player->physics.speed.x = 0;
        targetPosition.x = player->physics.transform.collider.x;
    }

    player->physics.transform.position = Vector2Lerp(player->physics.transform.position, targetPosition, 0.1f);

    // If collision occurred, the collider will already be set to the old position. If no collision occurred, position is updated
    player->physics.transform.position.x = player->physics.transform.collider.x;
    player->physics.transform.position.y = player->physics.transform.collider.y;
}