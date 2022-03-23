//https://1drv.ms/p/s!Aj7X6suujg_4hEgWUlp_t66icfol?e=oHAgax

#include <stdio.h>
int n, m, v[10][20], p[10], w[10], sum = 0;
int max(int, int);
void knapsack();

void main()
{
    int i;    
    printf("Enter the number of object\n");
    scanf("%d", &n);
    printf("Enter the weights of the object\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the profits of the object\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the capacity of knapsack\n");
    scanf("%d", &m);
    knapsack();
    
}

void knapsack()
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (j < w[i])
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }

    printf("The profit table is\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    i = n;
    j = m;

    printf("The optimal set of weights is \n");

    while (i != 0 && j != 0)
    {
        if (v[i][j] != v[i - 1][j])
        {
            printf("x[%d]=1\t", i);
            sum = sum + p[i];
            j = j - w[i];
        }
        else
            printf("x[%d]=0\t", i);
        i = i - 1;
    }

    printf("\n Total profit=%d\n", sum);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

//     OUTPUT
        
// Enter the number of object
// 4
// Enter the weights of the object
// 2
// 1
// 3
// 2
// Enter the profits of the object
// 12
// 10
// 20
// 15
// Enter the capacity of knapsack
// 5
// The profit table is
// 0       0       0       0       0       0
// 0       0       12      12      12      12
// 0       10      12      22      22      22
// 0       10      12      22      30      32
// 0       10      15      25      30      37
// The optimal set ofweights is
// x[4]=1  x[3]=0  x[2]=1  x[1]=1
//  Total profit=37
