#include<stdio.h>
int a[10][10], indegree[10], n;

void indegreeCal(){
   int i, j, sum;
    for(j=0; j<n; j++){
        sum=0;
        for(i=0; i<n; i++)
           sum=sum+a[i][j];        
        indegree[j]=sum;
    }
}

void topology(){
    int inStack[10], top=-1, topologySeq[10], k=0, i, topElement;
    indegreeCal();


    for(i=0; i<n; i++){
        if(indegree[i]==0)
            inStack[++top] = i;
    }

    while(top != -1){
        topElement = inStack[top--];
        topologySeq[k++]=topElement;

        for(i=0; i<n; i++)
             if(a[topElement][i]==0){
                inStack[++top]=i;

            if(a[topElement][i]==1)
                indegree[i]--;
             }
           
        
    }

    printf("Topological Sequence : \n");
    for(i=0; i<n; i++)
        printf("%d\t", topologySeq[i]);
    

}



int main(){
    int i, j;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the adjencency matrix : \n");
     for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    topology();

}