#include <stdio.h>
#include <stdlib.h>

void main()
{
    int nodes, edges, i, j, src, dest;
    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &nodes, &edges);

    int graph[nodes + 1][nodes + 1];

    for (i = 0; i < nodes + 1; i++)
    {
        for (j = 0; j < nodes + 1; j++)
        {

            graph[i][j] = 0;
        }
    }

    printf("Enter %d edges:\n", edges);

    for (i = 0; i < edges; i++)
    {
        scanf("%d%d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // if its undirected graph
    }

    for (i = 1; i < nodes + 1; i++)
    {
        for (j = 1; j < nodes + 1; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}