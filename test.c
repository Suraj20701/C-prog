#include<stdio.h>

void cal(int n){
  int sum=0;
  int i;
  printf("function calld");
  for(i = 0; i < n; i++)
  {
         printf("%d%d",i,n/i);   
  }
  printf("%d", sum);
}

int main(int argc, char const *argv[])
{
    cal(5);
    return 0;
}
