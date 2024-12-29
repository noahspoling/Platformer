#ifndef RENDER_STATE_H
#define RENDER_STATE_H

/*
    Keeps track of the size of screen to scale the textures to a 4:3 aspect ratio
*/
typedef struct RenderState {
    int screenWidth;
    int screenHeight;
    int tileSize;
    int mapWidth;
    int mapHeight;
} RenderState;

#endif // RENDER_STATE_H