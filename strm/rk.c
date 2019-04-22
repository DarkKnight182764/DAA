#include<stdio.h>
#include<string.h>
char text[]="ABDCBDCA";
char pat[]="DC";
int d=256,q=11;
void search(){
    int m=strlen(pat),n=strlen(text);
    int h=1,p=0,t=0,found=0;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+text[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            for(int j=i;j<i+m;j++){
                if(pat[j]!=text[j]){
                    found=1;
                    break;
                }                
            }
            if(found==1){
                printf("Match found at i=%d\n",i);
                found=0;
            }
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
                t=t+q;
        }
    }
}
int main(int argc, char const *argv[])
{
    search();
    return 0;
}
