#include<stdio.h>

int MSort(int arr[],int l,int h){
    int inv_count=0;
    if(l<h){
        int mid=(l+h)/2;
        inv_count += MSort(arr,l,mid);
        inv_count += MSort(arr,mid+1,h);
        inv_count += Merge(arr,l,mid,h);
    }
    return inv_count;
}

int Merge(int arr[],int l,int mid,int h){
    int i=l;
    int j=mid+1;
    int k=l;
    int inv_count=0;
    int B[20];
    while(i<=mid && j<=h){
        if(arr[i]<=arr[j]){
            B[k]=arr[i];
            i++;
            k++;
        }
        else if(arr[j]<=arr[i]){
            B[k]=arr[j];
            j++;
            k++;
            inv_count = inv_count + ((mid+1) - i);
        }
    }
    if(i>mid){
        while(j<=h){
           B[k]=arr[j];
            j++;
            k++;
        }
    }
    else if(j>h){
       while(i<=mid){
           B[k]=arr[i];
            i++;
            k++;
       }
    }
    for(int p=0;p<=h;p++){
        arr[p]=B[p];
    }
    return inv_count;

}

//void printArray(int arr[],int a){
    //for(int i=0;i<a;i++){
       // printf("%d ",arr[i]);
    //}
//}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //Before sorting
    //printArray(arr,n);

    //After sorting
    printf(" Number of inversions are %d \n",MSort(arr,0,n-1));
    //printf("\n");
    //printArray(arr,n);

}

