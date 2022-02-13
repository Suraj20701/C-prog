//  C program to swap two numbers using Call by value and Call by reference parameter passing techniques.

#include<stdio.h>
void callByValue(int,int);
void callByReference(int*,int*);

int main(){
    int a,b;
    printf("Enter the value of variable a and b\n");
    scanf("%d%d",&a,&b);
    printf("The value of a=%d and b=%d before function call\n",a,b);
    
    callByValue(a,b);
    printf("The value of a=%d and b=%d after function call callByValue()\n",a,b);

    callByReference(&a,&b);
    printf("The value of a=%d and b=%d after function call callByReference()\n",a,b);

    return 0;

}

void callByValue(int a,int b){
    int temp;
    temp =a;
    a=b;
    b=temp;
}

void callByReference(int *p1,int *p2){
    int temp;
    temp =*p1;
    *p1=*p2;
    *p2=temp;
}