#include <iostream>
#include <cmath>
using namespace std;
class Point
{
  float x,y;
  public:
  	float getX()const{
      return x;
    }
  	void setX(float X){
      x=X;
    }
 	float getY()const{
      return y;
    }
  	void setY(float Y){
      y=Y;
    }
  	Point(){
      x=0;
      y=0;
    }
  	Point(float a, float b){
      x=a;
      y=b;
    }
  	void printPoint(){
      cout<<"("<<x<<", "<<y<<")";
    }
    float getDistance(Point dis){
      float deltax=dis.x-x;
      float deltay=dis.y-y;
      return sqrt(deltax*deltax+deltay*deltay);
    }
};
class Segment
{
  public:
    Point point1,point2;
  	Segment(){
      point1.setX(0);
      point1.setY(0);
      point2.setX(0);
      point2.setY(0);
    }
 	Segment(Point test1,Point test2){
      point1.setX(test1.getX());
      point1.setY(test1.getY());
      point2.setX(test2.getX());
      point2.setY(test2.getY());
  }
  Segment(const Segment &s){
    this->point1.setX(s.point1.getX());
    this->point1.setY(s.point1.getY());
    this->point2.setX(s.point2.getX());
    this->point2.setY(s.point2.getY());
  }
    float getLength(){
      return this->point1.getDistance(this->point2);
    }
};
class Shape
{
public:
  Shape(){
    edgeCount=0;
  }
  Shape(Segment *lines, int edge){
    edgeCount=edge;
    for(int i=0;i<edge;i++){
      seg[i]=lines[i];
    }
  }
private:
  Segment seg[10];
  int edgeCount;
};
