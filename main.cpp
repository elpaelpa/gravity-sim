#include <raylib.h>
#include "physics.h"

int main(void){
    InitWindow(800,600,"Test Window");
    SetTargetFPS(60);

    const int N = 3;
    Body bodies[N] = {
        // mass, x, y, vx, vy, radius, color
        {1000.0f, 300.0f, 300.0f, 0.0f, 0.0f, 20.0f, BLUE},
        {1000.0f, 500.0f, 300.0f, 0.0f, 0.0f, 20.0f, ORANGE},
        {1000.0f, 400.0f, 450.0f, 0.0f, 0.0f, 20.0f, GREEN},
    };

    const float dt = 1.0f / 60.0f;  // fixed timestep

    while(!WindowShouldClose()){
        step(bodies, N, dt);

        BeginDrawing();
        ClearBackground(BLACK);
        for(int i = 0; i < N; i++){
            DrawCircle((int)bodies[i].x, (int)bodies[i].y, bodies[i].radius, bodies[i].color);
        }
        EndDrawing();
    }

    CloseWindow();
}
