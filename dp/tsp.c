#include<stdio.h>
int adjmat[4][4]={
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};
int n=4;

void remov(int s[],int k,int slength,int removed[]){    
    for(int i=0,j=0;i<slength;i++,j++){
        removed[j]=s[i];
        if(s[i]==k){
            j--;
        }
    }    
}

int g(int curr,int s[],int slength){
    if(slength==0)
        return adjmat[curr][0];
    int min=10000,k,temp,removed[10];
    for(int i=0;i<slength;i++){
        k=s[i];  
        remov(s,k,slength,removed);      
        temp=g(k,removed,slength-1);
        if(adjmat[curr][k]+temp<min){
            min=adjmat[curr][k]+temp;
        }
    }
    return min;
}

int main(int argc, char const *argv[])
{
    int s[3];
    s[0]=1;
    s[1]=2;
    s[2]=3;
    int res=g(0,s,3);
    printf("%d\n",res);
    return 0;
}
