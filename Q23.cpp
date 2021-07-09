#include<iostream>
using namespace std;
class Fraction
{
    int denominator,numerator;
    public:
    Fraction(){
        setNumerator(0);
        setDenominator(0);
    }
    Fraction(int n,int d){
        setNumerator(n);
        setDenominator(d);
    }
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }
    void setNumerator(int n){
        numerator=n;
    }
    void setDenominator(int d){
        denominator=d;
    }
    void display(){
        int frac=1;
        for(int i=2;i<=denominator;i++){
            if(numerator%i==0&&denominator%i==0){
                frac=i;
            }
        }
        numerator=numerator/frac;
        denominator=denominator/frac;
        if(denominator==1){
            cout<<"("<<numerator<<")";
        }
        else{
            cout<<"("<<numerator<<"/"<<denominator<<")";
        }
    }
    Fraction operator+(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.denominator);
        temp.setNumerator(this->numerator*a.denominator+this->denominator*a.numerator);
        return temp;
    }
    Fraction operator-(const Fraction &a)const{
        Fraction temp;
        temp.setDenominator(this->denominator*a.denominator);
        temp.setNumerator(this->numerator*a.denominator-this->denominator*a.numerator);
        return temp;
    }
    Fraction operator*(const Fraction &a)const{
        Fraction temp;
        temp.setNumerator(this->numerator*a.numerator);
        temp.setDenominator(this->denominator*a.denominator);
        return temp;
    }
    Fraction operator/(const Fraction &a)const{
        Fraction temp;
        temp.setNumerator(this->numerator*a.denominator);
        temp.setDenominator(this->denominator*a.numerator);
        return temp;
    }
    Fraction &operator=(const Fraction &a){
        this->setNumerator(a.numerator);
        this->setDenominator(a.denominator);
        return *this;        
    }
};
