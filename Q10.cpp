class bar3d
{
  public:
  	float width;
  	float height;
  	float depth;
  bar3d(float a,float b,float c) {
     if((a>0&&a<1000)&&(b>0&&b<1000)&&(c>0&&c<1000)){
       width=a;
       height=b;
       depth=c;
     }
     else{
       width=0;
       height=0;
       depth=0;
     }
   }
  bar3d();
  float getVolume(){
    	return width*height*depth;
  }
  void scale(float test);
};
bar3d::bar3d(){
  width=0;
  height=0;
  depth=0;
}
void bar3d::scale (float test){
    width=width*test;
    height=height*test;
    depth=depth*test;
  }
