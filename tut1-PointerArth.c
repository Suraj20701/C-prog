//  C program to illustrate the use of pointers in arithmetic operations.

#include<stdio.h>

int main(){
    int a[5] = {10,20,30,40,50},sub;
    int *p1,*p2;
  
    p1=a;
    printf("Pointer p1=%u\t value=%d\n",p1,*p1);
 
    ++p1;
    printf("Pointer p1=%u\t value=%d\n",p1,*p1);
   
    --p1;
    printf("Pointer p1=%u\t value=%d\n",p1,*p1);
   
    p1=p1+3;
    printf("   After adding integer 3 to p1\nPointer p1=%u\t value=%d\n",p1,*p1);
  
    p1=p1-2;    
    printf("   After substracting integer 2 from p1\nPointer p1=%u\t value=%d\n",p1,*p1);
   
    printf("Sustraction of two pointers\n");
    p1=a;
    p2=(a+4);
    printf("Pointer p1=%u\t value=%d\tPointer p2=%u\t value=%d\n",p1,*p1,p2,*p2);
    sub=p2-p1;
    printf("n=%d\n",sub);

    return 0;

}