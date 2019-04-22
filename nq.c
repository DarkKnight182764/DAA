#include<stdio.h>
#include<stdlib.h>
int n;
int arr[100];
void display(){
    printf("-----------------\n");
    for(int i=1;i<=n;i++){
        printf("%d\n",arr[i]);
    }
    printf("-----------------\n");
}
int place(int k,int i){
    for(int j=1;j<k;j++){
        if(arr[j]==i || abs(j-k)==abs(arr[j]-i)){
            return 0;
        }
    }
    return 1;
}
void nq(int k){
    for(int i=1;i<=n;i++){
        if(place(k,i)==1){
            arr[k]=i;
            if(k==n){
                display();
            }
            else{
                nq(k+1);
            }
        }
    }
}
int main(int argc, char const *argv[]){
    n=4;
    nq(1);
    return 0;
}
