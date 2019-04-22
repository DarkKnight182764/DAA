#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
    int num,key;
    struct vertex *parent;
}vertex;
int heap_size,n;
int adjmat[100][100]={
    {-1,10,-1,5,-1},
    {-1,-1,1,2,-1},
    {-1,-1,-1,-1,4},
    {-1,3,9,-1,2},
    {7,-1,6,-1,-1}
};
vertex *heap[20],*og[20];
void min_heapify(int i){
    if(i<=0 || i>heap_size)
        return;
    int left=2*i,right=2*i+1,smallest;
    if(left>heap_size){
        return;
    }
    else if(right>heap_size){
        if(heap[i]->key>heap[left]->key)
            smallest=left;
        else
            return;
    }
    else{
        if(heap[right]->key<heap[i]->key && heap[right]->key<heap[left]->key)
            smallest=right;
        else if(heap[left]->key<heap[i]->key && heap[right]->key>heap[left]->key)
            smallest=left;
        else{
            return;
        }
    }
    vertex *temp=heap[i];
    heap[i]=heap[smallest];
    heap[smallest]=temp;
    min_heapify(smallest);
}
vertex *alloc(int num){
    vertex *ret=malloc(sizeof(vertex));
    ret->num=num;
    ret->key=1000;
    ret->parent=NULL;
    return ret;
}
void build_heap(int size){
    heap_size=size;
    for(int i=heap_size/2;i>0;i--){
        min_heapify(i);
    }
}
vertex *extract_min(){
    vertex *ret=heap[1];
    heap[1]=heap[heap_size--];    
    min_heapify(1);
    return ret;
}
void decrease_key(int i,int new_val){
    int parent=i/2;
    vertex *temp;
    while(parent>0){
        if(heap[parent]->key>heap[i]->key){
            temp=heap[i];
            heap[i]=heap[parent];
            heap[parent]=temp;
            i=i/2;
            parent=i/2;
        }
        else
            return;
    }
}
void input(){
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){        
        for(int j=0;j<n;j++){
            printf("Enter weight of edge between %d and %d,-1 is disconnected\n",i,j);
            scanf("%d",&adjmat[i][j]);
        }
    }
}
int find_in_heap(int num){
    for(int i=1;i<=heap_size;i++){
        if(heap[i]->num==num)
            return i;
    }
    return 0;
}
void relax(vertex *u,vertex *v,int wt){
    if(v->key>u->key+wt){
        v->key=u->key+wt;
        v->parent=u;
        decrease_key(find_in_heap(v->num),u->key+wt);
    }
}
void algo(int source){
    heap_size=0;
    vertex *u,*v;
    heap[0]=NULL;
    for(int i=0;i<n;i++){
        vertex *temp=alloc(i);
        if(i==source){
            temp->key=0;                    
        }        
        heap[++heap_size]=temp;
        og[heap_size]=temp;
    }
    build_heap(heap_size);    
    while(heap_size>0){
        u=extract_min();
        for(int i=0;i<n;i++){
            if(adjmat[u->num][i]!=-1){  
                v=heap[find_in_heap(i)];
                if(v!=NULL){
                    relax(u,v,adjmat[u->num][i]);
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{    
    /*heap[1]=alloc(0);
    heap[1]->key=1;
    heap[2]=alloc(0);
    heap[2]->key=0;    
    heap[3]=alloc(0);
    heap[3]->key=10;
    heap[4]=alloc(0);
    heap[4]->key=5;
    heap[5]=alloc(0);
    heap[5]->key=4;
    heap[6]=alloc(0);
    heap[6]->key=-1;
    build_heap(6);*/
    //input();
    n=5;
    algo(0);
    return 0;
}

