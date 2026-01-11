#include <bits/stdc++.h>
using namespace std;

// SELECTION SORTING ALGORITHM

void selectionSort( vector<int>& arr ){
    int n = arr.size();
    for( int i = 0 ; i < n - 1 ; i++ ){
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j++ ){
            if( arr[j] < arr[minIndex] ){
                minIndex = j;
            }
        }
        swap( arr[i] , arr[minIndex] );
    }
}

// QUICK SORTING ALGORITHM

int partitionIndex(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        while (j >= low && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int partition = partitionIndex(arr, low, high);

        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}


// HEAP SORTING ALGORITHM

void heapify( vector<int>& arr , int n , int i ){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if( leftChild < n && arr[leftChild] > arr[largest] ){
        largest = leftChild;
    }
    if( rightChild < n && arr[rightChild] > arr[largest] ){
        largest = rightChild;
    }

    if( largest != i ){
        swap( arr[i] , arr[largest] );
        heapify( arr , n , largest );
    }
}

void heapSort( vector<int>& arr ){
    int n = arr.size();

    for( int i = n / 2 - 1 ; i >= 0 ; i-- ){
        heapify( arr , n , i );
    }

    for( int i = n - 1 ; i >= 0 ; i-- ){
        swap( arr[0] , arr[i] );
        heapify( arr , i , 0 );
    }
}

void printArray( const vector<int>& arr ){
    for( const int& element : arr ){
        cout << element << " ";
    }
    cout << endl;
}


// Driver code
int main()
{

    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> array(size);

    cout << "Enter elements of array :";

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    vector<int> array1 = array;
    vector<int> array2 = array;

    selectionSort( array1 );
    cout << "Array after Selection Sort: ";
    printArray( array1 );

    quickSort( array2 , 0 , size - 1 );
    cout << "Array after Quick Sort: ";
    printArray( array2 );

    heapSort( array );
    cout << "Array after Heap Sort: ";
    printArray( array );


    return 0;
}