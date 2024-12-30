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

    // updates the position of the collider and keep position as the old position for validation
    body->transform.collider.x += body->speed.x * deltaTime;
    body->transform.collider.y += body->speed.y * deltaTime;
}