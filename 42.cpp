#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char a[1001];
int d[129]={0};
int l;
int m=0;
int id=-1;

int main()
{
    //用gets()时记住头文件调用#include<string.h>
    cout<<"输入a"<<endl;
    gets(a);
    
    l = (int)strlen(a);
    
    for(int i=0; i<l; i++)
    {
        /*
         ascii码: A:65;Z:90;a:97;z:122;
         */
        
        if(a[i]>='A' && a[i]<='Z') //'A'可替换成65，下同理
        {
            a[i]+=32;
        }
        
        if(a[i]>='a' && a[i]<='z')
        {
            //d[a[i]-0]也对
            //d[a[i]-'0']不对
            d[a[i]]++;
        }
    }
    
    for(int i=96; i<=122; i++)
    {
        if(d[i]>m)
        {
            m=d[i];
            id=i;
        }
    }
    
    printf("%c %d",id,m);
    
    return 0;
}
