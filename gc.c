#include<stdio.h>
#include<stdlib.h>
int m=3;
int adj[5][5]={
    {0,1,1,0,1},
    {1,0,1,0,1},
    {1,1,0,1,0},
    {0,0,1,0,1},
    {1,1,0,1,0}
};
int n=5;
int x[5];
void display(){
    printf("-----------------\n");
    for(int i=0;i<n;i++){
        printf("%d\n",x[i]);
    }
    printf("-----------------\n");
}
int isValid(int k,int i){
    for(int j=0;j<n;j++){
        if(adj[j][k]==1 && i==x[j])
            return 0;
    }
    return 1;
}
void gc(int k){
    if(k>=n)
        return;
    for(int i=1;i<=m;i++){
        if(isValid(k,i)==1){
            x[k]=i;
            if(k==n-1)
                display();
            else{
                gc(k+1);       
            }            
        }
    }
}
int main(int argc, char const *argv[])
{
    gc(0);
    return 0;
}
