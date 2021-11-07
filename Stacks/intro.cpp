#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int max_size;
    int top;

    public:
    Stack(int size = 10){
        arr = new int(size);
        max_size = size;
        top = -1;
    }

    bool full(){
        return (top + 1) == max_size;
    }

    bool empty(){
        return top == -1;
    }

    void push(int data){
        if(full()){
            cout << "Stack Overflow" << endl;
            return;
        }else{
            top ++;
            arr[top] = data;
        }
    }

    void pop(){
        if(empty()){
            cout << "Stack Underflow" << endl;
            return;
        }else{
            top--;
        }
    }

    int get_top(){
        if(empty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }else{
            return arr[top];
        }
    }

    int get_size(){
        return top + 1;
    }

    int get_maxsize(){
        return max_size;
    }

    void print(){
        cout << endl;
        for(int i=0;i<max_size;i++){
            cout << arr[i];
        }cout << endl;
    }
};

int main(){

    Stack st = Stack(5);
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.get_top() << endl;
    // cout << st.print() << endl;



    return 0;
}