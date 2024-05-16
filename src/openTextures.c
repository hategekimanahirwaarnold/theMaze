#include "maze.h"

/**
 * openTextures - open textures from file and puts pixel information in buffer
 * @mapName: name of map loaded
 * Return: void
 */
void openTextures(char *mapName)
{
	SDL_Surface *textureSrfc[TEX_COUNT];
	uint8_t *pixel;
	int i, j, k;

	if (strcmp(mapName, "maps/map_0") == 0)
	{
		textureSrfc[0] = IMG_Load("textures/wall1.png");
		textureSrfc[1] = IMG_Load("textures/wall2.png");
		textureSrfc[2] = IMG_Load("textures/windowtree.png");
		textureSrfc[3] = IMG_Load("textures/windowspooky.png");
		textureSrfc[4] = IMG_Load("textures/ceiling.png");
		textureSrfc[5] = IMG_Load("textures/floorboards.png");
	}
	else
	{
		textureSrfc[0] = IMG_Load("textures/hedge1.png");
		textureSrfc[1] = IMG_Load("textures/hedge2.png");
		textureSrfc[2] = IMG_Load("textures/gate.png");
		textureSrfc[3] = IMG_Load("textures/hedge1.png");
		textureSrfc[4] = IMG_Load("textures/sky.png");
		textureSrfc[5] = IMG_Load("textures/grass.png");
	}

	/* get colors from texture pixels and put in array */
	for (i = 0; i < TEX_COUNT; i++)
	{
		for (j = 0; j < TEX_HEIGHT; j++)
		{
			for (k = 0; k < TEX_WIDTH; k++)
			{
				/**
				 * Allocates space for each pixel
				 * */	
				pixel = (uint8_t *)textureSrfc[i]->pixels
					+ k * textureSrfc[i]->pitch + j *
					textureSrfc[i]->format->BytesPerPixel;
				/**
				 * Red occupies the first 8 (0 - 7) bits
				 * Green occupies 8 - 15 bit positions
				 * Blue occupies 16 - 23 bit positions
				*/
				tiles[i][j][k] = pixel[0] | pixel[1] << 8
					| pixel[2] << 16;
			}
		}
	}

	/* free created surfaces */
	for (i = 0; i < TEX_COUNT; i++)
	{
		SDL_FreeSurface(textureSrfc[i]);
		textureSrfc[i] = NULL;
	}
}
