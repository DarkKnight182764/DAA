#include<stdio.h>
#include<string.h>
int m,n;
int lcs[20][20];
int
char x[]="bdcaba";
char y[]="abcbdab";

void algo(){
    for(int i=0;i<m;i++){
        lcs[i][0]=0;
    }
    for(int i=0;i<n;i++){
        lcs[0][i]=0;
    }

}

int main(int argc, char const *argv[])
{
    m=strlen(x);
    n=strlen(y);
    return 0;
}

