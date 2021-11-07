#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[], int l, int r){
    int pivot = arr[r-1];
    int i = l-1;

    for(int j=l; j<r; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        }
    }

    swap(arr,i+1,r);
    return i+1;
}


void Quick_Sort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr,l,r);
        Quick_Sort(arr,l,pi-1);
        Quick_Sort(arr,pi+1,r);
    }

}

int main(){

    int arr[] = {5,4,3,2,1};

    Quick_Sort(arr,0,5);
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }

    return 0;
}