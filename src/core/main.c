#include "raylib.h"

#include "config.h"

#include "game.h"

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Raylib - Hello World");

    GameState gameState;

    gameState.screen = GAME_MENU;




    SetTargetFPS(60);

    while (!WindowShouldClose() && !IsKeyPressed(KEY_ESCAPE)) 
    {
        switch (gameState.screen)
        {
        case GAME_MENU:
            BeginDrawing();

            ClearBackground(RED);

            DrawText("Hello, World!", 190, 200, 20, LIGHTGRAY);

            EndDrawing();
            break;
        case GAME_PLAYING:
            /* code */
            break;
        case GAME_OVER:
            /* code */
            break;
        default:
            break;
        }
        
    }

    CloseWindow();

    return 0;
}