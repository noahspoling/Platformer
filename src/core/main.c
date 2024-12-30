#include "raylib.h"
#include "config.h"
#include "game.h"
#include "player.h"
#include "input.h"
#include "renderer.h"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib - CRT Shader Example");
    GameState gameState;
    RenderState renderState;
    renderState.tileSize = TILE_SIZE;
    
    gameState.screen = GAME_MENU;

    gameState.player.physics.transform.position = (Vector2){ 0, 0 };
    gameState.player.physics.transform.collider = (Rectangle){ 0, 0, 32, 32 };

    SetTargetFPS(60);

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) 
    {
        float deltaTime = GetFrameTime();
        switch (gameState.screen)
        {
        case GAME_MENU:
            if (IsKeyPressed(KEY_ENTER)) {
                gameState.screen = GAME_PLAYING;
                createMap(&gameState.map);
            }
            BeginDrawing();
                ClearBackground(RED);
                DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 100, BLUE);
                DrawText("Press Enter to start", 10, 10, 20, WHITE);
            EndDrawing();
            break;
        case GAME_PLAYING:
            handlePlayerInput(&gameState.player);
            updatePlayer(&gameState.player, gameState.map);
            BeginDrawing();
                ClearBackground(BLACK);
                drawPlayer(&gameState.player, &renderState);
                drawMap(gameState.map, &renderState);
            EndDrawing();
            break;
        case GAME_OVER:
            /* code */
            break;
        default:
            break;
        }
    }

    // De-Initialization
    CloseWindow();

    return 0;
}