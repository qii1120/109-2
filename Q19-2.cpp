#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Digit
{
    int digit;

public:
    Digit()
    {
        setDigit(0);
    }
    Digit(int d)
    {
        setDigit(d);
    }
    void setDigit(int d)
    {
        if (d > 0 && d < 10)
        {
            digit = d;
        }
        else
        {
            digit = 0;
        }
    }
    int getDigit()
    {
        return digit;
    }
};
class IntNumber
{
    Digit digit[10000];
    int len = 0;
    char sign = '0';

public:
    IntNumber()
    {
        digit[0].setDigit(0);
    }
    IntNumber(char *s)
    {
        if (isalpha(s[0]) || isalpha(s[1]))
        {
            digit[0].setDigit(0);
            len = 1;
        }
        else if (s[0] == '-' || s[0] == '+')
        {
            if (s[0] == '-')
            {
                sign = '-';
            }
            for (int i = 1; i < strlen(s); i++)
            {
                if (isalpha(s[i]))
                {
                    break;
                }
                digit[len] = s[i] - '0';
                len++;
            }
        }
        else
        {
            for (int i = 0; i < strlen(s); i++)
            {
                if (isalpha(s[i]))
                {
                    break;
                }
                digit[len] = s[i] - '0';
                len++;
            }
        }
    }
    void display()
    {
        if (sign == '-')
        {
            cout << "-";
        }
        while (digit[0].getDigit() == 0 && len != 1)
        {
            for (int i = 0; i < len - 1; i++)
            {
                digit[i].setDigit(digit[i + 1].getDigit());
            }
            len--;
        }
        for (int i = 0; i < len; i++)
        {
            cout << digit[i].getDigit();
        }
    }
    IntNumber *add(const IntNumber *list)const{
        IntNumber *result=new IntNumber;
        IntNumber *n1 = new IntNumber(*this);
        IntNumber *n2 = new IntNumber(*list);
        long long int a=0,b=0,c;
        for(int i=0;i<this->len;i++){
            a=a*10 + n1->digit[i].getDigit();
        }
        for(int i=0;i<list->len;i++){
            b=b*10 + n2->digit[i].getDigit();
        }
        if(this->sign=='-'){
            a=a*-1;
        }
        if(list->sign=='-'){
            b=b*-1;
        }
        c=a+b;
        if(c<0){
            result->sign='-';
            c=c*-1;
        }
        string ans=to_string(c);
        for(int i=0;i<ans.size();i++){
            result->digit[i].setDigit(ans[i]-'0');
        }
        result->len=ans.size();
        return result;
    }
};
int main()
{
  char num1[10000], num2[10000];
  cin>>num1>>num2;
  IntNumber *number1 = new IntNumber(num1);
  IntNumber *number2 = new IntNumber(num2);
  number1->display();
  cout<<endl;
  number2->display();
  cout<<endl;
  number1->add(number2)->display();
  cout<<endl;
  number2->add(number1)->display();
  return 0;
}
