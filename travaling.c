#include<stdio.h>

int costMatrix[10][10], n, visited[10], cost = 0;

void minimumCost(int);
int least(int);

int main(int argc, char const *argv[])
{
    int i, j;
    
 printf("Enter number of cities\n");
 scanf("%d",&n);
 
 printf("Enter cost adjacency matrix\n");
 for ( i = 0; i < n; i++) 
    for ( j = 0; j < n; j++)    
        scanf("%d", &costMatrix[i][j]);
    
    
 printf("Shortest path\n");
 minimumCost(0);
 printf("Minimum cost is %d\n", cost);
 
    return 0;
}

void minimumCost(int city){
    int nearest;
    visited[city]=1;
    printf("%d->", city);
    nearest = least(city);
      if (nearest == 999)
      {
          nearest =0;
          printf("%d",nearest);
          cost=cost+costMatrix[city][nearest];
          return;
      }    

}

int least(int c){
    int i; 
    for ( i = 0; i < n; i++)
    {
        if (costMatrix[c][i]!=0 && visited[i]==0 && costMatrix[c][i]<minimumCost)
        {
            
        }
        
    }
    
}
