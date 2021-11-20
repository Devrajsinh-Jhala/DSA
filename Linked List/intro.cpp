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

struct Node{
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
        }
    };

class LinkedList{

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

    Node* FindMidpoint(){
        // Here we use slow and fast pointer approach where slow moves one step and fast moves 2 steps or more
        Node *slow = head, *fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    Node* Find_kth_Element_from_Last(int k){
        Node* slow = head, *fast = head;
        while(fast != NULL && --k){
            fast = fast -> next;
        }
        if(fast != NULL){
            fast = fast -> next;
            while(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
            return slow;
        }else{
            cout << "Position does'nt exist" << endl;
            return NULL;
        }

    }

    Node* get_head(){
        return head;
    }

    Node* get_tail(){
        return tail;
    }


};

Node *Find_the_Intersection_Point(Node* head1, Node* head2){
    int l1 = 0,l2 = 0;
    Node* temp1 = head1, *temp2 = head2;
    while(temp1 != NULL){
        l1++;
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL){
        l2++;
        temp2 = temp2 -> next;
    }

    int diff = abs(l1 - l2);
    if(l1<l2){
        temp1 = head2;
        temp2 = head1;
    }else{
        temp1 = head1;
        temp2 = head2;        
    }

    while(diff--){
        temp1 = temp1 -> next;
    }
    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){
            return temp1;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return NULL;

}

Node* Find_the_Intersection_Point2(Node* head1, Node* head2){
    Node* temp1 = head1, *temp2 = head2;
    while(true){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

        if(temp1 == temp2){
            return temp1;
        }

        if(temp1 == NULL){
            temp1 = head2;
        }
        if(temp2 == NULL){
            temp2 = head1;
        }
    }

    return NULL;

}


int main()
{
    /*
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
    Node *mid = ll.FindMidpoint();
    cout << "Midpoint is: " << mid -> data << endl;
    Node *kth = ll.Find_kth_Element_from_Last(5);
    cout << "Kth Position is: " << kth -> data << endl;

    */

   LinkedList l1 = LinkedList();
   l1.InsertAtEnd(10);
   l1.InsertAtEnd(20);
   l1.InsertAtEnd(30);
   l1.InsertAtEnd(40);
   l1.InsertAtEnd(50);
   l1.InsertAtEnd(60);

    LinkedList l2 = LinkedList();
    l2.InsertAtEnd(110);
    l2.InsertAtEnd(120);

    // Making an Intersection Point

    Node* head1 = l1.get_head();
    Node* tail2 = l2.get_tail();

    tail2 -> next = head1 -> next -> next -> next -> next;
    l1.print();
    l2.print();

    Node* Find = Find_the_Intersection_Point2(l1.get_head(), l2.get_head());
    cout << "Intersection Point is: " << Find -> data << endl;

    return 0;
}