#include<stdio.h>
#include<malloc.h>
int findMin(int *visited,int *temp,int index,int *to, int *f, int *weight,int length)
{
int i=0,cost=0,t=0;
while(i<length)
{
if(visited[index]==to[i])
{
cost=weight[i];
t=i;
break;
}
i++;
}
while(i<length)
{
if(visited[index]==to[i])
{
if(cost>weight[i])
{
cost=weight[i];
t=i;
}
}
i++;
}
return t;
}
int minCost(int g_nodes,int g_edges,int *g_from, int *g_to,int *g_weight,int start,int end, int w_extra)
{
int visited[g_nodes],temp[g_nodes],weightAssigned[g_nodes];
int i,j,k,t,l;
weightAssigned[start-1]=0;
i=0;
while(i<g_nodes)
{
if(i!=start-1) weightAssigned[i]=54321;
i++;
}
visited[0]=start;
i=0;
while(i<g_nodes)
{
j=0;
k=0;
while(j<g_nodes)
{
if(g_to[j]==visited[i])
{
temp[k]=g_from[j];
weightAssigned[g_from[j]-1]=g_weight[j]+weightAssigned[visited[i]-1];
k++;
}
j++;
}
t=findMin(visited,temp,i,g_to,g_from,g_weight,k);
l=0;
while(l<k)
{
temp[l]=0;
l++;
}
visited[i+1]=t;
i++;
}
return weightAssigned[end-1];
}
int main()
{
int nodes,edges,to[edges],from[edges],weight[edges],weightExtra,start,end;
int i;
scanf("%d %d",&nodes,&edges);
i=0;
while(i<edges)
{
scanf("%d %d %d",&to[i],&from[i],&weight[i]);
i++;
}
scanf("%d",&start);
scanf("%d",&end);
scanf("%d",&weightExtra);
printf("Cost : %d",minCost(nodes,edges,from,to,weight,start,end,weightExtra));
return 0;
}
