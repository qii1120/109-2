class Set
{
  public:
  	Set(){
      count=0;
      for(int i=0;i<100;i++){
        element[i]=0;
      }
    }
  	Set(const Set &s){
    	count=s.count;
    	for(int i=0;i<100;i++){
      	element[i]=s.element[i];
    	}
  	}
  	int add(const int n){
      int num=0;
      for(int i=0;i<=count;i++){
        if(n==element[i]){
          break;
        }
        if(i==count){
          element[i]=n;
          count++;
          num=1;
          break;
        }
      }
      return num;
    }
  	int add(const Set s){
      int num=0;
      for(int i=0;i<s.count;i++){
		for(int j=0;j<count;j++){
          if(s.element[i]==this->element[j]){
            break;
          }
          if(j==count-1){
            this->element[count]=s.element[i];
            this->count++;
            num++;
            break;
          }
        }
      }
      return num;
    }
  	Set operator+(const Set &s)const{
      Set temp=Set(*this);
      for(int i=0;i<s.count;i++){
		for(int j=0;j<this->count;j++){
          if(s.element[i]==this->element[j]){
            break;
          }
          if(j==count-1){
            temp.element[temp.count]=s.element[i];
            temp.count++;
            break;
          }
        }
      }
      return temp;
    }
  Set operator-(const Set &s){
    Set temp;
    for(int i=0;i<s.count;i++){
      for(int j=0;j<this->count;j++){
        if(s.element[i]==this->element[j]){
          temp.element[temp.count]=s.element[i];
          temp.count++;
          break;
        }
      }
    }
    return temp;
  }
  	void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        std::cout<<element[j]<<" ";
    }
  private:
  	int element[100];
  	int count;
};
