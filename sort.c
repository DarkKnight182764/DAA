#include<stdio.h>
int arr[]={5,2,2,4,6,1,3};
int n=7;

void display(){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void ins(){
    int i,key;
    for(int j=1;j<n;j++){
        key=arr[j];
        i=j-1;
        while(i>-1 && arr[i]>key){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
    display();
}

int partition(int p,int r){
    int pivot=arr[r];
    int i=p-1,swap;
    for(int j=p;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap=arr[j];        //SWAP arr[i] and arr[j]
            arr[j]=arr[i];
            arr[i]=swap;
        }
    }
    swap=arr[i+1];        //SWAP arr[i+1] and arr[r]
    arr[i+1]=arr[r];
    arr[r]=swap;
    return i+1;
}
void qs(int p,int r){
    if(p<r){
        int q=partition(p,r);
        qs(p,q-1);
        qs(q+1,r);
    }
}

void merge(int p,int q,int r){
    int l[20],ri[20];
    for(int i=p;i<=q;i++){
        l[i-p]=arr[i];
    }
    for(int i=q+1;i<=r;i++){
        ri[i-q-1]=arr[i];
    }
    l[q-p+1]=1000;
    ri[r-q]=1000;
    int i=0,j=0,k=p;
    while(k<=r){
        if(l[i]<ri[j]){
            arr[k]=l[i];
            k++;
            i++;
        }
        else{
            arr[k]=ri[j];
            k++;
            j++;
        }
    }
}
void msort(int p,int r){
    if(p<r){
        int q=(p+r)/2;
        msort(p,q);
        msort(q+1,r);
        merge(p,q,r);
    }
}

int main(int argc, char const *argv[])
{
    //ins();
    //qs(0,n-1);
    //display();
    msort(0,n-1);
    display();
    return 0;
}
