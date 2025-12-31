#include<stdio.h>

int Summation(int arr[],int l,int mid,int h){
    int leftSum=-1000000000;
    int sum=0;
    for(int i=mid;i>=l;i--){
        sum=sum+arr[i];
        if(sum>leftSum){
            leftSum=sum;
        }
    }
    int rightSum=-1000000000;
    sum=0;
    for(int i=mid+1;i<=h;i++){
        sum=sum+arr[i];
        if(sum>rightSum){
            rightSum=sum;
        }
    }
    return (leftSum+rightSum);
}




int MaximumSumSubArray(int arr[],int l,int h){
    if(l==h){
        return arr[h];
    }
    else{
        int mid=(l+h)/2;
        int leftElement=MaximumSumSubArray(arr,l,mid);
        int rightElement=MaximumSumSubArray(arr,mid+1,h);
        int middleElement=Summation(arr,l,mid,h);

        if((leftElement>rightElement) && (leftElement>middleElement)){
            return leftElement;
        }
        else if((rightElement>leftElement) && (rightElement>middleElement)){
            return rightElement;
        }
        else if((middleElement>leftElement) && (middleElement>rightElement)){
            return middleElement;
        }
    }

}






int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x=MaximumSumSubArray(arr,0,n-1);
    printf("%d",x);
}
