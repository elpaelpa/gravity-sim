#include "physics.h"
#include <cmath>

void step(Body* bodies, int n, float dt){
    // TODO 1: for each body i, compute its acceleration (ax, ay) from every other body j:
    //         dx = xj - xi, dy = yj - yi, r2 = dx*dx + dy*dy + eps*eps
    //         a += G * mj * d / (r2 * sqrt(r2))
    //         (compute ALL accelerations before moving anything)
    // TODO 2: update velocities from accelerations
    // TODO 3: update positions from velocities
    (void)bodies; (void)n; (void)dt;
}
