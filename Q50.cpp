#include <iostream>
using namespace std;
int main()
{
    long long int test, days, start=1,end=1;
    while (cin >> days)
    {
        long long int day[days], max = 0, total = 0, min;
        for (int i = 0; i < days; i++)
        {
            cin >> day[i];
        }
        for (int i = 0; i < days; i++)
        {
            for(int j=i;j<days;j++){
                total=0;
                min=day[i];
                for(int k=i;k<=j;k++){
                    total=total+day[k];
                    if(day[k]<min){
                        min=day[k];
                    }
                }
                if(total*min>max){
                    max=total*min;
                    start=i+1;
                    end=j+1;
                }
            }
            
        }
        cout << max << endl;
        cout << start << " " << end << endl;
        cout<<endl;
    }
    return 0;
}