#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block{
    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int columnOffset;

    public:
        Block();
        int id;
        std::vector<Color> colors;
        std::map<int, std::vector<Position>> cells;
        void Draw(int offsetX, int offsetY);
        void Move(int row, int column);
        std::vector<Position> GetCellPositions();
        void Rotate();
        void UndoRotation();
};