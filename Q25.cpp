#include <iostream>
using namespace std;
class Fraction
{
    int numerator, denominator;
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
        int fac=1;
        for(int i=2;i<=denominator;i++){
            if(numerator%i==0&&denominator%i==0){
                fac=i;
            }
        }
        numerator=numerator/fac;
        denominator=denominator/fac;
        if(denominator==1){
            cout<<"("<<numerator<<")";
        }
        else{
            cout<<"("<<numerator<<"/"<<denominator<<")";
        }
    }
    Fraction operator+(const Fraction &a)const{
        Fraction temp;
        temp.setNumerator(this->numerator*a.denominator+this->denominator*numerator);
        temp.setDenominator(this->denominator*a.denominator);
        return temp;
    }
    Fraction operator-(const Fraction &a)const{
        Fraction temp;
        temp.setNumerator(this->numerator*a.denominator-this->denominator*numerator);
        temp.setDenominator(this->denominator*a.denominator);
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
        this->setDenominator(a.denominator);
        this->setNumerator(a.numerator);
        return *this;
    }
    friend ostream &operator<<(ostream &out,Fraction temp){
        int fac=1;
        for(int i=2;i<=temp.denominator;i++){
            if(temp.numerator%i==0&&temp.denominator%i==0){
                fac=i;
            }
        }
        temp.numerator=temp.numerator/fac;
        temp.denominator=temp.denominator/fac;
        if(temp.denominator==1){
            out<<"("<<temp.numerator<<")";
        }
        else{
            out<<"("<<temp.numerator<<"/"<<temp.denominator<<")";
        }
        return out;
    }
    Fraction operator!(){
        return Fraction(denominator,numerator);
    }
};
