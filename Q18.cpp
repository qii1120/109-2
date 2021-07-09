#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Digit{
    int digit;
    public:
    Digit(){
        setDigit(0);
    }
    Digit(int d){
        setDigit(d);
    }
    void setDigit(int d){
        if(d>0&&d<10){
            digit=d;
        }
        else{
            digit=0;
        }
    }
    int getDigit(){
        return digit;
    }
};
class IntNumber{
    Digit digit[10000];
    int len=0;
    char sign='0';
    public:
    IntNumber(){
        digit[0].setDigit(0);
    }
    IntNumber(char *s){
        if(isalpha(s[0])||(s[0]=='-'&&isalpha(s[1]))){
            digit[0].setDigit(0);
            len=1;
        }
        else if(s[0]=='-'||s[0]=='+'){
            if(s[0]=='-'){
                sign='-';
            }
            for(int i=1;i<strlen(s);i++){
                if(isalpha(s[i])){
                    break;
                }
                digit[len]=s[i]-'0';
                len++;
            }
        }
        else{
            for(int i=0;i<strlen(s);i++){
                if(isalpha(s[i])){
                    break;
                }
                digit[len]=s[i]-'0';
                len++;
            }
        }
    }
    void display(){
        if(sign=='-'){
            cout<<"-";
        }
        while(digit[0].getDigit()==0&&len!=1){
            for(int i=0;i<len-1;i++){
                digit[i].setDigit(digit[i+1].getDigit());
            }
            len--;
        }
        for(int i=0;i<len;i++){
            cout<<digit[i].getDigit();
        }
    }
};
int main()
{
  char num[10000];
  cin>>num;
  IntNumber *number = new IntNumber(num);
  number->display();
  return 0;
}
