#include<iostream>
using namespace std;
int main()
{
    int row,col,Case=1,times=0;
    cin>>row>>col;
    while(row!=0&&col!=0){
        char field[row+2][col+2];
        for(int i=0;i<row+2;i++){
            for(int j=0;j<col+2;j++){
                field[i][j]='.';
            }
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                cin>>field[i][j];
            }
        }
        char result[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                result[i][j]='0';
            }
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(field[i][j]=='*'){
                    result[i-1][j-1]='*';
                }
                else{
                    for(int k=-1;k<2;k++){
                        for(int q=-1;q<2;q++){
                            if(field[i+k][j+q]=='*'){
                                times++;
                            }
                        }
                    }
                    times=times+48;
                    result[i-1][j-1]=(char)times;
                }
                times=0;
            }
        }
        cout<<"Field #"<<Case<<":"<<endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<result[i][j];
            }
            cout<<endl;
        }
        Case++;
        cin>>row>>col;
        cout<<endl;
    }
    return 0;
}