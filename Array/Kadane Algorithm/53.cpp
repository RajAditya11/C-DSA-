#include <bits/stdc++.h>
using namespace std;



int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int currSum = nums[0];

        for( int i = 1 ; i < nums.size() ; i++ ){
            // if( nums[i] > currSum + nums[i] ){
            //     currSum = nums[i];
            // }else{
            //     currSum += nums[i];
            // }
            currSum = max( nums[i] , currSum + nums[i] );
            maxSoFar = max( maxSoFar , currSum );
        }

        return maxSoFar;
    }

int main( ){

    vector<int> arr = {1 , -1 , 2 , 3 , 4 , 5 , 6 , - 7 , 8 , 1 , -2 , -6 , 9 , 1 , -2 , -9 , -11 , -43 , -22 };

    int maxSubarraySum = maxSubArray( arr );

    cout<<maxSubarraySum;

    return 0;
}