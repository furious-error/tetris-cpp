#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);

public:
    Grid();
    int grid[20][10];
    void Initialize();
    void Print();
    void Draw();
    bool isCellOutside(int row, int col);
    bool isCellEmpty(int row, int col);
    int ClearFullRows();
};