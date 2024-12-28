#ifndef GAMETRANSFORM_H
#define GAMETRANSFORM_H

#include "raylib.h"

typedef struct GameTransform {
    Rectangle collider;
    Vector2 position;
} GameTransform;


#endif // GAMETRANSFORM_H