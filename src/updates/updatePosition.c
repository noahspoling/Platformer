#include "updates/updatePosition.h"
#include "config.h"
#include "physicsBody.h"

void updatePosition(PhysicsBody *body, float deltaTime) {
    body->transform.position.x = body->transform.collider.x;
    body->transform.position.y = body->transform.collider.y;
}
