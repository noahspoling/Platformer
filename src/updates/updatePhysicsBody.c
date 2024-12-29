#include "config.h"
#include "physicsBody.h"
#include "collisionBox.h"

void updatePhysicsBody(PhysicsBody *body, float deltaTime) {
    body->speed.x += body->acceleration.x * deltaTime;
    body->speed.y += body->acceleration.y * deltaTime;

    if(body->speed.x > MAX_PLAYER_SPEED) {
        body->speed.x = MAX_PLAYER_SPEED;
    }
    if(body->speed.x < -MAX_PLAYER_SPEED) {
        body->speed.x = -MAX_PLAYER_SPEED;
    }

    body->transform.position.x += body->speed.x * deltaTime;
    body->transform.position.y += body->speed.y * deltaTime;
}