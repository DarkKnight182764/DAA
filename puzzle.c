#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int state[4][4];
    struct node *parent;
    int cost,dist;
}node;
int n=4,heap_size=0;
node* livenode_heap[20000];
void min_heapify(int i){
    int left=2*i,right=2*i+1,smallest;
    if(left>heap_size)      //leaf
        return;
    else if(right>heap_size){
        if(livenode_heap[i]->cost>livenode_heap[left]->cost)
            smallest=left;
        else 
            return;
    }
    else if(livenode_heap[left]->cost<livenode_heap[i]->cost || livenode_heap[right]->cost<livenode_heap[i]->cost){
        if(livenode_heap[left]->cost<livenode_heap[right]->cost)
            smallest=left;
        else{
            smallest=right;
        }        
    }
    else
        return;
    node *temp=livenode_heap[i];
    livenode_heap[i]=livenode_heap[smallest];
    livenode_heap[smallest]=temp;
    min_heapify(smallest);
}
void build_heap(int size){
    heap_size=size;    
    for(int i=heap_size/2;i>0;i--){
        min_heapify(i);
    }
}
node *extract_min(){
    node *temp=livenode_heap[1];
    livenode_heap[1]=livenode_heap[heap_size];
    livenode_heap[heap_size]=temp;
    //free(livenode_heap[heap_size]);
    heap_size--;
    min_heapify(1);
    return temp;
}
void decrease_key(int i,int new_cost){
    if(i==1)    
        return;
    livenode_heap[i]->cost=new_cost;
    int parent=i/2;
    node *temp;
    while(i>1 && livenode_heap[parent]->cost>livenode_heap[i]->cost){
        temp=livenode_heap[i];
        livenode_heap[i]=livenode_heap[parent];
        livenode_heap[parent]=temp;
        i=parent;
        parent=i/2;
    }
}
void insert(node *new_node){
    livenode_heap[++heap_size]=new_node;
    decrease_key(heap_size,new_node->cost);
}
void display_state(int state[4][4]){
    printf("--------------\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",state[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
}
void display_heap(){
    printf("--------------\n");
    for(int i=1;i<=heap_size;i++){  
        printf("Heap element %d\n",i);
        printf("cost:%d\n",livenode_heap[i]->cost);
        display_state(livenode_heap[i]->state);                        
    }
    printf("--------------\n");
}
void assign(int source[][4],int dest[][4]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dest[i][j]=source[i][j];
        }
    }
}
int get_cost(int state[][4],int dist){
    int ctr=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(state[i][j]!=0){                
                if(state[i][j]!=i*n+j+1)
                    ctr++;
            }            
        }
    }
    return ctr+dist;
}
int is_equal(int s1[][4],int s2[][4]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s1[i][j]!=s2[i][j])
                return 0;
        }
    }
    return 1;
}
int is_goal(int state[4][4]){
    int temp[4][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,0}        
    };
    return (is_equal(state,temp));
}
node *alloc(int state[][4],int cost,node *parent){
    node *res=malloc(sizeof(node));
    assign(state,res->state);
    res->cost=cost;
    res->parent=parent;
    return res;
}
int is_repeat(node *temp,node *E){
    if(is_equal(temp->state,E->state)==0){
        if(E->parent!=NULL){
            if(is_equal(temp->state,E->parent->state)==0){
                return 0;
            }
            else
                return 1;
        }
        else
            return 0;
    }
    else{
        return 1;
    }
}
int get_children(node *E,node *store[]){
    int ctr=0;
    int bi,bj;    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(E->state[i][j]==0){
                bi=i;
                bj=j;
            }                
        }
    }
    node *temp=alloc(E->state,E->cost,E->parent);
    if(bi>0){       //UP
        int t=temp->state[bi][bj];        
        temp->state[bi][bj]=temp->state[bi-1][bj];
        temp->state[bi-1][bj]=t;
        if(is_repeat(temp,E)==0)
            store[ctr++]=temp;
    }
    temp=alloc(E->state,E->cost,E->parent);
    if(bj<n-1){       //RIGHT
        int t=temp->state[bi][bj];        
        temp->state[bi][bj]=temp->state[bi][bj+1];
        temp->state[bi][bj+1]=t;
        if(is_repeat(temp,E)==0)
            store[ctr++]=temp;
    }
    temp=alloc(E->state,E->cost,E->parent);
    if(bi<n-1){       //DOWN
        int t=temp->state[bi][bj];        
        temp->state[bi][bj]=temp->state[bi+1][bj];
        temp->state[bi+1][bj]=t;
        if(is_repeat(temp,E)==0)
            store[ctr++]=temp;
    }
    temp=alloc(E->state,E->cost,E->parent);
    if(bj>0){       //LEFT
        int t=temp->state[bi][bj];        
        temp->state[bi][bj]=temp->state[bi][bj-1];
        temp->state[bi][bj-1]=t;
        if(is_repeat(temp,E)==0)
            store[ctr++]=temp;
    }   
    return ctr;
}
void print_path(node *ans){
    printf("Goal reached\n");
    while(ans!=NULL){        
        display_state(ans->state);
        ans=ans->parent;
        printf("    ^\n    |\n    |\n");
    }
    printf("   Start\n");
}
void lcp(int init_state[][4]){
    if(is_goal(init_state)==1)
        display_state(init_state);
    else{
        node *E=malloc(sizeof(node));
        assign(init_state,E->state);
        E->parent=NULL;
        E->cost=0;
        heap_size=0;
        int num_children;
        node *children[4];
        do{
            //printf("%d\n",heap_size);
            num_children=get_children(E,children);
            for(int i=0;i<num_children;i++){
                node *x=children[i];
                x->parent=E;
                if(is_goal(x->state)==1){   //goal found
                    print_path(x);
                    return;
                }  
                x->dist=x->parent->dist+1;
                x->cost=get_cost(x->state,x->dist);                 
                insert(x);
            }
            E=extract_min();
        }while(heap_size!=0);
        printf("No answer found\n");
    }
}
int position(int x,int state[][4]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(state[i][j]==x)
                return i*n+j+1;
        }
    }
}
int less(int x,int state[][4]){
    int ctr=0;
    for(int j=1;j<x;j++){
        if(position(j,state)>position(x,state))
            ctr++;
    }
    return ctr;
}
int get_x(int state[][4]){
    int bi,bj;    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(state[i][j]==0){
                bi=i;
                bj=j;
            }                
        }
    }
    /*int num=bi*n+bj+1;
    if((bi%2==0 && num%2==0) || (bi%2!=0 && num%2!=0)){
        return 1;
    }
    else{
        return 0;       
    }*/
    return ((n-bi)%2);
}
int main(int argc, char const *argv[])
{    
    int temp[4][4]={
        {1,2,3,4},
        {5,6,0,8},
        {9,10,11,12},
        {13,14,15,7}        
    };            
    lcp(temp);
    return 0;
}
