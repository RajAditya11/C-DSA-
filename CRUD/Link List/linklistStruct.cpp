#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Constructor previously was:
    /*
    Node( int val ){
        data = val;
        next = nullptr;
    }
    */

    Node( int val ) : data(val) , next(nullptr) {}  
    // This is a constructor. Modern C++ style initialization called member initializer list.
};

void printList( struct Node* head){
    if( head == nullptr ){
        cout<<"List is empty"<<endl;
        return;
    }
    struct Node* itr = head;  // temporary iterator pointer
    while( itr != nullptr ){
        cout<<itr->data<<"->";
        itr = itr->next;
    }
}

// 10 -> 20 -> 30 -> NULL

void reversePrintList( struct Node* head ){
    if( head == nullptr ){
        cout<<"List is empty"<<endl;
        return;
    }

    struct Node* itr = head;

    // recursive approach termination condition and backtracking print
    if( itr->next != nullptr){
        reversePrintList( itr -> next );
    }
    cout<<itr -> data <<"->";
}

int main(){

    int totalData;
    cout<<"Enter total number of data :";
    cin>>totalData;

    Node* itr = nullptr;
    Node* head = nullptr;
    Node* tail = nullptr;


    cout<<"Enter data values :";
    for( int i = 0 ; i < totalData ; i++ ){
        int val;
        cin>>val;

        if( head == nullptr ){
            head = new Node(val);
            itr = head;
        }else{
            itr->next = new Node(val);
            itr = itr->next;
        }
        if( i == totalData - 1 ){
            tail = itr;
        }
    }

    cout<<"Linked List is : ";
    printList( head );

    cout<<endl;

    cout<<"Reversed Linked List is : ";
    reversePrintList( head );



    return 0;
}