#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int val ) : data(val) , next(nullptr) {}

};

class Stack{
    Node* top;
    public :
    Stack() : top( nullptr ) {}

    //Push
    void push( int val ){
        
        Node* newNode = new Node( val );
        newNode ->next = top;
        top = newNode;
    }

    void pop(){
        if( top == nullptr ){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top -> next;
        delete temp;
    }

    int peek(){
        if( top == nullptr ){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top -> data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    ~Stack(){
        while( !isEmpty() ){
            pop();
        }
    }

    
};