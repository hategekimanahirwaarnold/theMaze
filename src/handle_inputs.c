#include "maze.h"

/**
 * handle_inputs - handles user inputs for movement
 * @maze: 2D array defining maze map
 * Return: void
 */
void handle_inputs(int *maze)
{
	const uint8_t *keystate;
	double oldTime;
	double frameTime;
	double oldDirX, oldPlaneX;
	double moveSpeed;
	double rotateSpeed;

	keystate = SDL_GetKeyboardState(NULL);
	oldTime = currentTime;
	currentTime = SDL_GetTicks();
	frameTime = (currentTime - oldTime) / 1000.0;
	moveSpeed = frameTime * 5.0;
	rotateSpeed = frameTime * 3.0;

	/* move forward if no wall in front */
	if (keystate[SDL_SCANCODE_W])
	{
		if (!*((int *)maze + (int)(pos.x + dir.x * moveSpeed)
		       * MAP_WIDTH + (int)pos.y))
			pos.x += dir.x * moveSpeed;
		if (!*((int *)maze + (int)pos.x * MAP_WIDTH +
		       (int)(pos.y + dir.y * moveSpeed)))
			pos.y += dir.y * moveSpeed;
	}

	/* move backward if no wall behind */
	if (keystate[SDL_SCANCODE_S])
	{
		if (!*((int *)maze + (int)(pos.x - dir.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= dir.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - dir.y * moveSpeed)))
			pos.y -= dir.y * moveSpeed;
	}

	if (keystate[SDL_SCANCODE_Q])
	{
		if (!*((int *)maze + (int)(pos.x - plane.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x -= plane.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y - plane.y * moveSpeed)))
			pos.y -= plane.y * moveSpeed;
	}

	if (keystate[SDL_SCANCODE_E])
	{
		if (!*((int *)maze + (int)(pos.x + plane.x * moveSpeed) *
		       MAP_WIDTH + (int)(pos.y)))
			pos.x += plane.x * moveSpeed;
		if (!*((int *)maze + (int)(pos.x) * MAP_WIDTH +
		       (int)(pos.y + plane.y * moveSpeed)))
			pos.y += plane.y * moveSpeed;
	}

	/* rotate left */
	if (keystate[SDL_SCANCODE_D])
	{
		oldDirX = dir.x;
		dir.x = dir.x * cos(rotateSpeed) - dir.y * sin(rotateSpeed);
		dir.y = oldDirX * sin(rotateSpeed) + dir.y * cos(rotateSpeed);

		oldPlaneX = plane.x;
		plane.x = plane.x * cos(rotateSpeed) - plane.y * sin(rotateSpeed);
		plane.y = oldPlaneX * sin(rotateSpeed) + plane.y * cos(rotateSpeed);
	}

	/* rotate right */
	if (keystate[SDL_SCANCODE_A])
	{
		oldDirX = dir.x;
		dir.x = dir.x * cos(-rotateSpeed) - dir.y * sin(-rotateSpeed);
		dir.y = oldDirX * sin(-rotateSpeed) + dir.y * cos(-rotateSpeed);

		oldPlaneX = plane.x;
		plane.x = plane.x * cos(-rotateSpeed) - plane.y * sin(-rotateSpeed);
		plane.y = oldPlaneX * sin(-rotateSpeed) + plane.y * cos(-rotateSpeed);
	}
}

/**
 * quit - checks if user quits
 * Return: True if user quits, else False
 */
bool quit(void)
{
	SDL_Event event;
	bool quit;
	uint32_t windowFlags;

	quit = false;
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
			quit = true;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			quit = true;

		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_f)
		{
			windowFlags = SDL_GetWindowFlags(window);

			if (windowFlags & SDL_WINDOW_FULLSCREEN)
				SDL_SetWindowFullscreen(window, SDL_FALSE);
			else
				SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		}
	}

	return (quit);
}
