// Devrajsinh Jhala
// 20th Oct. 2021

#include<iostream>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    int st = 0, e = 4;
    int sum=0; cin >> sum;
    // O(N^2)
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         if(a[i] + a[j] == sum){
    //             cout << i << j << endl;
    //             break;
    //         }
    //     }
    // }

    // O(nlogn) n = number of elements in the array
    // Here we need nlogn to sort the array
    while(st <= e)
    {
        if(a[st] + a[e] == sum){
        cout << st << " " << e << endl;
        break;
        }

        else if(a[st] + a[e] < sum){
        st++;
        }

        else{
            e--;
        }
    }

    return 0;
}