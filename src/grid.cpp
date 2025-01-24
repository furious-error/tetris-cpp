#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize(){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            grid[row][col] = 0;
        }
    }
}

void Grid::Print(){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            std::cout << grid[row][col] << " ";
        }
        std::cout << '\n';
    }
}

void Grid::Draw(){
    for(int row = 0; row < numRows; row++){
        for(int col = 0; col < numCols; col++){
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);

        }
    }
}

bool Grid::isCellOutside(int row, int col){
    if(row >= 0 && row < numRows && col >= 0 && col < numCols){
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int col){
    if(grid[row][col] == 0){
        return true;
    }
    return false;
}

bool Grid::isRowFull(int row){
    for(int column = 0; column < numCols; column++){
        if(grid[row][column] == 0){
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for(int column = 0; column < numCols; column++){
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows){
    for(int col = 0; col < numCols; col++){
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}

int Grid::ClearFullRows(){
    int completed = 0;
    for(int row = numRows - 1; row >= 0; row--){
        if(isRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if(completed > 0){
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

