#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

#include "raylib.h"
#include "transform.h"
#include "collisionBox.h"

/*
    For objects that have physics and need speed and acceleration
    uses transform for its position values
*/

typedef struct PhysicsBody
{
    GameTransform transform;
    Vector2 speed;
    Vector2 acceleration;
    CollisionBox collision;
} PhysicsBody;



#endif // PHYSICS_H