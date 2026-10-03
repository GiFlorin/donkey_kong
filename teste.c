#include <raylib.h>

int main(void)
{
    InitWindow(800, 450, "raylib test");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, raylib!", 190, 200, 20, BLACK);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}