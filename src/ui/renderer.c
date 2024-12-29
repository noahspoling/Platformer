
#include "raylib.h"
#include "renderer.h"
#include "renderState.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

void drawPlayer(Player *player, RenderState *renderState) {
    Rectangle source = { 0, 0, 32, 32 };
    Rectangle dest = { player->physics.transform.position.x, player->physics.transform.position.y, 32, 32 };
    // DrawTexturePro(player->texture, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
    TraceLog(LOG_INFO, "Player position x: %f y: %f", player->physics.transform.position.x, player->physics.transform.position.y);
    DrawRectangle(player->physics.transform.position.x, player->physics.transform.position.y, 32, 32, RED);
}
void drawMap(Map *map, RenderState *renderState) {
    for (int x = 0; x < renderState->mapWidth; x++) {
        for (int y = 0; y < renderState->mapHeight; y++) {
            int tile = map->tiles[x][y];
            if (tile != 0) {
                Rectangle source = { (tile % 8) * renderState->tileSize, (tile / 8) * renderState->tileSize, renderState->tileSize, renderState->tileSize };
                Rectangle dest = { x * renderState->tileSize, y * renderState->tileSize, renderState->tileSize, renderState->tileSize };
                DrawTexturePro(map->tileset, source, dest, (Vector2){0, 0}, 0.0f, WHITE);
            }
        }
    }
}
void drawEnemy(Enemy *enemy, RenderState *renderState) {}