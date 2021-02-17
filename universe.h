#pragma once
#include <ncurses.h>

#define ALIVE 1
#define DEAD 0

class Universe
{
private:
    int row;
    int col;
    int cells[1000][1000];
    bool is_ok(int n)
    {
        return n % 2 == 0 || n % 7 == 0;
    }
    int neighbour_count(int y, int x)
    {
        int count = 0;

        int north = y == 0 ? row - 1 : y - 1;
        int south = y == row - 1 ? 0 : y + 1;
        int west = x == 0 ? col - 1 : x - 1;
        int east = x == col - 1 ? 0 : x + 1;

        count += cells[north][west];
        count += cells[north][x];
        count += cells[north][east];
        count += cells[y][west];
        count += cells[y][east];
        count += cells[south][west];
        count += cells[south][x];
        count += cells[south][east];

        return count;
    }

public:
    Universe()
    {
        row = 32;
        col = 32;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (is_ok(i + j))
                    cells[i][j] = 1;
                else
                    cells[i][j] = 0;
            }
        }
    }

    void tick()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int count = neighbour_count(i, j);

                if (cells[i][j] == ALIVE && count < 2)
                    cells[i][j] = DEAD;
                else if (cells[i][j] == ALIVE && (count == 2 || count == 3))
                    continue;
                else if (cells[i][j] == ALIVE && count > 3)
                    cells[i][j] = DEAD;
                else if (cells[i][j] = DEAD && count == 3)
                    cells[i][j] = ALIVE;
            }
        }
    }

    void render()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cells[i][j] ? printw("*") : printw(" ");
            }
            printw("\n");
        }
    }
};