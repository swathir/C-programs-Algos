#include <stdio.h>
#include <string.h>

#define max 100
#define min(a,b) (((a)<(b))?(a):(b))

typedef struct{
  int deg;
  int adj[max];
} Node;

Node alist[max];
char ART[max], val[max];
int id;

void addEdge(int x, int y){
  alist[x].adj[alist[x].deg++] = y;
  alist[y].adj[alist[y].deg++] = x;
}

void clrlst(){
  memset(alist, 0, sizeof(alist));
}

int vis(int x, int root){
  int i, y, m, res, child = 0;

  res = val[x] = ++id;
  for(i = 0; i < alist[x].deg; i++){
    y = alist[x].adj[i];
    if(!val[y]){
      if(root && ++child > 1) ART[x] = 1;
      m = vis(y, 0);
      res = min(res, m);
      if(m >= val[x] && !root) ART[x] = 1;
    } else {
      res = min(val[y], res);
    }
  }
  return res;
}

void articulate(int n){
  int i;

  memset(ART, 0, sizeof(ART));
  memset(val, 0, sizeof(val));
  for(id = i = 0; i < n; i++)
    if(!val[i]) vis(i, 1);
}

int main(){
  int i, n, m, x, y, ff;

  printf("\nEnter the number of vertices and edges:");
  while(scanf("%d %d", &n, &m) == 2){
    printf("Enter the edges:");
    for(i = 0; i < m; i++){
      scanf("%d %d", &x, &y);
      addEdge(x,y);
    }

    articulate(n);

    for(ff = i = 0; i < n; i++)
      if(ART[i]){
	printf("\nNode %d is an articulation point\n", i);
	ff = 1;
      }
    if(!ff) printf("\nNo articulation pts\n");
    clrlst();
  }
  return 0;
}
