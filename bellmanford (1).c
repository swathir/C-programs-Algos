#include<stdio.h>
#include<conio.h>
#define infi 999

struct edges
{
    int w;

}  edge[10][10];

void bellman(int n,int s,struct edges edge[10][10],int dist[])
{
int i,j;

for(i=1;i<=n;i++)
dist[i]=infi;

dist[s]=0;

 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
    printf("\n%d ,%d %d",i,j,edge[i][j].w);
  }

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
    if(i==j)
    continue;

if(dist[j]>dist[i]+edge[i][j].w)
  dist[j]=dist[i]+edge[i][j].w;

}

}

void main()
{
int n,s,i,j,dist[10];

 printf("\n Enter the number of nodes : ");
 scanf("%d",&n);
 printf("\n Enter the weights of edges (0 if unconnected):\n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  {
      if (i==j)
       {
           edge[i][j].w=0;
           continue;
       }


      printf(" %d -> %d : ",i,j);

   scanf("%d",&edge[i][j].w);

   if(edge[i][j].w==0)
    edge[i][j].w=infi;

  }

 printf("\n Enter the source matrix : ");
 scanf("%d",&s);

 bellman(n,s,edge,dist);

 printf("\n Shortest path : \n");

 for(i=1;i<=n;i++)
{
  if(dist[i]==infi)
   {
       printf("\nnot possible");
       continue;
   }
  if(i!=s)
   printf(" %d->%d, edge = %d\n",s,i,dist[i]);
}
}
