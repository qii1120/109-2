#include <iostream>
using namespace std;
int main()
{
    int nx = 1, nr = 1, Case = 1;
    int ds, df;
    while (nx != 0 || nr != 0)
    {
        int olds[1000], oldf[1000];
        int nows[1000], nowf[1000];
        int year, month, day, year2, month2, day2;
        cin >> nx >> nr;
        if (nx == 0 && nr == 0)
        {
            break;
        }
        cout << "Case " << Case << ":" << endl;
        Case++;
        for (int i = 0; i < nx; i++)
        {
            cin >> ds >> df;
            olds[i] = ds;
            oldf[i] = df;
        }
        for (int i = 0; i < nr; i++)
        {
            cin >> ds >> df;
            nows[i] = ds;
            nowf[i] = df;
        }
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nx; j++)
            {
                if (nows[i] <= oldf[j] && nows[i] >= olds[j] && nowf[i] > oldf[j])
                {
                    year = oldf[j] / 10000;
                    month = (oldf[j] % 10000) / 100;
                    day = (oldf[j] % 100);
                    if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
                    {
                        day++;
                        if (day == 30)
                        {
                            month++;
                            day = 1;
                        }
                    }
                    else
                    {
                        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
                        {
                            day = 1;
                            month = month + 1;
                            if (month == 13)
                            {
                                month = 1;
                                year++;
                            }
                        }
                    }
                    cout << month << "/" << day << "/" << year << " to " << (nowf[i] % 10000) / 100 << "/" << nowf[i] % 100 << "/" << nowf[i] / 10000 << endl;
                }
                else
                {
                    cout << "No additional quotes are required." << endl;
                }
            }
        }
        if (nx == 0)
        {
            int start = 0, end = 0;
            for (int i = 0; i < nr; i++)
            {
                if (i < nr - 1)
                {
                    year = nowf[i] / 10000;
                    month = (nowf[i] % 10000) / 100;
                    day = (nowf[i] % 100);
                    year2 = nows[i + 1] / 10000;
                    month2 = (nows[i + 1] % 10000) / 100;
                    day2 = (nows[i + 1] % 100);
                }
                else{
                    cout<<(nowf[i]%10000)/100<< "/" << (nowf[i] % 100) << "/" << nowf[i] / 10000 << endl;
                }
                if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2) //閏年
                {
                    day++;
                    if (day == 30)
                    {
                        month++;
                        day = 1;
                    }
                    if (month != month2 || day != day2 || year != year2)
                    {
                        cout << (nows[start] % 10000) / 100 << "/" << (nows[start] % 100) << "/" << nows[start] / 10000 << " to " << (nowf[end] % 10000) / 100 << "/" << (nowf[end] % 100) << "/" << nowf[end] / 10000<<endl;
                        start++;
                    }
                    else
                    {
                        end++;
                    }
                }
                else
                {
                    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31)
                    {
                        day = 1;
                        month = month + 1;
                        if (month == 13)
                        {
                            month = 1;
                            year++;
                        }
                    }
                    else if (month == 2 && day == 28)
                    {
                        day = 1;
                        month = 3;
                    }
                    else
                    {
                        day++;
                    }
                    if (month != month2 || day != day2 || year != year2)
                    {
                        cout << (nows[start] % 10000) / 100 << "/" << (nows[start] % 100) << "/" << nows[start] / 10000 << " to " << (nowf[end] % 10000) / 100 << "/" << (nowf[end] % 100) << "/" << nowf[end] / 10000;
                        start++;
                    }
                    else
                    {
                        end++;
                    }
                }
            }
        }
    }
    return 0;
}