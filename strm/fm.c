#include<stdio.h>
#include<string.h>
int table[20][256];
char text[]="ABDCBDCA";
char pat[]="ACACA";
int m,n,NUM_CHARS=256;

int get_next_state(int curr_state,char curr_char){
    if(curr_state<m && pat[curr_state]==curr_char)
        return curr_state+1;
    else{
        int res=1;
        for (int ns = curr_state; ns > 0; ns--) 
        { 
            if (pat[ns-1] == curr_char) 
            { 
                int i=0;
                for (i = 0; i < ns-1; i++) 
                    if (pat[i] != pat[curr_state-ns+1+i]) 
                        break; 
                if (i == ns-1) 
                    return ns; 
            } 
        } 
        return 0;
    }
}

void init(){
    for(int curr_state=0;curr_state<=m;curr_state++){
        for(int curr_char=0;curr_char<=NUM_CHARS;curr_char++){
            table[curr_state][curr_char]=get_next_state(curr_state,curr_char);
        }        
    }
}
void display(){
    for(int curr_state=0;curr_state<m;curr_state++){
        for(int curr_char=0;curr_char<=NUM_CHARS;curr_char++){
            if(curr_char=='A' || curr_char=='C')
                printf("%d ",table[curr_state][curr_char]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    m=strlen(pat);n=strlen(text);
    init();
    display();
    return 0;
}
