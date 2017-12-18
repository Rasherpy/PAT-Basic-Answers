//
//  8.cpp
//  oj
//
//  Created by Rasherpy on 2017/12/14.
//  Copyright © 2017年 Rasherpy. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[105];
int n,m,i;
int main()
{
    
    while(scanf("%d%d",&n,&m)==2)
        
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int r=m%n;
        if(r==0)
        {
            for(i=0;i<n;i++)
            {
                if(i==0)
                {
                    printf("%d",a[i]);
                }
                else
                    printf(" %d",a[i]);
            }
            printf("\n");
            continue;
        }
        int start=n-r;
        int end=n-r-1;
        for(i=start;i<n;i++)
        {
            if(i==start)
            {
                printf("%d",a[i]);
            }
            else
                printf(" %d",a[i]);
        }
        if(end>=0)
        {
            for(i=0;i<=end;i++)
            {
                printf(" %d",a[i]);
            }
        }
        printf("\n");
    }
}
