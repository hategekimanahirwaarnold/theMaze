#include "maze.h"

void draw(Particle* self)
{
    if (self->y + self->height > 0)
    {
        // printf("we are drawing! x: %f,y: %f\n", self->x, self->y);
        SDL_SetRenderDrawColor(renderer, 181, 179, 179, 255);
        SDL_RenderDrawLine(renderer, self->x, self->y, self->x, self->y + self->height);
    } 
}

void rain_update()
{
    if (rain.fall)
    {
        for (int i = 0; i < PARTICLES_COUNT; i++)
        {
            if (rain.particles[i].y < (SCREEN_HEIGHT))
                rain.particles[i].y += rain.particles[i].gravity;
            else
            {
                rain.particles[i].y = (rand() % 5) * -1;
                rain.particles[i].gravity = (rand() % 20 + 10);
            }
            rain.particles[i].draw(&rain.particles[i]);
        }
    } else
    {
        for (int i = 0; i < PARTICLES_COUNT; i++)
        {
            rain.particles[i].y = (rand() % 5) * -1;
        }
    }
}

void rain_constructor()
{
    srand(time(NULL));
    rain.fall = false;
    rain.pressed = false;
    for (int i = 0; i < PARTICLES_COUNT; i++) 
    {
        rain.particles[i].x = rand() % (SCREEN_WIDTH - 1) + 1;
        rain.particles[i].y = (rand() % 10) * -1;
        rain.particles[i].height = (rand() & 6) + 1;
        rain.particles[i].gravity = (rand() % 20 + 10);
        rain.particles[i].draw = &draw;
    }
}
