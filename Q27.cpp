#include <iostream>
using namespace std;
int main(){
    int Case,i,X,Y;
    char dir;
    char lastdir;
    char bitmap[32][32];
    
    cin>>Case;
    for(i=0;i<Case;i++){
        for(int l=0;l<32;l++){
            for(int j=0;j<32;j++){
                bitmap[l][j]='.';
            }
        }
        cin>>X>>Y;
        X=X-1,Y=Y-1;
        cin>>dir;
        while(dir!='.'){
            if(dir=='E'){
                X=X+1;
                bitmap[Y][X]='X';
            }
            else if(dir=='N'){
                Y=Y+1;
                bitmap[Y][X+1]='X';
            }
            else if(dir=='W'){
                X=X-1;
                bitmap[Y+1][X+1]='X';
            }
            else if(dir=='S'){
                bitmap[Y][X]='X';
                Y--;
            }
            cin>>dir;
        }
        cout<<"Bitmap #"<<i+1<<endl;
        for(int j=31;j>=0;j--){
            for(int k=0;k<32;k++){
                cout<<bitmap[j][k];
            }
            cout<<endl;
        }
        cout << endl;      // this one
    }
    return 0;
}