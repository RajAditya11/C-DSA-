#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 50
using namespace std;


// P stands for Print
void printArray( const vector<int>& array ){
    for( int x : array ){
        cout<<x<<" ";
    }
    cout<<endl;
};

int main(){
    // C stands for Create
    vector<int> array( SIZE );

    // R stands for Read
    for( int i = 0 ; i < SIZE ; i++ ){
        cin>>array[i]; 
    }

    // U stands for Update
    for( int i = 0 ; i < SIZE ; i++ ){
        array[i] = array[i] * 2; 
    }

    // D stands for Delete
    array.clear();

    return 0;
}