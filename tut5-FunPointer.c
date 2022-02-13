// C program to illustrate the use of function pointer

#include<stdio.h>

int sum(int a,  int b){
   int sum = a + b;
   return sum;
}

int smallest(int a, int b){
    if(a<b)
        return a;
    else 
        return b;
}

int main(){
    int a,b,r;
    int  (*fun)();

     printf("Enter the values of a  and b\n");
        scanf("%d%d",&a,&b);
     
     r = sum(a,b);
       printf("Normal call to sum() function, sum = %d\n",r);

     fun = sum;
     r = fun(a,b);
     printf("Function call to sum() using pointer, sum= %d\n",r);

    r=smallest(a,b);
    printf("Normal call to smallest() function, smallest = %d\n",r);

    fun = smallest;
    r = fun(a,b);
    printf("Function call to smallest() using pointer, smallest = %d\n",r);

     return 0;
}