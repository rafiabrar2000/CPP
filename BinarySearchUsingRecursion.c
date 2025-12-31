#include<stdio.h>

int BinarySearch(int arr[],int l,int h,int k){
    if(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==k){
            return arr[mid];
        }
        else if(arr[mid]>k){
            return BinarySearch(arr,l,mid-1,k);
        }
        else if(arr[mid]<k){
            return BinarySearch(arr,mid+1,h,k);
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
    int x=BinarySearch(arr,0,n-1,k);
    if(x==-1){
        printf("Not Found");
    }
    else{
        printf("Found");
    }
}
