#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char c;
    int freq;
    struct node *left,*right;
}node;
int heap_size;
node *heap[20];
void min_heapify(int i){
    if(i<=0 || i>heap_size)
        return;
    int left=2*i,right=2*i+1,smallest;
    if(left>heap_size){
        return;
    }
    else if(right>heap_size){
        if(heap[i]->freq>heap[left]->freq)
            smallest=left;
        else
            return;
    }
    else{
        if(heap[right]->freq<heap[i]->freq && heap[right]->freq<heap[left]->freq)
            smallest=right;
        else if(heap[left]->freq<heap[i]->freq && heap[right]->freq>heap[left]->freq)
            smallest=left;
        else{
            return;
        }
    }
    node *temp=heap[i];
    heap[i]=heap[smallest];
    heap[smallest]=temp;
    min_heapify(smallest);
}
void build_heap(int size){
    heap_size=size;
    for(int i=heap_size/2;i>0;i--){
        min_heapify(i);
    }
}
node *extract_min(){
    node *ret=heap[1];
    heap[1]=heap[heap_size--];    
    min_heapify(1);
    return ret;
}
void decrease_freq(int i,int new_val){
    int parent=i/2;
    node *temp;
    while(parent>0){
        if(heap[parent]->freq>heap[i]->freq){
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

node *alloc(char c,int freq){
    node *ret=malloc(sizeof(node));
    ret->c=c;
    ret->freq=freq;
    ret->left=NULL;
    ret->right=NULL;
    return ret;
}

void algo(){
    node *n1,*n2,*temp;
    while(heap_size>1){
        n1=extract_min();
        n2=extract_min();
        temp=alloc(' ',n1->freq+n2->freq);
        temp->left=n1;
        temp->right=n2;
        heap[++heap_size]=temp;
        decrease_freq(heap_size,n1->freq+n2->freq);
    }
}
void display(int arr[],int length){
    for(int i=0;i<length;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
void printhuff(node *root,int length,int arr[]){
    if(root->left!=NULL){
        arr[length]=0;
        printhuff(root->left,length+1,arr);
    }
    if(root->right!=NULL){
        arr[length]=1;
        printhuff(root->right,length+1,arr);
    }
    if(root->left==NULL && root->right==NULL){
        printf("%c\n",root->c);
        display(arr,length);
    }
}   

int main(int argc, char const *argv[])
{    
    heap[1]=alloc('f',5);
    heap[2]=alloc('a',45);
    heap[3]=alloc('b',13);
    heap[4]=alloc('d',16);
    heap[5]=alloc('e',9);
    heap[6]=alloc('c',12);
    build_heap(6);

    algo();
    int arr[10];
    printhuff(heap[1],0,arr);
    return 0;
}
