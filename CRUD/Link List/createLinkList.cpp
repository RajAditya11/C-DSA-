// Using Class 
// Link List 

/*

Each Node [ data | next pointer ]

Real world use cases : 
1. Music Player : Next Song pointer
2. Browser : Previous/Next Page pointer
3. Undo-Redo Operations :  Stack using Linked List
4. OS process scheduling : Circular Linked List
5. HashMap Chaining : Collision Handling
6. LRU Cache : Doubly Linked List
7. Memory Management : Free Memory Blocks

*/


// Struture of Link list 

//    {HEAD} -> Node1 -> Node2 -> Node3 -> NULL {Tail}



// Most common way to create a Link List is by using struct

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

int main(){

    //manual Linking
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);


    return 0;
}