/*******************************************************************************************
 *
 *   raylib [core] example - Keyboard input
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
 *
 *   Copyright (c) 2014 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include <stdio.h>
#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    char msg[100];
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    float delta = 2.0f;
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_F)) ToggleFullscreen();
        // Update
        
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W)) delta += 0.1f;
        if (IsKeyDown(KEY_Q)) delta -= 0.1f;
        
        if (IsKeyDown(KEY_RIGHT)) {
            if (ballPosition.x < screenWidth)
                ballPosition.x += delta;
        }
        if (IsKeyDown(KEY_LEFT)) {
            if (ballPosition.x > 0)
                ballPosition.x -= delta;
        }
        if (IsKeyDown(KEY_UP)) {
            if (ballPosition.y > 0)
                ballPosition.y -= delta;
        }
        if (IsKeyDown(KEY_DOWN)) {
            if (ballPosition.y < screenHeight)
                ballPosition.y += delta;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        sprintf (msg, "move the ball with arrow keys. delta: %4.2f | pos: (x: %4.0f, y: %4.0f)", delta, ballPosition.x, ballPosition.y);

        DrawText(msg, 10, 10, 20, DARKGRAY);

        DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
