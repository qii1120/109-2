class bar3d
{
  public:
  	int width,height,depth;
  	bar3d(){
      width=0,height=0,depth=0;
    }
  	bar3d(int w,int h, int d){
      if(w>0&&h>0&&d>0&&w<1000&&h<1000&&d<1000){
        width=w,height=h,depth=d;
      }
      else{
        width=0,height=0,depth=0;
      }
    }
};
