#include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], pr=0;

    int i,j,u;

    u=capacity;

    for(int i=0;i<n;i++)
        x[i]=0.0;

    for(int i=0;i<n;i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            x[i]=1.0;
            pr=pr+profit[i];
            u=u-weight[i];

        }

    }

    if(i>n)
        x[i] = u/weight[i];

    pr = pr+(x[i]+profit[i]);
    printf("Result array x is ");
    for(int i=0;i<n;i++)
        printf("%f/t",pr);
    printf("profit is ...%f",pr);
}

void main()
{
    float weight[20],profit[20],capacity;
    int n,i,j;
    float ratio[20], t;
    printf("%f Enter the capacity of knapsack...");
    scanf("%f",&capacity);
    printf("%d total no of objects...");
    scanf("%f",&n);
    printf("%f Enter weights and profits of each object");

    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&weight[i],&profit[i]);

    }
    for(int i=0;i<n;i++)
    {
        ratio[i]=profit[i]/weight[i];

    }
    for(int i=0; i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                t=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=t;

                t=weight[j];
                weight[j] = weight[i];
                weight[i] = t;
                t=profit[j];

                profit[j] = profit[i];

                profit[i] = t;
            }
        }
    }

    knapsack(n,weight,profit,capacity);
}


