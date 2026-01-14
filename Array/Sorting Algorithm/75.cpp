#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[0];

        int i = low;
        int j = high;

        while (i < j)
        {

            while (nums[i] <= nums[pivot] && i <= high)
            {
                i++;
            }
            while (nums[j] >= nums[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }

        return pivot;
    }

    void quickSort(vector<int> &nums, int first, int last)
    {
        if (first < last)
        {
            int pivot = partition(nums, first, last);
            quickSort(nums, first, pivot - 1);
            quickSort(nums, pivot + 1, last);
        }
    }

    void sortColors(vector<int> &nums)
    {

        // Bubble Sort (n^2) Stable Concurrent Swap
        /*
        bool swapped = false;
        for( int i = 0 ; i < nums.size(); i++ ){

            for( int j = 0 ; j < nums.size() - i - 1; j++ ){

                if( nums[j] > nums[j+1] )
                   swap( nums[j] , nums[j+1]);
                   swapped = true;
            }
            if( !swapped ) break;
        }
        */

        // Selection Sort (n^2) Unstable minimum baised Swap
        /*
        for( int i = 0 ; i < nums.size() - 1 ; i++ ){
            int mini = i;

            for( int j = i+1 ; j < nums.size() ; j++ ){
                if( nums[j] < nums[mini] )
                   mini = j;
            }
            swap( nums[i] , nums[mini] );
        }
        */

        // Quick Sort  Unstable it follows Hoare Partition Algorithm
        /*
        quickSort( nums , 0 , nums.size()-1 );
        */

        //  Lomuto Partition Algorithm

        // Optimal Solution Dutch Flag Algorithm
        
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};