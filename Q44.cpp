template<typename T>
class Set
{
  public:
    Set(){
      for(int i=0;i<100;i++){
        element[i]=0;
      }
      count=0;
    }
    Set(const Set &copy){
      count=copy.count;
      for(int i=0;i<100;i++){
        element[i]=copy.element[i];
      }
    }
  	void display()
    {
      for(int i = 0;i < count;i ++)
        std::cout<<element[i]<<" ";
    }
    int add(const T n){
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
            for(int j=0;j<this->count;j++){
                if(s.element[i]==this->element[j]){
                    break;
                }
                if(j==count-1){
                    this->element[count]=s.element[i];
                    count++;
                    num++;
                    break;
                }
            }
        }
        return num;
    }
    Set operator +(const Set &uni)const{
        Set temp= Set(*this);
        temp.add(uni);
        return temp;
    }
    Set operator-(const Set &inter)const{
        Set temp=Set ();
        for(int i=0;i<inter.count;i++){
            for(int j=0;j<this->count;j++){
                if(this->element[j]==inter.element[i]){
                    temp.element[temp.count]=this->element[j];
                    temp.count++;
                }
            }
        }
        return temp;
    }
  private:
  	T element[100];
  	int count;
};
