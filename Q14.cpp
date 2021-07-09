#include<iostream>
#include<ctype.h>
#include<math.h>
using namespace std;
class Point
{
  float x,y;
  public:
  Point(){
    x=0,y=0;
  }
  Point(float x1, float y1){
    x=x1,y=y1;
  }
  void printPoint(){
    cout<<"("<<x<<", "<<y<<")";
  }
  void setX(float x1){
    x=x1;
  }
  float getX(){
    return x;
  }
  void setY(float y1){
    y=y1;
  }
  float getY(){
    return y;
  }
  float getDistance(Point a){
    float deltax=a.getX()-this->getX();
    float deltay=a.getY()-this->getY();
    return sqrt(deltax*deltax+deltay*deltay);
  }
};
