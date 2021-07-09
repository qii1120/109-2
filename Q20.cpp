#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
class Encode
{
    string str;
    public:
    Encode(string str2){
        str=str2;
    }
    string encode(){
        stringstream result;
        for(int i=0;i<str.size();i++){
            result<<setw(3)<<setfill('0')<<(int)str[i];
        }
        return result.str();
    }
};
int main() {
  string str;
  getline(cin, str);
  Encode *code = new Encode(str);
  cout<<code->encode();
  return 0;
}
