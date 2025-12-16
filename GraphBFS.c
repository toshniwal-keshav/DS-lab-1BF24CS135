#include<stdio.h>
#include<conio.h>
void bfs(int a[20][20], int n, int src, int s[])
{
    int f,r,q[20],u,v,k=0,i;
    for(i=0;i<n;i++)
        s[i]=-1;
    f=r=0;
    q[r]=src;
    s[src]=src;
    while(f<=r)
    {
        u=q[f++];
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1 && s[v]==-1)
            {
                s[v]=u;
                q[++r]=v;
            }
        }
    }
}
void main()
{
    int n,a[20][20],src,s[20],i,j;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d", &a[i][j]);
    }
    printf("Enter the source\n");
    scanf("%d", &src);
    bfs(a,n,src,s);

    for(i=0;i<n;i++)
    {
        if(s[i]==-1)
        {
            printf("Vertex %d is not reachable\n", i);
        }
        else{
            printf("Vertex %d is reachable\t Path:", i);
            printf("%d to %d\n",s[i], i);
        }
    }

    getch();
}

