// Data Structures and Algorithms in C++
// ways to create an array

#include <iostream>
#include <array>
#include <vector>
#include <algorithm> // for std::fill
#include <cstring>   // for memcpy

using namespace std;

int main(){

    int arr[5]; // uninitialized simple array with fixed size limitation


    array<int , 5> array; // standard template library array with fixed size limitation and advantages over simple array are 
    // 1. array knows its own size
    // 2. array supports copy assignment
    array.fill(0); // initialize all elements to 0

  //   arr.fill(0);  This line will cause a compilation error because built-in arrays do not have member functions

    vector<int> copyArray;
    vector<int> vectorArray(5);    // dynamic array with no size limitation and supports various functionalities
    // vectorArray can be resized dynamically using vectorArray.resize(new_size);
    // vectorArray also supports various member functions like push_back, pop_back, etc.
    // vectorArray elements are initialized to 0 by default
    // vectorArray.fill(0);  This line will cause a compilation error because std::vector does not have a fill member function
    // instead we can use std::fill algorithm
    fill(vectorArray.begin(), vectorArray.end(), 0); // initialize all elements to 0
    // Time complexity of fill algorithm is O(n)

    vectorArray.push_back(10); // adding an element to the end of the vector
    vectorArray.pop_back(); // removing the last element of the vector\


    vectorArray.clear(); // removing all elements from the vector
    vectorArray.shrink_to_fit(); // reducing the capacity of the vector to fit its size
    vectorArray.reserve(20); // reserving space for 20 elements in the vector
    // Time complexity of reserve is O(n) in case of reallocation, otherwise O(1)
    vectorArray.assign(5, 1); // assigning 5 elements with value 1 to the vector
    // Time complexity of assign is O(n)

    vectorArray.insert(vectorArray.begin() + 2, 99); // inserting an element at index 2 ,  based indexing starts from 0
    // Time complexity of insert is O(n)

    vectorArray.erase(vectorArray.begin() + 3); // erasing an element at index 3
    // Time complexity of erase is O(n)

    vectorArray.swap(copyArray); // swapping the contents of two vectors
    // Time complexity of swap is O(1) by simply swapping the internal pointers

    // IMPT STL OPS

    sort( vectorArray.begin(), vectorArray.end() ); // sorting the vector
    // Time complexity of sort is O(n log n) as it uses IntroSort algorithm internally which is 
    // a hybrid of QuickSort, HeapSort and InsertionSort but it is not a stable sort

    reverse( vectorArray.begin(), vectorArray.end() ); // reversing the vector
    // Time complexity of reverse is O(n) by swapping elements from start and end two pointers approach

    find( vectorArray.begin(), vectorArray.end(), 99 ); // finding an element in the vector
    // Time complexity of find is O(n) as it does a linear search

    binary_search( vectorArray.begin(), vectorArray.end(), 99 ); // binary search for an element in the vector
    // Time complexity of binary_search is O(log n) but the vector must be sorted before using binary_search    

    // Other useful operations

    // accessing elements
    int firstElement = vectorArray.front(); // accessing the first element

    // accessing the last element
    int lastElement = vectorArray.back(); // accessing the last element

    // getting the size of the vector
    size_t size = vectorArray.size(); // getting the number of elements in the vector

    // getting the capacity of the vector
    size_t capacity = vectorArray.capacity(); // getting the total allocated space in the vector

    // checking if the vector is empty
    bool isEmpty = vectorArray.empty(); // checking if the vector is empty

    // resizing the vector
    vectorArray.resize(10); // resizing the vector to hold 10 elements

    // copying vectors
    copyArray = vectorArray; // copy assignment of vectors
    // Time complexity of copy assignment is O(n)

    // copying elements from vector to simple array
    memcpy( arr , vectorArray.data(), 5 * sizeof(int) ); // Time complexity of memcpy is O(n); 5 means copying first 5 elements

    // also how it is dynamic in nature as cpacity increases automatically when more elements are added beyond current capacity
    // ex when a vector array is created lets say it has 5 size and 15 capacity
    // when we add more elements beyond 15 capacity it will automatically increase its capacity to accommodate more elements
    // the increase in capacity is generally done by doubling the current capacity
    // which means now the new capacity will be 30 





    vectorArray.resize(10); // resizing the vector to hold 10 elements
    copyArray = vectorArray; // copy assignment of vectors
    // Time complexity of copy assignment is O(n)

    memcpy( arr , vectorArray.data(), 5 * sizeof(int) ); // copying elements from vector to simple array
    // Time complexity of memcpy is O(n);

    return 0;
}