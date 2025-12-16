#include<stdio.h>
#include<conio.h>
void bfs(int a[20][20], int n, int src, int des[])
{
    int ft,r,q[20],pr_src,pr_des,k=0,i;
    for(i=0;i<n;i++)
        des[i]=-1;
    f=r=0;
    q[r]=src;
    des[src]=src;
    while(ft<=r)
    {
        pr_src=q[ft++];
        for(pr_des=0;pr_des<n;pr_des++)
        {
            if(a[pr_src][pr_des]==1 && des[pr_des]==-1)
            {
                des[pr_des]=pr_src;
                q[++r]=pr_des;
            }
        }
    }
}
void main()
{
    int n,a[20][20],src,des[20],i,j;
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
    bfs(a,n,src,des);

    for(i=0;i<n;i++)
    {
        if(des[i]==-1)
        {
            printf("Vertex %d is not reachable\n", i);
        }
        else{
            printf("Vertex %d is reachable\t Path:", i);
            printf("%d to %d\n",des[i], i);
        }
    }

    getch();
}



