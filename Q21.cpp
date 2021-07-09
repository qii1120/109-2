#include<iostream>
#include<string>
using namespace std;
class Decode
{
    string str;
    public:
    Decode(string str2){
        str=str2;
    }
    string decode(){
        string result;
        for(int i=0;i<str.size()-2;i=i+3){
            result=result+char((str[i]-'0')*100+(str[i+1]-'0')*10+(str[i+2]-'0'));
        }
        return result;
    }
};
int main() {
  string str;
  cin>>str;
  Decode *code = new Decode(str);
  cout<<code->decode();
  return 0;
}
