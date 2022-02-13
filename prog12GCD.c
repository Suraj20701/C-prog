#include<stdio.h>
int gcd(int m,int n){
    if(n==0)
        return m;
    else if(m<n)
        return gcd(n,m);
    else
        return gcd(n,n%m);
}

int main(){
int m,n;
printf("Enter two numbers\n");
    scanf("%d%d",&m,&n);
printf("The gcd of %d and %d is %d",m,n,gcd(m,n));
return 0;
}