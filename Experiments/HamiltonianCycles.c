#include<stdio.h>
void displaycycl();
void nextvalue(int k);
int g[10][10],n,x[10],c=0;

//hamilton cycle algorithm

void hamiltonian(int k)
{
while(1)
{
nextvalue(k);
if(x[k]==0)
{
return;
}
if(k==n)
{
c=c+1;
displaycycl();
}
else
{
hamiltonian(k+1);
}
}
}

//nextvalue algorithm to determine kth visiting vertex

void nextvalue(int k)
{
int j;
while(1)
{
x[k] = (x[k]+1)%(n+1);
if(x[k]==0)
{
return;
}
if(g[x[k-1]][x[k]] != 0)
{
for(j=1;j<=k-1;j++)
{
if(x[j] == x[k])
{
break;
}
}
if(j==k)
{
if((k<n) || ((k==n) && (g[x[n]][x[1]] != 0 )))
{
return;
}
}
}
}
}

//function to display solutions

void displaycycl()
{
int i;
for(i=1;i<=n;i++)
printf("%d ",x[i]);
printf("%d ", x[1]);
printf("\n");
}

//main function

int main()
{
int i,j;
printf("\n enter the no of vertices...");
scanf("%d",&n);
printf("\n enter the graph info...");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&g[i][j]);
}
}
for(i=1;i<=n;i++)
x[i]=0;
x[1]=1;
printf("\n Hamiltonian cycles possible are....\n");
hamiltonian(2);
printf("total %d solutions",c);
if(c==0)
{
printf("\n solutions not possible");
}
return 0;
}

/* Output 1:
enter the no of vertices...4
enter the graph info�
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
Hamiltonian cycles possible are....
1 2 3 4 1
1 2 4 3 1
1 3 2 4 1
1 3 4 2 1
1 4 2 3 1
1 4 3 2 1
total 6 solutions
Output 2:
enter the no of vertices...5
enter the graph info�
0 1 1 0 0
1 0 1 0 0
1 1 0 1 1
0 0 1 0 1
0 0 1 1 0
Hamiltonian cycles possible are....
total 0 solutions
solutions not possible */
