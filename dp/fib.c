#include<stdio.h>
int main(int argc, char const *argv[])
{
    int x=1,y=1,n=10,z;
    for(int i=1;i<=n;i++){
        z=x+y;
        y=x;
        x=z;
        printf("%d\n",z);
    }
    return 0;
}
