#include<cmath>
#include<string>
#include<stdexcept>
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
    for(int i=1;i<edge-1;i++){
      if((lines[i].point2.getX()!=lines[i+1].point1.getX()&&lines[i].point2.getY()!=lines[i+1].point1.getY())&&(lines[0].point1.getX()!=lines[edge-1].point2.getX()&&lines[0].point1.getY()!=lines[edge-1].point2.getY())){
        throw invalid_argument("intvaild");
        break;
      }
    }
  }
  virtual float getArea() = 0;
  float getPerimeter(){
      float sum=0;
      for(int i=0;i<edgeCount;i++){
        sum=sum+seg[i].getLength();
      }
      return sum;
    }
  Segment &getSeg(int index)
  {
  	return seg[index];
  }
private:
  Segment seg[10];
  int edgeCount;
};
class Rectangle : public Shape
{
public:
  Rectangle(Segment *seg){
  	for(int i=0;i<edge;i++){
      segg[i]=seg[i];
    }
    for(int i=1;i<edge-1;i++){
      if((seg[i].point2.getX()!=seg[i+1].point1.getX()&&seg[i].point2.getY()!=seg[i+1].point1.getY())&&(seg[0].point1.getX()!=seg[edge-1].point2.getX()&&seg[0].point1.getY()!=seg[edge-1].point2.getY())){
        throw invalid_argument("intvaild");
        break;
      }
    }
  }
  float getArea(){
  	return segg[0].getLength()*segg[1].getLength();
    }
private:
	int edge=4;
    Segment segg[10];
};
