#include <stdbool.h>
#include <stdio.h>

#define V 6
#define MAXIMUM 99999

void DijkstraProcess(int graph[V][V], int Start);
int MinimumDistance(int CostOfThePath[], bool IsSelected[]);

int main()
{

    int graph[V][V] = { { 0, 700, 800, 0, 0, 9060},
        { 700, 0, 0, 50, 0, 0},
        { 800, 0, 0, 900, 0, 0 },
        { 0, 50, 900, 0, 80, 79},
        { 0, 0, 0, 80, 0, 0},
        { 9060, 0, 0, 79, 0, 0}

    };


    DijkstraProcess(graph, 0);

    return 0;
}


void DijkstraProcess(int graph[V][V], int Start)
{
    int CostOfThePath[V];
    int Predecessor[1000];

    bool IsSelected[V];
    for (int i = 0; i < V; i++)
    {
        CostOfThePath[i] = MAXIMUM;
        IsSelected[i] = false;
        Predecessor[i]=Start;
    }
    CostOfThePath[Start] = 0;


    for (int CountingCost = 0; CountingCost < V - 1; CountingCost++)
    {
        int u = MinimumDistance(CostOfThePath, IsSelected);
        IsSelected[u] = true;
        for (int v = 0; v < V; v++){
            if ((!IsSelected[v] && graph[u][v]) && (CostOfThePath[u] != MAXIMUM) && (CostOfThePath[u] + graph[u][v] < CostOfThePath[v]))
            {
                CostOfThePath[v] = CostOfThePath[u] + graph[u][v];
                Predecessor[v]=u;
            }
        }


    }
    int k;
    for (int i = 0; i < V; i++)
    {
        if(i!=Start)
        {
            printf("\nDistance of  destination vertex %d from source vertex 1 =%d\n",i+1,CostOfThePath[i]);
            printf("ShortestPath=%d",i+1);
            k=i;
            do
            {
                k=Predecessor[k];
                printf("<-%d",k+1);
            }
            while(k!=Start);
        }
    }
}

int MinimumDistance(int CostOfThePath[], bool IsSelected[])
{

    int min = MAXIMUM;
    int  Ind;//Index above vertex

    for (int p = 0; p < V; p++)
    {
        if ((IsSelected[p] == false) && (CostOfThePath[p] <= min))//Is the vertex selected as a part of the shortest path and the Path cost from source vertex to destination vertex
        {
            min = CostOfThePath[p];
            Ind = p;
        }
    }

    return Ind;
}


