#include<stdio.h>
#include<stdlib.h>

int A;

void RAS(int s[][2], int f[][2], int i)
{
  int m,c,d,t;


      for (c = 0 ; c < A ; c++)
  {
    d = c;

    while ( d > 0 && f[d][1] < f[d-1][1]) {
      t= f[d][1];
      f[d][1]= f[d-1][1];
      f[d-1][1] = t;
      t= f[d][0];
      f[d][0]= f[d-1][0];
      f[d-1][0] = t;


      d--;
    }
  }

  m=i+1;

  while( m<=A && s[m][1]< f[i][1])
      m+=1;

    if(m<=A)
     {
         s[m][0]=1;
         RAS(s,f,m);
     }
    else return;
}

void main()
{
int s[10][2],f[10][2],i;

printf("Enter the number of activities : ");
scanf("%d",&A);

for(i=0;i<A;i++)
 {
   s[i][0]=f[i][0]=i;
 }
printf(" foo %d soo %d",f[0][0],s[0][0]);
printf("\nEnter the starting times : ");
for(i=0;i<A;i++)
scanf("%d",&s[i][1]);

printf("\nEnter the finish times : ");
for(i=0;i<A;i++)
scanf("%d",&f[i][1]);

RAS(s,f,0);
s[0][0]=1;
for(i=0;i<A;i++)
{
if(s[i][0]==1)
printf("  %d",f[i][0]);
}

}
