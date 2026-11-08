#include <raylib.h>
#include "physics.h"

int main(void){
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(0,0,"Test Window");  // 0,0 = use the monitor's resolution
    SetTargetFPS(60);

    const float cx = GetScreenWidth() / 2.0f;
    const float cy = GetScreenHeight() / 2.0f;

    const int N = 3;
    Body bodies[N] = {
        // mass, x, y, vx, vy, radius, color  (positions relative to screen center)
        {1000.0f, cx - 100.0f, cy,           0.0f,  112.0f, 20.0f, BLUE},
        {1000.0f, cx + 100.0f, cy,           0.0f, -112.0f, 20.0f, ORANGE},
        {1000.0f, cx,          cy + 150.0f,  0.0f, 0.0f, 20.0f, GREEN},
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
