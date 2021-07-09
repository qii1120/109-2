#include <iostream>
#include <math.h>
#include <stdexcept>
using namespace std;
class Point
{
private:
    float x;
    float y;

public:
    Point()
    {
        setX(0), setY(0);
    }
    Point(float a, float b)
    {
        setX(a), setY(b);
    }
    void printPoint()
    {
        cout << "(" << x << ", " << y << ")";
    }
    float getX()
    {
        return x;
    }
    void setX(float c)
    {
        x = c;
    }
    float getY()
    {
        return y;
    }
    void setY(float d)
    {
        y = d;
    }
    float getDistance(Point e)
    {
        float deltax = e.x - x;
        float deltay = e.y - y;
        return sqrt(deltax * deltax + deltay * deltay);
    }
};
class Segment
{
private:
    Point point1;
    Point point2;

public:
    Segment()
    {
        point1.setX(0), point1.setY(0);
        point2.setX(0), point2.setY(0);
    }
    Segment(Point p1, Point p2)
    {
        point1.setX(p1.getX()), point1.setY(p1.getY());
        point2.setX(p2.getX()), point2.setY(p2.getY());
    }
    float getLength()
    {
        return this->point1.getDistance(this->point2);
    }
    Point getp1()
    {
        return point1;
    }
    Point getp2()
    {
        return point2;
    }
    bool getIntersect(Segment s){
        float x1=this->point1.getX(),x2=this->point2.getX(),y1=this->point1.getY(),y2=this->point2.getY();//first line
        float x3=s.point1.getX(),x4=s.point2.getX(),y3=s.point1.getY(),y4=s.point2.getY();//second line
        float m1,m2;
        if(x1>x2){
            float temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        if(x3>x4){
            float temp=x3;
            x3=x4;
            x4=temp;
            temp=y3;
            y3=y4;
            y4=temp;
        }
        if((x2-x1)==0){
            m1=99999;
        }
        else{
            m1=(y2-y1)/(x2-x1);
        }
        if((x4-x3)==0){
            m2=99999;
        }
        else{
            m2=(y4-y3)/(x4-x3);
        }
        if((x3==x1&&y3==y1)||(x4==x1&&y4==y1)){
            return true;
        }
        else if((x3==x2&&y3==y2)||(x4==x2&&y4==y2)){
            return true;
        }
        else if(m1==0&&m2!=0&&x3>=x1&&x3<=x2&&y1>=y3&&y1<=y4){
            return true;
        }
        else if(m1!=0&&m2==0&&x1>=x3&&x1<=x4&&y3>=y1&&y3<=y2){
            return true;
        }
        else if(m1!=0&&m2!=0){
            if((m1*(x3-x1)+y1)<=0&&(m1*(x4-x1)+y1)>=0&&(m2*(x1-x3)+y3)<=0&&(m2*(x2-x3)+y3)>=0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};
class Shape
{
public:
    Shape()
    {
        edgeCount = 0;
    }
    Shape(Segment *lines, int edge)
    { // to construct a shape with a serial of segment. Throw an invalid_argument if the segment can not construct a close path.
        edgeCount = edge;
        for (int i = 0; i < edge; i++)
        {
            seg[i] = lines[i];
        }
        for (int i = 1; i < edge - 1; i++)
        {
            if ((lines[i].getp2().getX() != lines[i + 1].getp1().getX() && lines[i].getp2().getY() != lines[i + 1].getp1().getY()) && (lines[0].getp1().getX() != lines[edge - 1].getp2().getX() && lines[0].getp1().getY() != lines[edge - 1].getp2().getY()))
            {
                throw invalid_argument("intvaild");
            }
        }
    }
    virtual float getArea() = 0;
    float getPerimeter()
    {
        float sum = 0;
        for (int i = 0; i < edgeCount; i++)
        {
            sum = sum + seg[i].getLength();
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
class Square : public Shape
{
public:
    Square(Segment *seg) : Shape(seg, 4)
    {
    }
    float getArea()
    {
        return getSeg(0).getLength() * getSeg(0).getLength();
    }
};
class Rectangle : public Shape
{
public:
    Rectangle(Segment *seg)
    {
        for (int i = 0; i < edge; i++)
        {
            segg[i] = seg[i];
        }
        for (int i = 1; i < edge - 1; i++)
        {
            if ((seg[i].getp2().getX() != seg[i + 1].getp1().getX() && seg[i].getp2().getY() != seg[i + 1].getp1().getY()) && (seg[0].getp1().getX() != seg[edge - 1].getp2().getX() && seg[0].getp1().getY() != seg[edge - 1].getp2().getY()))
            {
                throw invalid_argument("intvaild");
                break;
            }
        }
    }
    float getArea()
    {
        return segg[0].getLength()*segg[1].getLength();
    }
    bool isCollision(const Rectangle rec){
        for(int i=0;i<this->edge;i++){
            for(int j=0;j<rec.edge;j++){
                if(this->segg[i].getIntersect(rec.segg[j])){
                    return true;
                }
            }
        }
        return false;
    }
private:
    Segment segg[10];
    int edge=4;
};
int main() {
  Point p1(0, 0), p2(10, 0), p3(10, 0), p4(10, 10), p5(10, 10), p6(0, 10), p7(0, 10), p8(0, 0);
  Point p9(5, 5), p10(15, 5), p11(15, 5), p12(15, 15), p13(15, 15), p14(5, 15), p15(5, 15), p16(5, 5);
  Segment s[4] = {Segment(p1, p2), Segment(p3, p4), Segment(p5, p6), Segment(p7, p8)};
  Segment s2[4] = {Segment(p9, p10), Segment(p11, p12), Segment(p13, p14), Segment(p15, p16)};
  Point p17(0, 0), p18(10, 0), p19(10, 0), p20(10, 10), p21(10, 10), p22(0, 10), p23(0, 10), p24(0, 0);
  Point p25(15, 15), p26(15, 20), p27(15, 20), p28(20, 20), p29(20, 20), p30(20, 15), p31(20, 15), p32(15, 15);
  Segment s3[4] = {Segment(p17, p18), Segment(p19, p20), Segment(p21, p22), Segment(p23, p24)};
  Segment s4[4] = {Segment(p25, p26), Segment(p27, p28), Segment(p29, p30), Segment(p31, p32)};
  Rectangle r1(s), r2(s2), r3(s3), r4(s4);
  cout<<r1.isCollision(Rectangle(s2))<<std::endl;
  cout<<r3.isCollision(Rectangle(s4))<<std::endl;
  return 0;
}
