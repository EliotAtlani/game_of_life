#pragma once
#include "grid.hpp"

class Simulation
{
public:
    Simulation(int width, int height, int cellSize) : grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false), count(0) { grid.FillRandom(); };
    void Draw();
    void SetCellValue(int row, int column, int value);
    int CountLiveNeighbors(int row, int column);
    void Update();
    bool IsRunning() { return run; }
    void Start() { run = true; }
    void Stop() { run = false; }
    void ClearGrid();
    void CreateRandomState();
    void ToggleCell(int row, int column);
    int GetGenerationCount();
    int GetLiveCellCount();

private:
    Grid grid;
    Grid tempGrid;
    bool run;
    int count;
};