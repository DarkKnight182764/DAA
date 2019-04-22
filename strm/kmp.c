#include<stdio.h>
#include<string.h>
char text[]="ABDCBDCA";
char pat[]="DC";
int lps[100];
void get_lps(){
    int len=0,i=1,m=strlen(pat);
    lps[0]=0;
    while(i<m){
        if(pat[len]==pat[i]){
            lps[i]=++len;
            i++;
        }
        else{
            if(len>0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void algo(){
    int m=strlen(pat),n=strlen(text),j=0,i=0;
    get_lps();
    while(i<n){
        if(pat[j]==text[i]){
            j++;
            i++;                     
        }
        if(j==m){
            printf("Pattern found at %d\n",i-m);
            j=lps[j-1];
        }  
        if(i<n && pat[j]!=text[i]){
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}
int main(int argc, char const *argv[])
{
    algo();    
    return 0;
}
