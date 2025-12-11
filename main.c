#include "raylib.h"
#include <stdlib.h>
//#include <time.h>


#define ROWS 40             // Height of the grid
#define COLS 60             // Width of the grid
#define CELL_SIZE 15        // Size of each square in pixels
#define SIMULATION_SPEED 10 // How fast it runs (Frames Per Second)

// GLOBAL VARIABLES
//Need TWO grids to prevent the "Double Buffer" bug.
// grid[y][x]: The current generation.
// next_grid[y][x]: The calculation area for the next frame.
int grid[ROWS][COLS];
int next_grid[ROWS][COLS];

// FUNCTIONS
//void InitGrid();
void DrawGameGrid();
void ComputeNextGeneration();
int CountNeighbors(int y, int x);

int main(void) {
    // 1. Setup Window
    InitWindow(COLS * CELL_SIZE, ROWS * CELL_SIZE, "Conway's Game of Life - Final Skeleton");
    SetTargetFPS(SIMULATION_SPEED);

    // 2. Initialize Random Seed & Grid

    //InitGrid();

    // Variable to track if game is paused
    bool isPaused = true;

    // MAIN GAME LOOP
    while (!WindowShouldClose()) {

        //INPUT HANDLING
        // SPACE: Toggle Pause
        if (IsKeyPressed(KEY_SPACE)) {
            isPaused = !isPaused;
        }
        // R: Reset to Random
        if (IsKeyPressed(KEY_R)) {
            for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            grid[y][x] = rand()%2;
        }
    }
        }
        // C: Clear Board (All Dead)
        if (IsKeyPressed(KEY_C)) {
            for(int y=0; y<ROWS; y++)
            for(int x=0; x<COLS; x++){
                    grid[y][x] = 0;
            }
        }

        // MOUSE: Draw Life (Only works if we know where the mouse is)
       // MOUSE INPUT (The Level Editor)
        struct Vector2 mousePos = GetMousePosition();
        int mouseX = mousePos.x / CELL_SIZE;
        int mouseY = mousePos.y / CELL_SIZE;

        // Check if mouse is inside the grid
        if (mouseX >= 0 && mouseX < COLS && mouseY >= 0 && mouseY < ROWS) {

            // Left Click: Draw Life
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                grid[mouseY][mouseX] = 1;
            }

            // Right Click: Erase Life
            if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
                grid[mouseY][mouseX] = 0;
            }
        }

        // UPDATE LOGIC
        // Only calculate the next generation if we are NOT paused
        if (!isPaused) {
            ComputeNextGeneration();
        }

        //DRAWING
        DrawGameGrid();

        if (isPaused) {
            DrawText("SETUP MODE", 10, 10, 20, RED);
            DrawText("Left Click to Draw | Right Click to Erase", 10, 40, 20, DARKGRAY);
            DrawText("Press SPACE to Start", 10, 70, 20, DARKGRAY);
        }
        //else {
           // DrawText("SETUP MODE", 10, 10, 20, WHITE);
           // DrawText("Left Click to Draw | Right Click to Erase", 10, 40, 20, WHITE);
           // DrawText("Press SPACE to Start", 10, 70, 20, WHITE);
       // }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

//FUNCTION DEFINITIONS
// Fills the grid with 0s (All Dead)
/*void InitGrid() {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            grid[y][x] = rand()%2;
        }
    }
}*/

// 2. Draws the grid based on the 'grid' array
void DrawGameGrid() {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            if (grid[y][x] == 1) {
                // Alive: Draw Black Box
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE - 1, CELL_SIZE - 1, BLACK);
            } else {
                // Dead: Draw Faint Grid Lines and White Box
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, WHITE);
                DrawRectangleLines(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, LIGHTGRAY);

            }
        }
    }
}

// 3. The Brains
void ComputeNextGeneration() {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {

            //Count how many alive neighbors this cell has
            int neighbors = CountNeighbors(y, x);

            //Apply The 3 Rules
            // Rule 1: Loneliness (0-1 neighbors) -> Dies
            if (grid[y][x] == 1 && (neighbors < 2)) {
                next_grid[y][x] = 0;
            }
            // Rule 2: Overpopulation (4+ neighbors) -> Dies
            else if (grid[y][x] == 1 && (neighbors > 3)) {
                next_grid[y][x] = 0;
            }
            // Rule 3: Reproduction (Exactly 3 neighbors) -> Becomes Alive
            else if (grid[y][x] == 0 && (neighbors == 3)) {
                next_grid[y][x] = 1;
            }
            // Otherwise: Stays the same
            else {
                next_grid[y][x] = grid[y][x];
            }
        }
    }

    // Step C: Swap the Grids
    // Copy 'next_grid' into 'grid' to show it on the next frame
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            grid[y][x] = next_grid[y][x];
        }
    }
}

// 4. The Math: Counts the 8 neighbors around a cell
int CountNeighbors(int y, int x) {
    int sum = 0;
    // Loop from -1 to +1 on both axes
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            // Skip the center cell (itself)
            if (i == 0 && j == 0) continue;

            int col = x + j;
            int row = y + i;

            // Check Boundaries! Don't look outside the array.
            if (col >= 0 && col < COLS && row >= 0 && row < ROWS) {
                sum += grid[row][col];
            }
        }
    }
    return sum;
}
