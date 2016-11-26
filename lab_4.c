#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
int info;
struct node* L;
};

void display(struct node* nw[][10], int n)
{
int i,j;
for(i=1;i<=n;i++)
  {
    for(j=1;j<=n+1;j++)
      printf("  %d ->",nw[i][j]->info);

  printf("\n");
  }

}

void dijkstra(int n,int s,struct node* nw[10][10],int d[])
{
 int i,u,c,w,f[10],min;
 for(i=1;i<=n;i++)
  f[i]=0,d[i]=nw[s][i+1]->info;
  for(i=1;i<=n;i++)
   printf("%d->%d,dist=%d\n",s,i,d[i]);

for(c=2;c<=n;c++)
 {
  min=99;
  for(w=1;w<=n;w++)
   if(d[w]<min && !f[w])
   {
          printf("\n%d dist=%d\n",w,d[w]);
    min=d[w],u=w;
   }
             printf("%d \n",u);
  f[u]=1;

  for(w=1;w<=n;w++)
  {
   if((d[u]+(nw[u][w+1]->info)<d[w]) && !f[w]&& u!=w)
     d[w]=d[u]+nw[u][w+1]->info;
         printf("\n%d sum=%d dist=%d\n",w,d[u]+nw[u][w+1]->info,d[w]);
  }
}
}


void main()
{
int n,i,num,dist[10],ch,j,s;
struct node* nw[10][10];

printf("Enter the no. of nodes ");
scanf("%d",&n);

for(i=1;i<=n;i++)
{
printf("Enter distance for each node ( 0 if not connected) for %d ",i);
nw[i][1]=(struct node*)malloc(sizeof(struct node));
nw[i][1]->L=NULL;
nw[i][1]->info=i;

for(j=2;j<=n+1;j++)
{
if(i==(j-1))
 {
     num=999;
     goto loop;
 }
 printf("%d  ",(j)-1);
scanf("%d",&num);
if(num==0)
num=999;

loop:
nw[i][j]=(struct node*)malloc(sizeof(struct node));
nw[i][j]->L=NULL;
nw[i][j]->info=num;

//printf("\nWould you like to continue ? 1/0 :");
//scanf("%d",&ch);
//if(ch==0)
//j1[i]=j;
}
}

 printf("\n Enter the source :");
 scanf("%d",&s);

display(nw,n);

dijkstra(n,s,nw,dist);
 printf("\n Shortest path:\n");
 for(i=1;i<=n;i++)
  if(i!=s)
   printf("%d->%d,dist=%d\n",s,i,dist[i]);
}
