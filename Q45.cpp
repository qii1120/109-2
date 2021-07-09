#include <iostream>
using namespace std;
int main()
{
    int size;
    cin >> size;
    while (size != 0)
    {
        int matrix[size][size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> matrix[i][j];
            }
        }
        int row[size] = {0}, col[size] = {0};
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                row[i] = row[i] + matrix[i][j];
                col[j] = col[j] + matrix[i][j];
            }
        }
        int change = 0, pos[2],co=0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (row[i] % 2 != 0 && col[j] % 2 != 0)
                {
                    change++;
                    pos[0] = i;//row
                    pos[1]=j;//col
                }
                else if ((row[i] % 2 == 0 && col[j] % 2 != 0) || (row[i] % 2 != 0 && col[j] % 2 == 0))
                {
                    co++;
                }
                if (i == size - 1&&j==size-1)
                {
                    if (change == 0&&co==0)
                    {
                        cout << "OK" << endl;
                    }
                    else if (change == 1)
                    {
                        cout <<"Change bit ("<<pos[0]+1<<","<<pos[1]+1<<")"<<endl;
                    }
                    else{
                        cout<<"Corrupt"<<endl;
                    }
                }
            }
        }
        cin >> size;
    }
    return 0;
}
