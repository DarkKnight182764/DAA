#include<stdio.h>
#include<stdlib.h>
int nv=1,nh=1;
long long int x[100],y[100];        //along row:y, along col:x
long long int cost;
int num_rows,num_cols,num_q,xl,yl;
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
int main(int argc, char const *argv[])
{       
    scanf("%d",&num_q);
    for(int i=1;i<=num_q;i++){
        scanf("%d %d",&num_rows,&num_cols);
        for(int j=0;j<num_rows-1;j++){
            scanf("%lld",&y[j]);            
        }
        for(int j=0;j<num_cols-1;j++){
            scanf("%lld",&x[j]);
        }
        xl=num_cols-1;
        yl=num_rows-1;
        qsort(x,100,sizeof(int),comp);
    }
    return 0;
}
/*1
6 4
2 1 3 1 4
4 1 2*/