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
};
