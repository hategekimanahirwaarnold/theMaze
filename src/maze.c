#include "maze.h"
/* Declare global variables */
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
point_t pos;
point_t dir;
point_t plane;
double currentTime;


/**
 * main - main function
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int *maze;
	char *mapName;
	bool textured;

	pos.x = 1;
	pos.y = 12;
	dir.x = 1;
	dir.y = -0.66;
	plane.x = 0;
	plane.y = 0.66;
	currentTime = 0;
	mapName = "\0";

	textured = true;
	if (argc == 3)
	{
		if (strcmp(argv[2], "no_texture") == 0)
			textured = false;
		mapName = argv[1];
	}
	else if (argc == 2)
	{
		if (strcmp(argv[1], "no_texture") == 0)
		{
			mapName = "maps/map_0";
			textured = false;
		}
		else
			mapName = argv[1];
	}
	else if (argc == 1)
		mapName = "maps/map_0";

	/*Initialize window */
	if (!init())
		return (1);

	maze = NULL;
	maze = readMap(mapName, maze);
	if (maze == NULL)
		return (1);

	if (textured)
		openTextures(mapName);

	/* Enter game loop */
	while (!quit())
	{
		if (!textured)
			show_flat_background();

		cast_ray(maze, textured);

		handle_inputs(maze);
	}

	/* release memory and close */
	close_file();
	free(maze);
	return (0);
}
