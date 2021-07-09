#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
    int emp;
    cin >> emp;
    int n[emp], set[emp][15];
    for (int i = 0; i < emp; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            set[i][j] = -1;
        }
    }
    for (int i = 0; i < emp; i++)
    {
        cin >> n[i];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> set[i][j];
        }
    }
    int t, test, know[emp], day = 0, max = 0, count = emp, peo[emp], last = 0, temp,maxday;
    int total;
    queue<int> q;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> test;
        day=0;
        for(int j=0;j<emp;j++){
            know[j]=123;
        }
        if (n[test] == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            q.push(test);
            last = 1;
            count = emp;
            know[emp - 1] = test;
            count--;
            max=0;
            while (!q.empty())
            {
                total = 0;
                //cout << last << "???" << endl;
                for (int z = 0; z < last; z++)
                {
                    
                    for (int j = 0; j < n[q.front()]; j++)
                    {
                        for (int k = 0; k < emp; k++)
                        {
                            //cout<<set[q.front()][j]<<" "<<know[k]<<"!!!"<<endl;
                            if (set[q.front()][j] == know[k])
                            {
                                //cout<<set[q.front()][j]<<"break"<<endl;
                                break;
                            }
                            if (k == emp - 1)
                            {
                                know[count - 1] = set[q.front()][j];
                                count--;
                                //cout<<set[q.front()][j]<<"#"<<endl;
                                q.push(set[q.front()][j]);
                                //cout<<q.back()<<"back"<<endl;
                                total = total + 1;
                                temp++;
                            }
                        }
                    }
                    //cout << q.front() << "?" << endl;
                    q.pop();
                }
                day++;
                last = temp;
                temp = 0;
                if(last==0){
                    break;
                }
                if (total > max)
                {
                    max = total;
                    maxday=day;
                }
            }
            cout << max<<" "<<maxday<<endl;
        }
    }
    return 0;
}