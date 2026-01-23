#include <iostream>
#include <vector>

#define SIZE 50
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    //Method 1: Range-based for loop
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    //Method 2: Traditional for loop with indices
    for( int i = 0; i < SIZE; i++ ){
        for( int j = 0; j < SIZE; j++ ){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //Method 3: Using size() method
    for( int i = 0; i < matrix.size(); i++ ){
        for( int j = 0; j < matrix[i].size(); j++ ){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    // Create a 2D vector (matrix) with SIZE x SIZE dimensions
    vector<vector<int>> matrix( SIZE , vector<int>( SIZE , 0) ); // it means a vector of size SIZE all initialized to 0 which is 
    //inside another vector of size SIZE all initialized to 0

    printMatrix(matrix);

    // No need to manually free memory, vector handles it automatically

    //THINGS for matrix 

    // Accessing elements
    matrix[0][0] = 1; // Set first element

    // Modifying elements
    matrix[1][1] = 5; // Set second element

    // Getting size
    cout << "Matrix size: " << matrix.size() << "x" << matrix[0].size() << endl;    
    // why matrix[0].size() ? because matrix is a vector of vectors so to get the size of the inner vector we use matrix[0].size()

    // Iterating through elements
    for( int i = 0; i < SIZE; i++ ){
        for( int j = 0; j < SIZE; j++ ){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Resizing the matrix
    matrix.resize(100, vector<int>(100, 0)); // Resize to 100x100, new elements initialized to 0

    // Note: Existing elements are preserved during resizing
    cout << "Resized Matrix size: " << matrix.size() << "x" << matrix[0].size() << endl;

    // Clearing the matrix
    matrix.clear(); // Now matrix is empty
    cout << "Cleared Matrix size: " << matrix.size() << endl;

    // No need to manually free memory, vector handles it automatically

    int arr[SIZE][SIZE] = {0}; // Static 2D array
    cout << "Static array size: " << sizeof(arr)/sizeof(arr[0]) << "x" << sizeof(arr[0])/sizeof(arr[0][0]) << endl;

    // Note: Static arrays have fixed size and cannot be resized like vectors

    // No need to manually free memory for static arrays

    // pass by reference to function
    vector<vector<int>> anotherMatrix( SIZE , vector<int>( SIZE , 0) );
    printMatrix(anotherMatrix);

    //for static array
    int staticArr[SIZE][SIZE] = {0};

    // why need to pas col size for static array ?
    // Because in C++, when passing a 2D array to a function, the size of all dimensions except the first must be known at compile time.
    // This is because the compiler needs to know how to calculate the memory offset for accessing elements
    // Hence, we need to specify the number of columns when passing a 2D array to a function.
    // Example function to print static array

    // Function to print static 2D array

    return 0;
}