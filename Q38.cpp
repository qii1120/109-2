#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString(){// "mm, dd, yyyy"
    stringstream datee;
    datee<<setw(2)<<setfill('0')<<month<<", "<<setw(2)<<setfill('0')<<day<<", "<<year;
    return datee.str();
  } 
  void setDay(int d){
    day=d;
  }
  void setMonth(int m){
    month=m;
  }
  void setYear(int y){
    year=y;
  }
  int getDay() const{
      return day;
  }
  int getMonth() const{
      return month;
  }
  int getYear() const{
      return year;
  }
  int maxday(int m){
      if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
          return 31;
      }
      else if(m==2&&((year%4==0&&year%100!=0)||(year%400==0))){
          return 29;
      }
      else if(m==2){
          return 28;;
      }
      else{
          return 30;
      }
  }
  void addDays(int d){// adds the specified number of days to this instance
    day=day+d;
    while(day>maxday(month)){
        day=day-maxday(month);
        addMonths(1);
    }
  } 
  void addMonths(int m){
      month=month+m;
      while(month>12){
          month=month-12;
          addYears(1);
      }
  } // adds the specified number of months to this instance
  void addYears(int y){
      year=year+y;
  } // adds the specified number of years to this instance
  static bool isLeapYear(const Date &d){
      if((d.getYear()%4==0&&d.getYear()%100!=0)||(d.getYear()%400==0)){
          return true;
      }
      else{
          return false;
      }
  }
private:
  int year, month, day;
};