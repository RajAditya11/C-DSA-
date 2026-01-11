#include <bits/stdc++.h>
using namespace std;

void generatePrefixSum( const vector<int>& arr , vector<int>& prefixSum ){
    if( arr.empty() ) return;
    prefixSum[0] = arr[0];
    for( int i = 1; i < arr.size(); i++ ){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}

void printArray( const vector<int>& array ){
    for( auto i : array ){
        cout<< i <<" ";
    }cout<<'\n';
}


int main( ){
    int size;
    cout<<"Enter size of Array :";
    cin>>size;

    vector<int>array(size);

    cout<<"Enter Elements in Array :";
    for( int i = 0 ; i < size ; i++ ){
        cin>>array[i];
    }

    vector<int>prefixSum(size); 
    
    generatePrefixSum( array , prefixSum );
    

    cout<<"\nOriginal Array :";
    printArray( array );
    cout<<"\nPrefixSum Array :";
    printArray( prefixSum );

    return 0;
}