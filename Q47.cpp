#include <iostream>
using namespace std;
int day[100] = {0}, know[100], count;
int find(int arr[100][15], int index, int num, int employ)
{
    //cout<<num<<"?"<<endl;
    int max = 0;
    for (int j = 0; j < num; j++)
    {
        for (int k = 0; k < employ; k++)
        {
            //cout << count << "::" << endl;
            if (arr[index][j] == know[k])
            {
                break;
            }
            if (k == employ - 1)
            {
                know[count - 1] = arr[index][j];
                //cout<<"?"<<count<<" "<<know[count-1]<<" "<<index<<" "<<endl;
                count--;
                max++;
            }
        }
    }
    return max;
}
int main()
{
    int emp;
    cin >> emp;
    int set[100][15] = {0}, max = 0, n[emp];
    for (int i = 0; i < emp; i++)
    {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> set[i][j];
        }
    }
    int t, test, max2 = 0, temp[100],now=0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> test;
        temp[0]=test;
        if (n[test] == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            for (int i = 0; i < emp; i++)
            {
                know[i] = 1000;
            }
            know[emp - 1] = test;
            count = emp - 1;
            day[test]++;
            max = find(set, test, n[test], emp);
            while(){
            for (int k = 0; k < ; k++)
            {
                max2 = 0;
                for (int j = 0; j < n[temp[now]]; j++)
                {
                    //cout<<n[set[test2][j]]<<" "<<set[test2][j]<<endl;
                    max2 = max2 + find(set, set[temp[now]][j], n[set[temp[now]][j]], emp);
                }
                temp[now+1]=set[temp[now]][k];
                now++;
                //cout<<"max"<<max<<"vs"<<max2;
                if (max2 > max)
                {
                    max = max2;
                }
                else
                {
                    day[test]--;
                }
                //cout<<"!"<<n[test2]<<"max"<<max<<"count"<<count<<endl;
            }
            day[test]++;
            cout << max << " " << day[test] << endl;
            }
        }
    }
    return 0;
}