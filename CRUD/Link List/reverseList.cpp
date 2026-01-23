#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int val ) : data(val ) , next( nullptr) {}

};

void printList( struct Node* head ){
    if( head == nullptr ){
        cout<<"List is empty"<<endl;
        return;
    }

    Node* tempItr = head;
    while( tempItr != nullptr ){
        cout<<tempItr -> data <<"->";
        tempItr = tempItr->next;
    }
}

Node* reverseList( struct Node* head ){
    Node* curr = head;
    Node* prev = nullptr , *next = nullptr;

    while( curr != nullptr ){
        next = curr->next;
        curr->next = prev;
        prev = curr;

        // move forward
        curr = next;
    }
    return prev;
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
    Node* reversedHead = reverseList( head );
    printList( reversedHead );

    return 0;
}