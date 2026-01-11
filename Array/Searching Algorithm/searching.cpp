#include <bits/stdc++.h>
using namespace std;

pair<int, int> linearSearch(const vector<int> &arr, const int &key)
{
    for (int itr = 0; itr < arr.size(); itr++)
    {
        if (arr[itr] == key)
        {
            return {key, itr};
        }
    }
    return {key, -1};
}

pair<int, int> binarySearch(const vector<int> &arr, int first, int last, const int &key)
{
    if (arr.empty())
        return {key, -1};

    while (first <= last)
    {
        int mid = first + (last - first) / 2;

        if (arr[mid] == key)
        {
            return {key, mid};
        }
        else if (arr[mid] > key)
        {
            last = mid - 1;
        }else{
            first = mid + 1;
        }
    }
    return { key , -1 };
}

pair<int, int> jumpSearch(const vector<int>& arr , const int& key ){
    if( arr.empty() ) return { key , -1 };

    int size = arr.size();
    int step = sqrt( size );
    int prevBlockStart = 0;

    while ( prevBlockStart < size && arr[ min( step , size )-1 ] < key ){
        prevBlockStart = step;
        step += sqrt( size );
    }

    // linear search in the found block
    for( int j = prevBlockStart ; j < min( step , size ) ; j++ ){
        if( arr[j] == key ){
            return { key , j };
        }
    }
    return { key , -1 };
}

pair<int , int > interpolationSearch ( const vector<int>& arr , const int& key ){
    if( arr.empty() ) return { key , -1 };

    int low = 0;
    int high = arr.size() - 1;

    while ( low <= high && key >= arr[low] && key <= arr[high] ){
        if( low == high)  {
            if( arr[low] == key ) return { key , low };
            return { key , -1 };
        }
        
        int pos = low + ( double )( high - low ) / ( arr[high] - arr[low]) * ( key - arr[low] );

        if( arr[pos] == key ){
            return { key , pos };
        }

        if( arr[pos] < key ){
            low = pos + 1;
        }else{
            high = pos - 1;
        }
    }

    
    return { key , -1 };
}

pair<int , int > exponentialSearch ( const vector<int>& arr , const int& key ){
    if( arr.empty() ) return { key , -1 };

    if( arr[0] == key ) return { key , 0 };

    int i = 1;
    int size = arr.size();

    while ( i < size && arr[i] <= key ){
        i = i * 2;
    }

    return binarySearch( arr , i/2 , min( i , size - 1 ) , key );
}

pair<int , int > ternarySearch ( const vector<int>& arr , int left , int right , const int& key ){
    if( arr.empty() ) return { key , -1 };

    while ( left <= right ){
        int mid1 = left + ( right - left ) / 3;
        int mid2 = right - ( right - left ) / 3;

        if( arr[mid1] == key ){
            return { key , mid1 };
        }
        if( arr[mid2] == key ){
            return { key , mid2 };
        }

        if( key < arr[mid1] ){
            right = mid1 - 1;
        }else if( key > arr[mid2] ){
            left = mid2 + 1;
        }else{
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return { key , -1 };
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

    int valueToSearch;

    cout << "Enter value to search value with index : ";
    cin >> valueToSearch;

    // STL function to find the value in array in one line of code
    /*
    auto it = find( array.begin() , array.end() , valueToSearch);
    */

    pair<int, int> linearResult = linearSearch(array, valueToSearch);
    cout << "Value " << linearResult.first << " found at index " << linearResult.second << "using Linear Search Algorithm TC : [ O(n) ] " << endl;

    pair<int , int> binaryResult = binarySearch(array, 0, size - 1, valueToSearch);
    cout << "Value " << binaryResult.first << " found at index " << binaryResult.second << " using Binary Search Algorithm TC : [ O(log n) ] " << endl;

    pair<int , int> jumpResult = jumpSearch( array , valueToSearch );
    cout << "Value " << jumpResult.first << " found at index " << jumpResult.second << " using Jump Search Algorithm TC : [ O(√n) ] " << endl;
    
    pair<int , int> interpolationResult = interpolationSearch( array , valueToSearch );
    cout << "Value " << interpolationResult.first << " found at index " << interpolationResult.second << " using Interpolation Search Algorithm TC : [ O(log log n) ] " << endl;

    pair<int , int> exponentialResult = exponentialSearch( array , valueToSearch );
    cout << "Value " << exponentialResult.first << " found at index " << exponentialResult.second << " using Exponential Search Algorithm TC : [ O(log n) ] " << endl;

    pair<int , int> ternaryResult = ternarySearch( array , 0 , size - 1 , valueToSearch );
    cout << "Value " << ternaryResult.first << " found at index " << ternaryResult.second << " using Ternary Search Algorithm TC : [ O(log3 n) ] " << endl;

    return 0;
}