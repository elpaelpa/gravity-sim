#pragma once
#include <raylib.h>  // for Color (only needed because Body stores its display color)

typedef struct{
    float mass;
    float x,y;
    float vx,vy;
    float radius;
    Color color;
}Body;

// Gravitational constant (simulation units, tune by trial)
const float G = 5000.0f;

// Advance all bodies by dt seconds.
void step(Body* bodies, int n, float dt);
