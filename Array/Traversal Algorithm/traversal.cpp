#include <bits/stdc++.h>
using namespace std;

void forwardTraversal( const vector<int>& arr ){
    for( int i = 0 ; i < arr.size() ; i++ ){
        if( arr[i] == arr[i]/1 ) continue;
    }
    cout<<"Foward Traversal Completed"<<endl;
}

void backwardTraversal( const vector<int>& arr ){
    for( int i = arr.size() - 1 ; i > 0 ; i-- ){
        if( arr[i] == arr[i]/1 ) continue;
    }
    cout<<"Backward Traversal Completed"<<endl;
}

void middleTraversalEnd( const vector<int>& arr , int start , int end ){
    int mid = start + ( end - start )/ 2;
    for( int i = mid ; i <= end ; i++ ){
        if( arr[i] == arr[i]/1 ) continue;
    }
    cout<<"Middle to End Traversal Completed"<<endl;
}

void middleTraversalStart( const vector<int>& arr , int start , int end ){
    int mid = start + ( end - start )/2;
    for( int i = mid ; i >= start ; i-- ){
        if( arr[i] == arr[i]/1 ) continue;
    }
    cout<<"Middle to Start Traversal Completed"<<endl;
}

int main(){

    vector<int> array = { 1, 2, 3, 4, 5 };

    forwardTraversal( array );
    backwardTraversal( array );
    middleTraversalEnd( array , 0 , array.size() - 1 );
    middleTraversalStart( array , 0 , array.size() - 1 );

    return 0;
}