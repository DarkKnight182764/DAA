#include<stdio.h>
int e1=2,e2=4,x1=3,x2=6,n=5;


void display(int arr[][10]){
    for(int i=1;i<=2;i++){
        for(int w=1;w<=n;w++){
            printf("%d ",arr[i][w]);
        }
        printf("\n");
    }
}
void al(int a[][10],int t[][10]){
    int f[3][10],p[3][10],res,res_p;
    f[1][1]=e1+a[1][1];
    f[2][1]=e2+a[2][1];
    //printf("%d %d",f[1][1],f[2][1]);
    for(int j=2;j<=n;j++){
        if(f[1][j-1]+a[1][j]<f[2][j-1]+t[2][j-1]+a[1][j]){
            f[1][j]=f[1][j-1]+a[1][j];
            p[1][j]=1;
        }            
        else{
            f[1][j]=f[2][j-1]+t[2][j-1]+a[1][j];
            p[1][j]=2;
        }
        if(f[2][j-1]+a[2][j]<f[1][j-1]+t[1][j-1]+a[2][j]){
            f[2][j]=f[2][j-1]+a[2][j];
            p[2][j]=2;
        }            
        else{
            f[2][j]=f[1][j-1]+t[1][j-1]+a[2][j];
            p[2][j]=1;
        }
    }
    if(f[1][n]+x1>f[2][n]+x2){
        res=f[2][n]+x2;
        res_p=2;
    }
    else{
        res=f[1][n]+x1;
        res_p=1;
    }
    display(f);
    display(p);
    printf("%d,%d",res,res_p);
}
int main(int argc, char const *argv[])
{
    int a[][10]={
        {},
        {0,7,9,3,4,8},
        {0,8,5,6,4,5}
    };
    int t[][10]={
        {},
        {0,2,3,1,3},
        {0,2,1,2,2}
    };
    al(a,t);
    return 0;
}