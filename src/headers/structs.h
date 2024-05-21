#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * struct point_s - holds x/y point coordinates of a double type
 * @x: X coordinate
 * @y: Y coordinate
 * Description: struct point
 */
typedef struct point_s
{
	double x;
	double y;
} point_t;

typedef struct particle_s
{
	double y;
	double x;
	double height;
	double gravity;
	void (*draw)(struct particle_s*);
} Particle;

typedef struct rain_s
{
	bool fall;
	bool pressed;
	Particle particles[PARTICLES_COUNT];
	void (*update)(struct rain_s);
} Rain;

#endif /* STRUCTS_H */
