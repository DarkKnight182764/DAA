#include<stdio.h>
int n=40000,factors[100],num_factors=0,max=-1;

int get_sum(int depth,int curr[]){
    int sum=0;
    for(int i=0;i<depth;i++){
        sum+=curr[i];
    }
    return sum;
}
int get_prod(int depth,int curr[]){
    int prod=1;
    for(int i=0;i<depth;i++){
        prod*=curr[i];
    }
    return prod;
}

void display(int curr[]){
    for(int i=0;i<4;i++){
        printf("%d ",curr[i]);
    }
    printf("\n");
}
void fs(int depth,int curr[]){
    int prod=get_prod(depth,curr),sum=get_sum(depth,curr);
    if(depth==4){
        if(sum==n && prod>max){
            display(curr);
            max=prod;
        }
        return;
    }
    for(int i=0;i<num_factors;i++){
        if(sum+factors[i]<=n){
            curr[depth]=factors[i];
            fs(depth+1,curr);
        }        
    }
}

int main(int argc, char const *argv[])
{    
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            factors[num_factors++]=i;
        }
    }    
    int curr[4];
    fs(0,curr);
    printf("%d\n",max);
    return 0;
}

