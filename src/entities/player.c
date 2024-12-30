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
    updatePhysicsBody(&player->physics, GetFrameTime());
    checkPlayerCollision(player, map);
    
}