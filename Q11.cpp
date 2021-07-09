class bar3d
{
  public:
  float width,height,depth;
  bar3d(){
    width=height=depth=0;
  }
  bar3d(float w, float h, float d){
    if(w<1000&&w>0&&h<1000&&h>0&&d<1000&&d>0){
      width=w,height=h,depth=d;
    }
    else{
      width=depth=height=0;
    }
  }
  float getVolume(){
    return width*height*depth;
  }
  void scale(float s){
    width=s*width,height=height*s,depth=depth*s;
  }
  float addVolume(bar3d b){
    return getVolume()+b.getVolume();
  }
