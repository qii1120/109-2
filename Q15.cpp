#include <cmath>
class Point
{
  float x,y;
  public:
  	float getX(){
      return x;
    }
  	void setX(float X){
      x=X;
    }
 	float getY(){
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
  Point point1,point2;
  public:
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
    float getLength(){
      //float deltax=point1.getX()-point2.getX();
      //float deltay=point1.getY()-point2.getY();
      //return sqrt(pow(deltax,2)+pow(deltay,2));
      return this->point1.getDistance(this->point2);
    }
};
