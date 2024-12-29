#ifndef CONFIG_H
#define CONFIG_H

// Shader configuration
#define CRT_VERTEX_SHADER_PATH "resources/shaders/crt.vs"
#define CRT_FRAGMENT_SHADER_PATH "resources/shaders/crt.fs"


// Game configuration

#define MAX_ENEMIES 100
#define MAP_WIDTH 40
#define MAP_HEIGHT 30
#define TILE_SIZE 32

#define WINDOW_WIDTH MAP_WIDTH * TILE_SIZE
#define WINDOW_HEIGHT MAP_HEIGHT * TILE_SIZE

#define PLAYER_SPEED 10
#define PLAYER_ACCELERATION 1
#define MAX_PLAYER_SPEED 40
#define MAX_PLAYER_ACCELERATION 10


#define GRAVITY 10


#endif // CONFIG_H