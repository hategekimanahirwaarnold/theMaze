#ifndef MAZE_H
#define MAZE_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800
#define TEX_COUNT 6
#define TEX_WIDTH 64
#define TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAP_CHAR_COUNT 1275
#define PARTICLES_COUNT 1000

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "structs.h"
#include "global.h"

int *readMap(char *filename, int *map);
void openTextures(char *mapName);
bool init(void);
void updateRenderer(bool textured);
void close_file(void);
void handle_inputs(int *maze);
bool quit(void);
void cast_ray(int *maze, bool textured);
void show_walls(int *maze, SDL_Point map, point_t rayPos, point_t rayDir,
			double distToWall, int x, int side, bool textured);

void show_flat_background(void);
void show_textured_background(SDL_Point map, point_t rayDir, double distToWall,
					double wallX, int drawEnd, int x, int side);

void rain_constructor();
void rain_update();

#endif /* MAZE_H */
