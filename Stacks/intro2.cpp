#include<bits/stdc++.h>
using namespace std;

class Stack{
    struct Node
    {
        int data;
        Node* next;

        Node(int d){
            data = d;
            next = NULL;
        }
    };

    Node *head;
    int size;

public:
    Stack(){
        head = NULL;
        size = 0;
    }


    bool empty(){
        return head == NULL;
    }

    void push(int data){
        Node* newHead = new Node(data);
        if(empty()){
            head = newHead;
            size = 1;
        }else{
            newHead -> next = head;
            head = newHead;
        }
        size += 1;
    }

    void pop(){
        if(empty()){
            cout << "Stack Underflow" << endl;
            return;
        }else{
            Node *todelete = head;
            head = head -> next;
            free(todelete);
            size -= 1;
        }
    }

    int top(){
        if(empty()){
            cout << "Stack Underflow" << endl;
            return -1;
        }else{
            return head -> data;
        }
    }

    int get_size()
    {
        return size-1;
    }

    void print(){
        if(empty()){
            cout << "Stack is Empty!" << endl;
            return;
        }else{
            cout << "Top to bottom" << endl;
            Node* current = head;
            while(current != NULL){
                cout << current -> data << " ";
                current = current -> next;
            }
            cout << endl;
        }
    }
    
};


int main()
{
    Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout << st.top() << endl;
    cout << st.get_size() << endl;
    st.print();

    st.pop();
    st.print();
    cout << st.top() << endl;
    cout << st.get_size() << endl;


    return 0;
}