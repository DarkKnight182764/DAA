#include<stdio.h>
#include<stdlib.h>
typedef struct set{
    int num,rank;
    struct set *parent;
}set;
typedef struct edge{
    int weight;
    set *v1,*v2;
}edge;
set *sets[20];
edge *edges[40];
int num_edges=0,n;
void make_set(int num){
    set *temp=malloc(sizeof(set));
    temp->num=num;
    temp->rank=0;
    temp->parent=NULL;
}
set *find_set(set *x){
    if(x->parent!=x){
        x->parent=find_set(x->parent);
    }
    return x->parent;
}
void link(set *r1,set *r2){
    if(r1->rank>r2->rank){
        r2->parent=r1;        
    }
    else if(r2->rank>r1->rank){
        r1->parent=r2;
    }
    else{
        r1->parent=r2;
        r2->rank++;
    }
}
void set_union(set *s1,set *s2){
    link(find_set(s1),find_set(s2));
}

set *set_alloc(int num){
    set *ret=malloc(sizeof(set));
    ret->num=num;    
    ret->parent=ret;
    ret->rank=0;
    return ret;
}
void edge_alloc(set *u,set *v,int wt){
    edge *ret=malloc(sizeof(edge));
    ret->weight=wt;    
    ret->v1=u;
    ret->v2=v;
    edges[num_edges++]=ret;
}
void input(){
    printf("Enter number of vertices\n");
    scanf("%d",&n);    
    for(int i=0;i<n;i++){
        sets[i]=set_alloc(i);
    }
    int ipv1,ipv2,ipwt;
    do{
        printf("Enter the vertices\n");
        scanf("%d %d",&ipv1,&ipv2);
        if(ipv1==-1)
            break;
        printf("Enter the weight for this edge\n");
        scanf("%d",&ipwt);
        edge_alloc(sets[ipv1],sets[ipv2],ipwt);
        edge_alloc(sets[ipv2],sets[ipv1],ipwt);
    }while(ipv1!=-1);

    edge *temp;
    for(int i=0;i<num_edges;i++){
        for(int j=0;j<num_edges-1;j++){
            if(edges[j]->weight>edges[j+1]->weight){
                temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}
void algo(){
    edge *curr_edge;
    set *u,*v;
    for(int i=0;i<num_edges;i++){
        curr_edge=edges[i];
        u=curr_edge->v1;
        v=curr_edge->v2;
        if(find_set(u)!=find_set(v)){
            set_union(u,v);
        }
    }
}
int main(int argc, char const *argv[])
{
    input();
    algo();
    return 0;
}
