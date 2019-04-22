#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n=4;
int col[10];
int place(int k,int kcol){
    for(int i=1;i<k;i++){
        if(col[i]==kcol)
            return 0;
        if(abs(i-k)==abs(kcol-col[i]))
            return 0;
    }
    return 1;
}
void display(){
    for(int i=1;i<=n;i++){
        printf("%d\n",col[i]);
    }
    printf("---------\n");
}
void nq(int k){    
    if(k>n)
        return;
    for(int i=1;i<=n;i++){
        if(place(k,i)==1){
            col[k]=i;
            if(k==n){
                display();
                return;
            }
            nq(k+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    nq(1);
    return 0;
}
