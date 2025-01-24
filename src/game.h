#pragma once

#include "grid.h"
#include "blocks.cpp"

class Game{
    private:
        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Sound rotateSound;
        Sound clearSound;
        std::vector<Block> GetAllBlocks();
        Block GetRandomBlock();
        bool isBlockOutside();
        void RotateBlock();
        bool BlockFits();
        void Reset();
        void LockBlock();
        void UpdateScore(int linesCleared, int moveDownPoints);
        void MoveBlockLeft();
        void MoveBlockRight();

    public:
        Game();
        ~Game();
        bool gameOver;
        int score;
        Music music;
        void Draw();
        void HandleInput();
        void MoveBlockDown();
};