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
};
