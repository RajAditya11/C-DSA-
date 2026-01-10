#include <bits/stdc++.h>
using namespace std;

// pass by reference
bool checkPrime( int &number ){
    for( int i = 2 ; i < sqrt(number) ; i++ ){
        if( number % i == 0 ){
            cout<<number<<" is not Prime. "<<endl;
            return false;
        }
    }
    cout<<"Prime. "<<endl;
    return true;
}

bool checkEven ( int &number ){
    if( number%2 == 0 ){
        cout<<number<<" is Even. "<<endl;
        return true;
    }
    return false;
}

void printArray( vector<int> arr, int size){
    for( auto x : arr ){
        cout<<x<<" ";
    }   
    cout<<endl;

    return;
}

int searchElement( vector<int> arr , int size , int target ){
    for( int i : arr ){
        if( i == target ){
            return 1;
        }
    }
    return 0;
}

int binarySearch( vector<int> arr , int size , int target ){
    int left = 0;
    int right = size - 1;

    while( left <= right ){

        int mid = left + ( right - left ) / 2;

        if( arr[mid] == target ){
            return mid;
        }

        if( arr[mid] < target ){
            left = mid + 1;
        }

        else{
            right = mid - 1;
        }

    }

    return -1;
}

int main(){
    int number;
    cout<<"Enter number :";
    cin >> number;
  
    bool isPrime = checkPrime( number );

    if( !isPrime ){
        bool isEven = checkEven( number );
        if( isEven ){
            cout<<"If number is not prime then it is not even. Proved!";
        }
    }

    int size;
    cout<<"Enter array size :";
    cin>>size;

    vector<int> array(size);

    for( int i = 0 ; i < size ; i++ ){
        cin>>array[i];
    }

    printArray(array , size);


    int target;
    cout<<"Enter element to seach :";
    cin>>target;

    bool searchResult = searchElement( array , size , target ) == 1 ;

    if( searchResult){
        cout<<"Element found in array."<<endl;
    }else{
        cout<<"Element not found in array."<<endl;
    }


    //Optimal Search

    int index = binarySearch( array , size , target );

    if( index == -1){
        cout<<"Element not found in array."<<endl;
        return 0;
    }else{
        cout<<"Elemet found at index : "<<index<<endl;
    }

    return 0;

}