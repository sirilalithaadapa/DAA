#include<stdio.h>
#include<math.h>

int x[30],count=0;

int place(int pos)

{
    int i;
    
    for(i=1;i<pos;i++)
    {
        if((x[i]==x[pos]|| (((x[i]-x[pos])==(i-pos)))))

            return 0;

    }
    return 1;
}

void printboard(int n)
{
    int i,j;
    count ++;
    printf("\n\n Solution %d:\n",count);

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        {
            if(x[i]=j)
                printf("Q%d \t",i);
            else
                printf("*/t");
        }
        printf("\n");
    }

}

void queen(int n){
    int k=1;
    x[k]=0;
    while(k!=0){
        x[k]=x[k]+1;
        while(x[k]<=n && !place(k))
            x[k]<=n;
        if(x[k]<=n)
        {
            if(k==n)
                printboard(n);
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
            k--;

    }

}

void main()
{
    int i,n;
    printf("enter the number of queens...");
    scanf("%d",&n);
    queen(n);
    printf("\n possible solutions...%d",count);

}
