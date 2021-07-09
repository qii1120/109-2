#include "Q38.cpp"
class DateTime : public Date
{
public:
    virtual string toString()
    {
        stringstream timee;
        timee << setw(2) << setfill('0') << getMonth() << ", " << setw(2) << setfill('0') << getDay() << ", " << getYear()<<" "<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second;
        return timee.str();
    } // "mm/dd/yyyy HH:MM:SS"
    DateTime() : Date()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    DateTime(int y, int m, int d, int hh=0, int mm=0, int ss=0) : Date(y, m, d)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }
    void setHour(int h){
        hour=h;
    }
    void setMinute(int m){
        minute=m;
    }
    void setSecond(int s){
        second=s;
    }
    int getHour() const{
        return hour;
    }
    int getMinute() const{
        return minute;
    }
    int getSecond() const{
        return  second;
    }
    void addHours(int h){
        hour=hour+h;
        while(hour>=24){
            setDay(getDay()+1);
            hour=hour-24;
        }
    }   // adds the specified number of hours to this instance
    void addMinutes(int m){
        minute=minute+m;
        while(minute>=60){
            addHours(1);
            minute=minute-60;
        }
    } // adds the specified number of minutes to this instance
    void addSeconds(int s){
        second=second+s;
        while(second>=60)
        {
            addMinutes(1);
            second=second-60;
        }
    } // adds the specified number of seconds to this instance
private:
    int hour, minute, second;
};
int main()
{
    int n;
    DateTime d(2021, 1, 1);
    cin >> n;
    d.addHours(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addMinutes(n);
    cout << d.toString() << endl;
    cin >> n;
    d.addSeconds(n);
    cout << d.toString() << endl;
    return 0;
}