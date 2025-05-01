#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long power(int b,int n,int m){
    long ans=1;
    b=b%m;
    while(n>0){
        if(n%2==1){
            ans=(ans*b)%m;
            n--;
        }
        n%2==0;
        b=(b*b)%m;
        n=n/2;
    }
    return ans;
}
int main()
{
    int b,n,m;
    long power_value;
    printf("Enter Base:");
    if(scanf("%d",&b)!=1 || b<0){
        printf("Invalid base entered!");
        return 1;
    }
    printf("Enter exponential:");
    if(scanf("%d",&n)!=1 || n<0){
        printf("Invalid exponential entered!");
        return 1;
    }
    printf("Enter Base:");
    if(scanf("%d",&m)!=1 || m<0){
        printf("Invalid modulo entered!");
        return 1;
    }
    power_value=power(b,n,m);;
    printf("Result:%ld",power_value);
    
    
 
 

    return 0;
}
