#include "physics.h"
#include <cmath>
#include <vector>

static const float EPS = 5.0f;  // softening: avoids huge forces at tiny separations

// Fill ax/ay with the acceleration of every body due to all the others.
static void computeAccelerations(const Body* bodies, int n, std::vector<float>& ax, std::vector<float>& ay){
    for(int i = 0; i < n; i++){
        ax[i] = 0.0f;
        ay[i] = 0.0f;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            float dx = bodies[j].x - bodies[i].x;
            float dy = bodies[j].y - bodies[i].y;
            float r2 = dx*dx + dy*dy + EPS*EPS;
            float invR3 = 1.0f / (r2 * std::sqrt(r2));
            ax[i] += G * bodies[j].mass * dx * invR3;
            ay[i] += G * bodies[j].mass * dy * invR3;
        }
    }
}

// Leapfrog (kick-drift-kick): symplectic, so energy stays bounded over long runs.
void step(Body* bodies, int n, float dt){
    std::vector<float> ax(n), ay(n);

    // half kick
    computeAccelerations(bodies, n, ax, ay);
    for(int i = 0; i < n; i++){
        bodies[i].vx += 0.5f * dt * ax[i];
        bodies[i].vy += 0.5f * dt * ay[i];
    }

    // drift
    for(int i = 0; i < n; i++){
        bodies[i].x += dt * bodies[i].vx;
        bodies[i].y += dt * bodies[i].vy;
    }

    // half kick with the new accelerations
    computeAccelerations(bodies, n, ax, ay);
    for(int i = 0; i < n; i++){
        bodies[i].vx += 0.5f * dt * ax[i];
        bodies[i].vy += 0.5f * dt * ay[i];
    }
}
