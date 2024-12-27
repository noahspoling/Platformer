#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

typedef void (*SceneInitFunc)(ecs_world_t *ecs);    // Initialize the scene
typedef void (*SceneUpdateFunc)(ecs_world_t *ecs);  // Update the scene logic
typedef void (*SceneDrawFunc)(ecs_world_t *ecs);    // Render the scene
typedef void (*SceneUnloadFunc)(ecs_world_t *ecs);  // Clean up the scene

typedef struct Scene {
    SceneInitFunc init;
    SceneUpdateFunc update;
    SceneDrawFunc draw;
    SceneUnloadFunc unload;


} Scene;

#endif // SCENE_H