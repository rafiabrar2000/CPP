#include <stdio.h>
#include <stdlib.h>

#define V 5
#define MAXIMUM 99999

void BellmanFordProcess(int graph[V][V],int Start);

int main() {

    int graph[V][V] = { { 0, -1, 4, 0, 0},
        { 0, 0, 3, 2, 2},
        { 0, 0, 0, 0, 0 },
        { 0, 1, 5, 0, 0},
        { 0, 0, 0, -3, 0},
    };

    BellmanFordProcess(graph,0);

    return 0;
}

void BellmanFordProcess(int graph[V][V],int Start) {
    int Distance[1000];
    int Predecessor[1000];
    int i, j, k;

    for (i = 0; i < V; i++) {
        Distance[i] = MAXIMUM;
        Predecessor[i]=Start;
    }
    Distance[Start] = 0;
    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < V; j++) {
            for (k = 0; k < V; k++) {
                if (graph[j][k] != 0 && Distance[j] != MAXIMUM && Distance[j] + graph[j][k] < Distance[k]) {
                    Distance[k] = Distance[j] + graph[j][k];
                    Predecessor[k]=j;
                }
            }
        }
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if ((graph[i][j] != 0) && (Distance[i] != MAXIMUM) && (Distance[i] + graph[i][j] < Distance[j])) {
                printf("Negative Cycle Detected\n");
                return 0;
            }
        }
    }
    int l;
    for (int i = 0; i < V; i++)
    {
        if(i!=Start)
        {
            printf("\nDistance of  destination vertex %d from source vertex 1:%d\n",i+1,Distance[i]);
            printf("ShortestPath=%d",i+1);
            l=i;
            do
            {
                l=Predecessor[l];
                printf("<---%d",l+1);
            }
            while(l!=Start);
        }
    }
}



