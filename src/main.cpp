#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

int main()
{
    Color GREY = {29, 29, 29, 255};

    const int WINDOW_WIDTH = 1000; // Increased width to add space for stats
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int FPS = 12;
    const int GRID_WIDTH = 750;
    const int GRID_HEIGHT = 750;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    Simulation simulation(GRID_WIDTH, GRID_HEIGHT, CELL_SIZE);
    // Simulation Loop
    while (!WindowShouldClose())
    {
        // 1. Event handler
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            if (mousePosition.x < 750) // Ensure clicks are within the grid
            {
                int row = mousePosition.y / CELL_SIZE;
                int col = mousePosition.x / CELL_SIZE;
                simulation.ToggleCell(row, col);
            }
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Life is running");
        }
        else if (IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life has stopped");
        }
        else if (IsKeyPressed(KEY_F))
        {
            FPS += 2;
            SetTargetFPS(FPS);
        }
        else if (IsKeyPressed(KEY_S))
        {
            if (FPS > 5)
            {
                FPS -= 2;
                SetTargetFPS(FPS);
            }
        }
        else if (IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

        // 2. Updating State
        simulation.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(GREY);

        // Draw simulation grid
        simulation.Draw();

        // Draw the side panel background
        DrawRectangle(750, 0, WINDOW_WIDTH - 750, WINDOW_HEIGHT, BLACK);

        // Draw stats
        DrawText("Stats:", 760, 20, 20, WHITE);

        char buffer[128];
        sprintf(buffer, "FPS: %d", FPS);
        DrawText(buffer, 760, 50, 20, WHITE);

        int generation = simulation.GetGenerationCount();
        sprintf(buffer, "Generation: %d", generation);
        DrawText(buffer, 760, 80, 20, WHITE);

        int liveCells = simulation.GetLiveCellCount();
        DrawText(TextFormat("Live Cells: %d", liveCells), 760, 110, 20, WHITE);

        // Draw commands/instructions
        DrawText("Commands:", 760, 150, 20, WHITE);
        DrawText("Enter: Start", 760, 180, 20, WHITE);
        DrawText("Space: Stop", 760, 210, 20, WHITE);
        DrawText("F: Faster", 760, 240, 20, WHITE);
        DrawText("S: Slower", 760, 270, 20, WHITE);
        DrawText("R: Random state", 760, 300, 20, WHITE);
        DrawText("C: Clear grid", 760, 330, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
}
