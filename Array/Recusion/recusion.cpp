#include <bits/stdc++.h>
using namespace std;

// Print n times with recursion.  && Linearly from 1 to N;
void printTimesN( int number ){
    if( number <= 0 ) return;
    cout<<number<<" ";
    printTimesN( --number);
}

// Print From N to 1                ( Recursion )
void printNTo1( int number ){
    if( number <= 0 ) return;
    cout<<number<<" ";
    printTimesN( --number);
}

// Print from N to 1                ( Recursion & BackTracking )
void printNTo1( int number ){
    if( number <= 0 ) return;
    printTimesN( --number);
    cout<<number<<" ";
}


int main(){

    int number;
    cout<<"Enter Number :";
    cin>>number;

    printTimesN ( number);
    printNTo1( number );


    return 0;
}