#include<stdio.h>

void QuickSort(int arr[],int l,int h){
    if(l<h){
        int i=l+1;
        int j=h;
        while(i<=j){
            while((i<=h) && (arr[l]>=arr[i])){
                i=i+1;
            }
            while((j>=l) && (arr[l]<arr[j])){
                j=j-1;
            }
            if(i>j){
                break;
            }
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i=i+1;
            j=j-1;
        }
        int temp1=arr[l];
        arr[l]=arr[j];
        arr[j]=temp1;
        QuickSort(arr,l,j-1);
        QuickSort(arr,j+1,h);
    }
}


void printArray(int arr[],int a){
    for(int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //Before sorting
    printArray(arr,n);

    //After sorting
    QuickSort(arr,0,n-1);
    printf("\n");
    printArray(arr,n);

}
