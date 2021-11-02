#include<stdio.h>
#include<stdlib.h>
#define INF 9999

struct edge{
    int u,v,w;
};

struct graph
{
    int vertices,edges;
    struct edge  *edge;
};

void bellmanford(struct graph * g, int source);
void display(int arr[], int size);
int main(void){
    int v,e,i;
    // create graph 
    struct graph * g = (struct graph *)malloc(sizeof(struct graph));
    printf("\n enter the total vertices and edges");
    scanf("%d %d",&v,&e);
    
    g->vertices=v;
    g->edges=e;
    g->edge=(struct edge *)malloc(g->edges* sizeof(struct edge));
    printf("\n enter edge u,v and weights...");
    for(i=0;i<e;i++)
    {
            scanf("%d %d %d",&g->edge[i].u,&g->edge[i].v,&g->edge[i].w);
    }
    bellmanford(g,0);

    return 0;   
}

void bellmanford(struct graph* g,int source){
    
    int i,j,u,v,w;
    int ve = g-> vertices; //no.of vertices(total)
    int ee = g-> edges; //total no.of edge
    int d[ve];
    int p[ve];
    // initialize distance and predessor array.

    for(i=0;i<ve;i++)
    {
       d[i] = INF;
       p[i] = 0;
    }
    d[source]=0;
    for(i=1;i<=ve;i++)  //relax edges
    {
        for(j=0;j<ee;j++)
        {
             u = g->edge[j].u;
             v = g->edge[j].v;
             w = g->edge[j].w;

             if(d[u]!=INF && d[v]>d[u]+w){
                        d[v]=d[u]+w;
                        p[v]=w;
             }
        }
    }

    for(i=0;i<ee;i++)       //checks for negative cycle
    {
        u = g->edge[i].u;
        v = g->edge[i].v;
        w = g->edge[i].w;
    
        if(d[u]!= INF && d[v]>d[u]+w)
        {
                printf("\n negatgive cycle...");
                return;
        }
    }
    
    printf("distance array.");
    display(d,ve);
    printf("predecessor array:");
    
    display(p,ve);

}

void display(int arr[], int size){

        int i;
        for(i=0;i<size;i++)
        {
            printf("\n %d",arr[i]);
        }
        printf("\n");

}
