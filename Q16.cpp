#include<iostream>
#include<math.h>
using namespace std;
class Point{
    float x,y;
    public:
    Point(){
        setX(0);
        setY(0);
    }
    Point(float xx,float yy){
        setX(xx);
        setY(yy);
    }
    void printPoint(){
        cout<<"("<<getX()<<", "<<getY()<<")";
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void setX(float xx){
        x=xx;
    }
    void setY(float yy){
        y=yy;
    }
    float getDistance(Point p){
        float deltax,deltay;
        deltax=p.getX()-this->getX();
        deltay=p.getY()-this->getY();
        return sqrt(deltax*deltax+deltay*deltay);
    }
};
class Segment{
    Point p1,p2;
    public:
    Segment(){
        p1.setX(0),p1.setY(0),p2.setX(0),p2.setY(0);
    }
    Segment(Point a1,Point a2){
        p1.setX(a1.getX()),p1.setY(a1.getY()),p2.setX(a2.getX()),p2.setY(a2.getY());
    }
    float getLength(){
        float deltax,deltay;
        deltax=p2.getX()-p1.getX();
        deltay=p2.getY()-p1.getY();
        return sqrt(deltax*deltax+deltay*deltay);
    }
    Point *getIntersect(Segment s){
        Point *result=new Point();
        float x1=this->p1.getX(),x2=this->p2.getX(),y1=this->p1.getY(),y2=this->p2.getY();
        float x3=s.p1.getX(),x4=s.p2.getX(),y3=s.p1.getY(),y4=s.p2.getY();
        float m1,m2,inx,iny;
        if((x2-x1)==0){
            m1=99999;
        }
        else{
            m1=(y2-y1)/x2-x1;
        }
        if((x4-x3)==0){
            m2=99999;
        }
        else{
            m2=(y4-y3)/x4-x3;
        }
        if((x3==x1&&y3==y1)||(x4==x1&&y4==y1)){//p3==p1||p4==p1
            result->setX(x1);
            result->setY(y1);
            return result;
        }
        else if((x3==x2&&y3==y2)||(x4==x2&&y4==y2)){
            result->setX(x2);
            result->setY(y2);
            return result;
        }
        else if(m1==0&&m2!=0){//line1 is hor line2 isn't
            result->setX(x3);
            result->setY(y1);
            return result;
        }
        else if(m1!=0&&m2==0){
            result->setX(x1);
            result->setY(y3);
            return result;
        }
        else if(m1!=0&&m2!=0){
            if((m1*(x3-x1)+y1)<=0&&(m1*(x4-x1)+y1)>=0&&(m2*(x1-x3)+y3)<=0&&(m2*(x2-x3)+y3)>=0){
                inx=(y3-y1+m1*x1-m2*x3)/(m1-m2);
                iny=m1*(inx-x1)+y1;
                result->setX(inx);
                result->setY(iny);
                return result;
            }
          else{
            return NULL;
          }
        }
        else{
            return NULL;
        }
    }
};
