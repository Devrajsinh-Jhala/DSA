#include<bits/stdc++.h>
using namespace std;

/*

    No memory allocated while defining a structure
    Can be declared global as well as local scope
    Linked list are non-contiguous blocks of memory which are linked together using pointers

*/

/*
struct Node{
    // basic structure of linked list
    int data;
    Node *next;

    // constructor
    Node(int d = 0){
        data = d;
        next = NULL;
    }
};

*/

class LinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
    };
    Node* head;
    Node* tail;

public:
    LinkedList(){
        head = NULL;
        // maintaining tail pointer
        tail = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void InsertAtEnd(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = head;
        }else{
            /*
            It takes O(N) time
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
            */

           // Using tail pointer, this operation can be done in O(1);
           tail -> next = newNode;
           tail = tail -> next;
        }

    }

    void InsertAtBeginning(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void DeleteNode(int data){
        Node* temp = head;
        if(head == NULL){
            cout << "Nothing to delete, List is Empty!" << endl;
            return;
        }
        else if(head -> data == data){
            head = head -> next;
            free(temp);
            return;
        }
        else{
            while(temp -> next != NULL && temp -> next -> data != data){
                temp = temp -> next;
            }
            if(temp -> next == NULL){
                cout << "Data does'nt exist" << endl;
                return;
            }else{
                temp -> next = temp -> next -> next;
                free(temp -> next);
            }
        }
    }

    void print(){
        if(head == NULL){
            cout << "List is Empty" << endl;
            return;
        }else{
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> data  << " -> ";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
    }

    void Insert_At_Kth_Position(int k, int val){

        if(k<0){
            cout << "Invalid Position" << endl;
            return;
        }


        if(isEmpty()){
            cout << "List is Empty" << endl;
        }
        Node *newnode = new Node(val);

        if(k == 0){
            newnode -> next = head;
            head = newnode;
            return;
        }else{
            Node* temp = head;
            while(temp != NULL && --k){
                temp = temp -> next;
            }
            if(k == 0){
                newnode -> next = temp -> next;
                temp -> next = newnode;
            }else{
                cout << "Position does'nt exist" << endl;
            }
        }
    }

    void Reverse_Iterative_Method(){
        Node *previous = NULL, *current = head, *next = NULL;
        while(current != NULL){
            next = current -> next;
            current -> next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    Node *Reverse_Recursive_Method(Node *previous, Node *current){
        if(current != NULL){
            Node *head = Reverse_Recursive_Method(current, current -> next);
            current -> next = previous;
            return head;
        }
        else{
            return previous;
        }
    }

    void Reverse_Recursive_Method_ll(){
        head = Reverse_Recursive_Method(NULL,head);
    }

};



int main()
{
    LinkedList ll = LinkedList();
    ll.InsertAtEnd(10);
    ll.InsertAtEnd(20);
    ll.InsertAtEnd(30);
    ll.InsertAtBeginning(5);
    ll.Insert_At_Kth_Position(2,15);
    // ll.DeleteNode(30);
    // ll.DeleteNode(5);
    ll.print();
    // ll.Reverse_Iterative_Method();
    ll.Reverse_Recursive_Method_ll();
    ll.print();

    return 0;
}