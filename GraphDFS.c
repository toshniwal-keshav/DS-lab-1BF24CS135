#include<stdio.h>
#include<conio.h>

void dfs(int n, int cost[10][10], int src, int visited[10]){
	int v;
	visited [src]=1;
    for(v=0;v<n;v++){
        if((cost[src][v]==1) && (visited[v]==0))
            dfs(n,cost,v,visited);
    }
}

void main(){
    int n,i,j,cost[10][10],visited[10],con;

    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d", &cost[i][j]);
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(n,cost, 0, visited);
    con=1;

    for(i=0;i<n;i++){
        if(visited[i]!= 1){
           con=0;
           break;
        }
    }
    if(con==1)  printf("Graph is connected\n");
    else    printf("Graph is not connected\n");
    getch();
}
