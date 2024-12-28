#include "collision.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

void checkMooreNeighborhood(Player *player, Map *map) {
    for(int x = player->physics.transform.collider.x - 1; x < player->physics.transform.collider.x + 1; x++) {
        for(int y = player->physics.transform.collider.y - 1; y < player->physics.transform.collider.y + 1; y++) {
            if(map->tiles[x][y] == 1) {
                player->physics.collision.bottom = true;
            }
        }
    }
}
void checkPlayerCollision(Player *player, Map *map) {
    
}
void checkEnemyPlayerCollision(Enemy *enemy, Player *player) {

}
void checkEnemyCollision(Enemy *enemy, Map *map) {

}

