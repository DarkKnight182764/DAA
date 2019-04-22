#include<stdio.h>
#include<stdlib.h>
int n=3,max_wt=50,B[100][100];

void knap(int wt[],int val[]){
    for(int i=0;i<=max_wt;i++){
        B[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        B[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int w=1;w<=max_wt;w++){
            if(wt[i]<=w){
                if(B[i-1][w-wt[i]]+val[i]>B[i-1][w]){
                    B[i][w]=B[i-1][w-wt[i]]+val[i];
                }
                else{
                    B[i][w]=B[i-1][w];
                }
            }
            else{
                B[i][w]=B[i-1][w];
            }
        }
    }
}
void display(){
    for(int i=0;i<=n;i++){
        for(int w=0;w<=max_wt;w++){
            printf("%d ",B[i][w]);
        }
        printf("\n");
    }
}
void items(int wt[]){
    int i=n,w=max_wt;
    while(i>0 && w>0){
        if(B[i][w]!=B[i-1][w]){
            w-=wt[i];
            printf("item %d\n",i);
        }
        i--;
    }
}
int main(int argc, char const *argv[])
{
    //init
    int wt[100]={0,10,30,20};
    int val[100]={0,60,120,100};
    knap(wt,val);
    display();
    items(wt);
    return 0;
}

