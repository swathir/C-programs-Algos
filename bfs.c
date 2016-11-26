 #include<stdio.h>
 #include<conio.h>
 #include<malloc.h>

 #define max 10

 struct nodes
 {
   int vertex;
   struct nodes *next;
 };
 typedef struct nodes* node;

 typedef struct queue
 {
  int front,rear;
  int arr[max];
 };
 typedef struct stack
 {
  int top;
  int arr[max];
 };
 node getnode()
 {
  node p;
  p=(node)malloc(sizeof(struct nodes));
  p->next=NULL;
  return p;
 }

  int empty(struct stack *s)
  {
   if(s->top==-1)
   {
   return 1;
   }
   else
   return 0;
  }
  void push(struct stack *s,int x)
  {
  if(s->top==max-1)
  printf("\n Queue Overflow");
  else
  {
 s->top++;
 s->arr[s->top]=x;
  }
  }
  int pop(struct stack *s)
  {
  int x;
  if(empty(s))
   printf("\n Queue Underflow..!");
  else
  {
   x=s->arr[s->top];
   s->top--;
  }
  return x;
  }

  int qempty(struct queue *q)
  {
  if(q->front > q->rear)
  return 1;
  else
  return 0;
  }
  void insertq(struct queue *q,int x)
  {
  if(q->rear==max-1)
   printf("\n Queue Overflow..!");
  else
  {
  q->rear++;
  q->arr[q->rear]=x;
  }
  }
  int removeq(struct queue *q)
  {
   int x;
   if(qempty(q))
 printf("\n Queue Underflow..!");
   else
   {
   x=q->arr[q->front];
   q->front++;
   }
   return x;
  }

  void init(node head[],int n)
  {
  int v;
  for(v=1;v<=n;v++)
  head[v]=NULL;
  }
  void visit(int vis[],int n)
  {
  int i;
  for(i=1;i<=n;i++)
   vis[i]=0;
  }

    void create(node head[])
  {
  node adj;
  char ch='y';
  int i,v1,v2,v,c;
  node new1,p;
  printf("\n enter 0 for Directed 1 for undirected:\t");
  scanf("%d",&c);

  do
  {
  printf("\n Enter an edge:\t");
  scanf("%d%d",&v1,&v2);
  new1=getnode();
  new1->vertex=v2;
  p=head[v1];
  if(p==NULL)
  head[v1]=new1;
  else
  {
  while(p->next!=NULL)
   p=p->next;
   p->next=new1;
  }
  if(c==1)
  {
 new1=getnode();
 new1->vertex=v1;
 p=head[v2];
 if(p==NULL)
  head[v2]=new1;
 else
 {
   while(p->next!=NULL)
    p=p->next;
    p->next=new1;
 }
  }
  printf("\n Do You Want To Add More Edges In Graph(y/n):\t");
  ch=getche();
  }while(ch=='y'||ch=='Y');
  }

  void display(node head[],int n)
  {
  int v;
  node adj;
  printf("\n Adjancency List Is:\n");
  for(v=1;v<=n;v++)
  {
   printf("\n Head[%d]->",v);
   adj=head[v];
   while(adj!=NULL)
   {
  printf("%d  ",adj->vertex);
  adj=adj->next;
   }
   printf("\n");
  }
  }


  void BFS(node head[],int start,int vis[])
  {
  node adj;
  struct queue q;
  int v;
  q.front=0;
  q.rear=-1;
  vis[start]=1;
  printf("\n %d",start);
  insertq(&q,start);
  while(!qempty(&q))
  {
  v=removeq(&q);
  adj=head[v];
  while(adj!=NULL)
  {
 if(vis[adj->vertex]==0)
 {
   vis[adj->vertex]=1;
     insertq(&q,adj->vertex);

   printf("\t %d",adj->vertex);
 }
 adj=adj->next;
  }
  }
  }
  void main()
  {
  char c='y';
  int ch,start,n,vis[10];
  node head[10];

 printf("\n Enter The No. of Vertices:\t");
 scanf("%d",&n);
 init(head,n);
 create(head);

 display(head,n);

 printf("\n Enter source vertex: \t");
 scanf("%d",&start);
 visit(vis,n);
 BFS(head,start,vis);

}
