#include <bits/stdc++.h>
using namespace std;
/*

Concept of Kadane Algorithm revolve around a situation of finding out the max/min  subarray and its sum. Where
you iterate every single index and decide either you can add or start a new subarray from that particular index.
and if the sum is less than 0 or in case of minimum > then we re initialize it as start from that particular index.

*/
pair<int , int> maxSubarraySum(const vector<int>& nums ){
    int maxSum = INT_MIN , currSum = 0;


    int start = 0 , end = 0;
    int tempStart = 0;

    for( int i = 0 ; i < nums.size() ; i++ ){
        if( currSum < 0 ){
            currSum = nums[i];
            tempStart = i;
        }else{
            currSum += nums[i];
        }

        if( currSum > maxSum ){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    return { start , end };
}


int main(){
    vector<int> arr = { -1 , 73 , -18 , 39 , 62 , -23 , -21 , 54 , 22 , -43 , -45 , 56 , 78 , 89 , 90 , -88 , -90  };

    pair<int , int > index = maxSubarraySum( arr );

    for( int i = index.first ; i <= index.second ; i++ ){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}