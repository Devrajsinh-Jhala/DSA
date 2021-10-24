#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void DNFSort(int a[], int n){
    int low = 0, mid = 0, high = n-1;

    while(mid<=high){
        if(a[mid] == 0){
            swap(a,low,mid);
            low++; mid++;
        }

        else if(a[mid] == 1){
            mid++;
        }

        else{
            swap(a,mid,high);
            high--;
        }
    }
}


int main(){

    int n; cin >> n; // n -> size of array
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    DNFSort(a,n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    return 0;
}