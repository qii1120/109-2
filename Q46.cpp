#include <iostream>
using namespace std;
int main()
{
    int row, col;
    int x, y;
    char dir;
    string move;
    cin >> col >> row;
    int grid[row + 3][col + 3];
    for (int i = 0; i < row + 3; i++)
    {
        for (int j = 0; j < col + 3; j++)
        {
            if (i == 0 || i == row + 2 || j == 0 || j == col + 2)
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }
    while (cin >> x >> y >> dir >> move)
    {
        for (int i = 0; i < move.length(); i++)
        {
            if (dir == 'N')
            {
                if (move[i] == 'R')
                {
                    dir = 'E';
                }
                else if (move[i] == 'L')
                {
                    dir = 'W';
                }
                else if (move[i] == 'F')
                {
                    y++;
                    if (grid[y + 1][x + 1] == 1)
                    {
                        if (grid[y][x + 1] == 2)
                        {
                            y--;
                        }
                        else
                        {
                            cout << x << " " << y - 1 << " " << dir << " LOST" << endl;
                            grid[y][x + 1] = 2;
                            break;
                        }
                    }
                }
            }
            else if (dir == 'S')
            {
                if (move[i] == 'R')
                {
                    dir = 'W';
                }
                else if (move[i] == 'L')
                {
                    dir = 'E';
                }
                else if (move[i] == 'F')
                {
                    y--;
                    if (grid[y + 1][x + 1] == 1)
                    {
                        if (grid[y + 2][x + 1] == 2)
                        {
                            y++;
                        }
                        else
                        {
                            cout << x << " " << y + 1 << " " << dir << " LOST" << endl;
                            grid[y + 2][x + 1] = 2;
                            break;
                        }
                    }
                }
            }
            else if (dir == 'E')
            {
                if (move[i] == 'R')
                {
                    dir = 'S';
                }
                else if (move[i] == 'L')
                {
                    dir = 'N';
                }
                else if (move[i] == 'F')
                {
                    x++;
                    if (grid[y + 1][x + 1] == 1)
                    {
                        if (grid[y + 1][x] == 2)
                        {
                            x--;
                        }
                        else
                        {
                            cout << x - 1 << " " << y << " " << dir << " LOST" << endl;
                            grid[y + 1][x] = 2;
                            break;
                        }
                    }
                }
            }
            else if (dir == 'W')
            {
                if (move[i] == 'R')
                {
                    dir = 'N';
                }
                else if (move[i] == 'L')
                {
                    dir = 'S';
                }
                else if (move[i] == 'F')
                {
                    x--;
                    if (grid[y + 1][x + 1] == 1)
                    {
                        if (grid[y + 1][x + 2] == 2)
                        {
                            x++;
                        }
                        else
                        {
                            cout << x + 1 << " " << y << " " << dir << " LOST" << endl;
                            grid[y + 1][x + 2] = 2;
                            break;
                        }
                    }
                }
            }
            if (i == move.length() - 1)
            {
                std::cout << x << " " << y << " " << dir << endl;
            }
        }
    }
    return 0;
}