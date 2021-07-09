#include <iostream>
#include <iomanip>
#include <ctype.h>
using namespace std;
class Digit
{
    int digit;

public:
    Digit()
    {
        setDigit(0);
    }
    Digit(int test)
    {
        setDigit(test);
    }
    void setDigit(int num)
    {
        if (num >= 0 && num < 10)
        {
            digit = num;
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
    Digit num[10000];
    char sign = '0';
    int len = 0;
    bool big = true;

public:
    IntNumber()
    {
        num[0].setDigit(0);
    }
    IntNumber(char *str)
    {
        int i = 0;
        if (isalpha(str[0]) || isalpha(str[1]))
        {
            num[0].setDigit(0);
            len = 1;
        }
        while (str[i] == '-' || str[i] == '+' || isdigit(str[i]))
        {
            if (str[i] == '-' && !isalpha(str[i + 1]))
            {
                sign = '-';
            }
            else if (isdigit(str[i]))
            {
                num[len].setDigit(str[i] - '0');
                len++;
            }
            i++;
        }
    }
    void display()
    {
        while (num[0].getDigit() == 0 && len != 1)
        {
            for (int j = 0; j < len - 1; j++)
            {
                num[j].setDigit(num[j + 1].getDigit());
            }
            len--;
        }
        if (sign == '-' && num[0].getDigit() != 0)
        {
            cout << "-";
        }
        for (int j = 0; j < len; j++)
        {
            cout << num[j].getDigit();
        }
    }
    void reverse(IntNumber *arr, int length)
    {
        for (int j = 0; j < length / 2; j++)
        {
            int temp = this->num[j].getDigit();
            this->num[j].setDigit(this->num[length - j - 1].getDigit());
            this->num[length - j - 1].setDigit(temp);
        }
    }
    void bigger(IntNumber *arr)
    {
        for (int j = this->len - 1; j >= 0; j--)
        {
            if (arr->num[j].getDigit() > this->num[j].getDigit())
            {
                big = false;
                break;
            }
        }
    }
    IntNumber *add(const IntNumber *num2) const
    {
        IntNumber *result = new IntNumber(*this);
        IntNumber *n1 = new IntNumber(*this);
        IntNumber *n2 = new IntNumber(*num2);
        n1->reverse(n1, n1->len);
        n2->reverse(n2, n2->len);
        int temp = 0;
        if ((n2->len) > (n1->len))
        {
            return num2->add(this);
        }
        if ((n1->sign == '-' && n2->sign == '-') || (n1->sign == '0' && n2->sign == '0'))
        {
            for (int i = 0; i < n1->len; i++)
            {
                if (temp == 0)
                {
                    if ((n1->num[i].getDigit() + n2->num[i].getDigit()) < 10)
                    {
                        result->num[i].setDigit(n1->num[i].getDigit() + n2->num[i].getDigit());
                    }
                    else
                    {
                        result->num[i].setDigit(n1->num[i].getDigit() + n2->num[i].getDigit() - 10);
                        temp = 1;
                    }
                }
                else
                {
                    if ((n1->num[i].getDigit() + n2->num[i].getDigit() + temp) >= 10)
                    {
                        result->num[i].setDigit(n1->num[i].getDigit() + n2->num[i].getDigit() + temp - 10);
                    }
                    else
                    {
                        result->num[i].setDigit(n1->num[i].getDigit() + n2->num[i].getDigit() + temp);
                        temp = 0;
                    }
                }
                if(i==n1->len-1&&temp==1){
                    result->len++;
                    n1->len++;
                }
            }
        }
        else
        {
            n1->bigger(n2);
            if (n1->big)
            {
                if(n1->sign=='-'){
                    result->sign='-';
                }
                for (int i = 0; i < n1->len; i++)
                {
                    if (temp == 0)
                    {
                        if ((n1->num[i].getDigit() - n2->num[i].getDigit()) >= 0)
                        {
                            result->num[i].setDigit(n1->num[i].getDigit() - n2->num[i].getDigit());
                        }
                        else
                        {
                            result->num[i].setDigit(n1->num[i].getDigit() - n2->num[i].getDigit() + 10);
                            temp = 1;
                        }
                    }
                    else
                    {
                        if ((n1->num[i].getDigit() - n2->num[i].getDigit() - temp) >= 0)
                        {
                            result->num[i].setDigit(n1->num[i].getDigit() - n2->num[i].getDigit() - temp);
                            temp = 0;
                        }
                        else
                        {
                            result->num[i].setDigit(n1->num[i].getDigit() - n2->num[i].getDigit() - temp + 10);
                        }
                    }
                }
            }
            else{
                return num2->add(this);
            }
        }
        result->reverse(result, result->len);
        return result;
    }
};
int main()
{
    char num1[10000], num2[10000];
    cin >> num1 >> num2;
    IntNumber *number1 = new IntNumber(num1);
    IntNumber *number2 = new IntNumber(num2);
    number1->display();
    cout << endl;
    number2->display();
    cout << endl;
    number1->add(number2)->display();
    cout << endl;
    number2->add(number1)->display();
    return 0;
}