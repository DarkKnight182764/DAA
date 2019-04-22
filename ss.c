#include<stdio.h>
#include<stdlib.h>
int w[]={0,5,7,10,12,15,18,20};
int n=7,m=35;
int x[10];
void display(){
    printf("-----------------\n");
    for(int i=1;i<=n;i++){
        printf("%d\n",x[i]);
    }
    printf("-----------------\n");
}
void bk(k,s,r){
    if(k>n)
        return;
    for(int i=0;i<=1;i++){
        if(s+w[k]*i<=m && s+w[k]*i+r>=m){
            x[k]=i;
            if(s+w[k]*i==m){
                display();
            }
            else{
                bk(k+1,s+w[k]*i,r-w[k]);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int r=0;
    for(int i=1;i<=n;i++){
        r+=w[i];
    }
    bk(1,0,r);
    return 0;
}
