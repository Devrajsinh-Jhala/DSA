#include<iostream>
using namespace std;

int linearSearch(int a[], int n, int key){
    for(int i=0;i<n;i++){
        if(a[i] == key){
            return i;
            break;
        }
    }
    return -1;
}

int binarySearch(int a[], int n, int key){
    int s=0,e = n;

    while(s<=e){
        int mid = (s + e)/2;
        if(a[mid] == key){
            return mid;
            break;
        }
        else if(a[mid]<key){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return -1;
}


int main(){
    int n; cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int key; cin >> key;

    cout << linearSearch(a,n,key) << endl;
    cout << binarySearch(a,n,key) << endl;

    return 0;
}