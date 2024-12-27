#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "stddef.h"
#include "stdlib.h"

#include "flecs.h"
#include "Components/Engine/Scene.h"


// extern Scene *currentScene = NULL;

// Function to switch between scenes
void SwitchScene(ecs_world_t *ecs, Scene *scene);

// Main scene manager functions
void InitCurrentScene(ecs_world_t *ecs);
void UpdateCurrentScene(ecs_world_t *ecs);
void DrawCurrentScene(ecs_world_t *ecs);
void UnloadCurrentScene(ecs_world_t *ecs);

#endif // SCENE_MANAGER_H