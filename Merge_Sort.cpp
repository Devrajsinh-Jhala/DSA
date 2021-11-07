#include<iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1],b[n2]; // temp arrays
    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }

    for(int i=0;i<n2;i++){
        b[i] = arr[mid + l + i];
    }

    int i=0, j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            a[k] = a[i];
            k++; i++;
        }

        else{
            a[k] = b[j];
            k++,j++;
        }

    }

    while(i<n1){
        a[k] = a[i];
        k++; i++;      
    }

    while(j<n2){
        a[k] = b[j];
        k++,j++;   
    }

}

void Merge_Sort(int arr[], int l, int r){
    int mid = (l+r)/2;
    if(l<r){
        Merge_Sort(arr,l,mid);
        Merge_Sort(arr,mid+1,r);

        Merge(arr,l,mid,r);
    }
}


int main()
{
    int arr[] = {2,1,3,5,4};
    Merge_Sort(arr,0,4);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}