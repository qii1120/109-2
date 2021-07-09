#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    int Case, row, col, x, y;
    int back[100] = {0};
    cin >> Case;
    for (int i = 0; i < Case; i++)
    {
        cin >> row >> col;
        char maze[row + 1][2 * col + 1];
        for (int j = 0; j <= row; j++)
        {
            for (int k = 0; k <= 2 * col; k++)
            {
                if (j == row)
                {
                    if (k % 2 == 0)
                    {
                        maze[j][k] = ' ';
                    }
                    else
                    {
                        maze[j][k] = '_';
                    }
                }
                else
                {
                    if (k % 2 == 0)
                    {
                        maze[j][k] = '|';
                    }
                    else
                    {
                        maze[j][k] = '_';
                    }
                }
            }
        }
        cin >> x >> y;
        x = x - 1;
        char dirtest;
        int backcount = 0;
        string dir;
        int num = 0;
        while (num < row * col - 1)
        {
            cin >> dirtest;
            dir = dir + dirtest;
            if (dirtest == 'F')
            {
                cin >> dirtest;
                back[backcount] = dirtest - '0';
                backcount++;
            }
            else
            {
                num++;
            }
        }
        int times = 0;
        for (int j = 0; j < dir.size(); j++)
        {
            if (dir[j] == 'U')
            {
                x++;
                maze[x][y] = ' ';
            }
            else if (dir[j] == 'R')
            {
                y++;
                maze[x][y] = ' ';
                y++;
            }
            else if (dir[j] == 'D')
            {
                maze[x][y] = ' ';
                x--;
            }
            else if (dir[j] == 'L')
            {
                y--;
                maze[x][y] = ' ';
                y--;
            }
            else if (dir[j] == 'F')
            {
                for (int k = 0; k < back[times]; k++)
                {
                    if (dir[j - k - 1] == 'U')
                    {
                        x--;
                    }
                    else if (dir[j - 1 - k] == 'R')
                    {
                        y = y - 2;
                    }
                    else if (dir[j - 1 - k] == 'D')
                    {
                        x++;
                    }
                    else if (dir[j - 1 - k] == 'L')
                    {
                        y = y + 2;
                    }
                }
                times++;
            }
        }

        for (int k = 0; k < 2 * col; k++)
        {
            cout << maze[row][k];
        }
        cout << endl;

        for (int j = row - 1; j >= 0; j--)
        {
            for (int k = 0; k <= 2 * col; k++)
            {
                cout << maze[j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}