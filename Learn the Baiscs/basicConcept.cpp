#include <bits/stdc++.h>
using namespace std;

int totalDigit( int number ){
    int count = 0;
    if( number/10 == 0  ) return 1;
    while( number != 0 ){
        number = number / 10;
        count++;
    }
    return count;
}

int inverse( int number ){
    int reverseNumber = 0 , temp = number;

    while( temp != 0 ){
        int lastDigit = temp%10;
        reverseNumber = reverseNumber * 10 + lastDigit;
        temp = temp / 10;
    }
    return reverseNumber;
}

bool checkPalindrome( int &number ){
    int reversedNumber = inverse( number );
    return ( number == reversedNumber );
}

int gcd( int x , int y ){
    if( y == 0 ) return x;
    return gcd( y , x%y );
}

int hcf(int a , int b ){
    return gcd( a , b );
}

int power( int base , int exponent ){
    int result = 1;
    if( exponent == 0 ) return 1;
    
    while( exponent != 0 ){
        result = result * base;
        exponent--;
    }
    return result;
}

int isArmstrong ( int number ){
    int sum = 0 , temp = number;
    int digits = totalDigit( number );

    while ( temp != 0 ){
        int lastDigit = temp % 10 ;
        sum = sum + power( lastDigit , digits );
        temp = temp / 10;
    } 
    if( sum == number ) return 1;
    else return 0;
}

void printDivisors( int number ){
    cout<<"Divisors : "<<1<<" , ";
    for( int i = 1 ; i < number ; i++ ){
        if( number % i == 0 ){
            cout<<i<<" , ";
        }cout<<"."<<endl;
    }
    return;
}

bool checkPrime( int number ){
    if( number <=1 ) return false;
    
    for( int i = 2 ; i <= sqrt(number) ; i++ ){
        if( number % i == 0 ){
            return false;
        }
    }
    return true;
}

int main(){
    int first , second ;

    cout<<"Enter First :";
    cin>>first;
    cout<<"Enter Second :";
    cin>>second;

    cout<<"Total Digit : "<<totalDigit( first )<<endl;
    cout<<"Inverse : "<<inverse( first )<<endl;
    if( checkPalindrome( first ) ){
        cout<<"Palindrome Number"<<endl;
    }
    else{
        cout<<"Not a Palindrome Number"<<endl;
    }
    cout<<"GCD : "<<gcd( first , second )<<endl;
    cout<<"HCF : "<<hcf( first , second )<<endl;

    if( isArmstrong( first ) == 1 ){
        cout<<"Armstrong Number"<<endl;
    }
    else{
        cout<<"Not an Armstrong Number"<<endl;
    }

    printDivisors( first );
    bool isPrime = checkPrime( first );

    if( isPrime ){
        cout<<"Prime Number"<<endl;
    }
    else{
        cout<<"Not a Prime Number"<<endl;
    }


    return 0;
}