#ifndef GLOBAL_H
#define GLOBAL_H

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
extern uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
extern point_t pos;
extern point_t dir;
extern point_t plane;
extern double currentTime;
extern Rain rain;

#endif /* GLOBAL_H */
