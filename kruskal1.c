#include<stdio.h>
#define m 10
int cost[m][m],parent[m];

int find(int i)
{
 while(parent[i]!=i)
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j){
  parent[j]=i;
  return 1;
 }
 return 0;
}

void main()
{
 int i,j,u1,v1,u,v,edge=1,c,mincost=0,n;
 printf("Enter the number of vertices : ");
 scanf("%d",&n);
 printf("Enter the cost adjacency matrix : ");
 for(i=1;i<=n;++i)
 {
  parent[i]=i;
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
    cost[i][j]=9999;
  }
 }
 while(edge<n)
 {
  c=9999;
  for(i=1;i<=n;++i)
   for(j=1;j<=n;j++)
    if(cost[i][j]<c)
    {
     c=cost[i][j];
     u1=i;
     v1=j;
    }
  u=find(u1);
  v=find(v1);
  if(uni(u,v))
  {
   printf("\nEdge %d  :  %d---%d    cost=%d",edge,u1,v1,c);
   edge++;
   mincost+=c;
  }
  cost[u1][v1]=cost[v1][u1]=9999;
  
 }
 printf("Total cost = %d",mincost); 
}