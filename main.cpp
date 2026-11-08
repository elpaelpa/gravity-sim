#include <raylib.h>

int main(void){
    InitWindow(800,600,"Test Window");


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(400,300,20,WHITE);
        EndDrawing();
    }


    CloseWindow();

}