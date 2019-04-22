#include<stdio.h>
#include<stdlib.h>
int wt[]={0,5,7,10,12,15,18,20};
int n=7,m=35;
int x[20];

void display(){
    for(int i=1;i<=n;i++)
        printf("%d ",x[i]);
    printf("\n");
}

void ss(int s,int k,int r){
    if(k>n)
        return;
    for(int i=0;i<=1;i++){
        if(i*wt[k]+s<=m && i*wt[k]+s+r>=m){
            x[k]=i;
            if(s+i*wt[k]==m)
                display();
            else{
                ss(s+i*wt[k],k+1,r-wt[k]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int r=0;
    for(int i=1;i<=n;i++){
        r+=wt[i];
    }
    ss(0,1,r);
    return 0;
}
