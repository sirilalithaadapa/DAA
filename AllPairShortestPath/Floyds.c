#include<stdio.h>
#include<conio.h>

int main(int, int);

void floyds(int c[10],[10], int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    c[i][j]=0;
                else
                    c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
                    
}

int min(int a,int b){
    if(a<b)
        return a;
    else
        return b;
        
}

void main()
{
    int c[10][10],w,n,e,u,v,i,j;
    
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    
    printf("\n Enter the number of Edges:");
    scanf("%d",&e);
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            c[i][j]=999;
    }
    printf("\n Enter the Edges, weights for %d edges \n",e);
    
    for(i=1;i<=e;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        c[u][v]=w;
    }
    
    printf("\n Matrix of input data: \n");
    
    for(i=1;i<=n;i++)
    {
        for(j=-1;j<=n;j++)
            printf("%d\t", c[i][j]);
            printf("\n");
    }
    
    floyds(c,n);
    printf("\n cost matrix: \n");
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d \t", c[i][j]);
            printf("\n");
    }
    
    printf("\n Shortest path are : \n");
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i! = j)
                printf("\n Shortest path from %d to %d is %d", i,j,c[i][j]);
        }
        
        getch();
}
