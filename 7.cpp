#include<iostream>
#include<string>
using namespace std;

bool issushu(int n){
    bool flag=true;
    for(int j=3;j*j<=n;j++){
        if(n%j==0){
            flag=false;   //能整出，则false
        }
    }
    return flag;
}

int main(){
    unsigned int n;
    cin>>n;
    unsigned int i=7,count=1;
    if(n<5)
        cout<<'0';
    else{
        bool front,now;
        
        front=true; //3是素数
        now=true; //5是素数
        while(i<=n){
            front=now;
            now=issushu(i);
            if(now==true&&front==true){
                count++;
            }
            i=i+2;
        }
        cout<<count;
    }
    return 0;
}
