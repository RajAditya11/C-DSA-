#include <bits/stdc++.h>
using namespace std;

pair<int , int> minSubarraySum(const vector<int>& nums) {

    int minSum = INT_MAX;
    int currMin = 0;

    int start = 0, end = 0;
    int tempStart = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(currMin > 0) {
            currMin = nums[i];
            tempStart = i;
        } else {
            currMin += nums[i];
        }

        if(currMin < minSum) {
            minSum = currMin;
            start = tempStart;
            end = i;
        }
    }

    return {start, end};
}



int main(){
    vector<int> arr = { -1 , 73 , -18 , 39 , 62 , -23 , -21 , 54 , 22 , -43 , -45 , 56 , 78 , 89 , 90 , -88 , -90  };

    pair<int , int > index = minSubarraySum( arr );

    for( int i = index.first ; i <= index.second ; i++ ){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}