#include <iostream>
#include <string.h>
using namespace std;
int size,b=0;
void print(int map[9][9])
{
    for (int i = 0; i < size * size; i++)
    {
        for (int j = 0; j < size * size; j++)
        {
            if(j==size*size-1){
                cout<<map[i][j]<<" ";
            }
            else{
                cout << map[i][j] << " ";
            }
        }
        cout << endl;
    }
    b=1;
}
int check(int map[9][9], int row, int col)
{
    int temp[10];
    int i, j;
    memset(temp, 0, sizeof(temp));
    for (i = 0; i < size * size; i++)
    {
        if (map[i][col] != 0)
        {
            if (temp[map[i][col]] != 0)
            {
                return 0;
            }
            temp[map[i][col]] = 1;
        }
    }
    memset(temp, 0, sizeof(temp));
    for (i = 0; i < size * size; i++)
    {
        if (map[row][i] != 0)
        {
            if (temp[map[row][i]] != 0)
            {
                return 0;
            }
            temp[map[row][i]] = 1;
        }
    }
    memset(temp, 0, sizeof(temp));
    for (i = (row / size) * size; i < (row / size) * size + size; i++)
    {
        for (j = (col / size) * size; j < (col / size) * size + size; j++)
        {
            if (map[i][j] != 0)
            {
                if (temp[map[i][j]] != 0)
                {
                    return 0;
                }
                temp[map[i][j]] = 1;
            }
        }
    }
    return 1;
}
int solution(int map[9][9])
{
    int i, j, k;
    for (i = 0; i < size * size; i++)
    {
        for (j = 0; j < size * size; j++)
        {
            if (map[i][j] == 0)
            {
                break;
            }
        }
        if (j < size * size)
        {
            break;
        }
    }
    if (i == size*size)
    {
        print(map);
        return 1;
    }
    for (k = 1; k <= size * size; k++)
    {
        map[i][j] = k;
        if (check(map, i, j) == 1)
        {
            if (solution(map) == 1)
            {
                return 1;
            }
        }
        map[i][j] = 0;
    }
    return 0;
}
int main()
{
    while (cin >> size)
    {
        int map[9][9];
        for (int i = 0; i < size * size; i++)
        {
            for (int j = 0; j < size * size; j++)
            {
                cin >> map[i][j];
            }
        }
        solution(map);
        if(!b){
            cout<<"NO SOLUTION"<<endl;
        }
        cout<<endl;
        b=0;
    }
    return 0;
}