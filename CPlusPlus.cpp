#include<iostream>
using namespace std;



int main()
{
    int x, y;
    int sum,sum1=0;
    cout << "Type a number: ";
    cin >> x;
    cout << "Type another number: ";
    cin >> y;
    sum = x + y;
    cout << sum << endl;
    cout << sum1 << endl;
    int i=1;
    while(i<=20){
        cout << i <<" ";
        i++;
    }
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}


