#include<stdio.h>
int a[20], max,min;
void minmax(int i,int j) {
    int mid,min1,max1;
    if(i==j)
    {
        max=min=a[j];
    } else if(i==j-1) {
        if(a[i]>a[j])
        {
            max = a[i];
            max = a[j];

        }

        else
        {
            max = a[j];
            min = a[i];
        }
    }

    else
    {
        mid = (i+j)/2;
        minmax(i,mid);
        max1 = max;
        min1 = min;

        minmax(mid+1,j);

        if(max<max1)
            max=max1;

        if(min>min1)
            min=min1;


    }

}

int main(){
    int i,n;

    printf("enter size of array\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    minmax(1,n);

    printf("maximum value is %d",max);
    printf("minimum value is %d",min);
}

