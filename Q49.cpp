#include <iostream>
#include <string>
using namespace std;
int maxday(string mon){
    if(mon=="JAN"||mon=="MAR"||mon=="MAY"||mon=="JUL"||mon=="AUG"||mon=="OCT"||mon=="DEC"){
        return 31;
    }
    else if(mon=="FEB"){
        return 28;
    }
    else{
        return 30;
    }
}
int daytonum(string day){
    if(day=="MON"){
        return 1;
    }
    else if(day=="TUE"){
        return 2;
    }
    else if(day=="WED"){
        return 3;
    }
    else if(day=="THU"){
        return 4;
    }
    else if(day=="FRI"){
        return 5;
    }
    else if(day=="SAT"){
        return 6;
    }
    else{
        return 7;
    }
}
int main()
{
    int test,max,date,weekend;
    string mon,day;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>mon>>day;
        max=maxday(mon);
        date=daytonum(day);
        weekend=0;
        while (max>0)
        {
            if(date==5||date==6){
                max--;
                date++;
                weekend++;
            }
            else if(date==7){
                date=1;
                max--;
            }
            else{
                date++;
                max--;
            }
        }
        cout<<weekend<<endl;
    }
    
}