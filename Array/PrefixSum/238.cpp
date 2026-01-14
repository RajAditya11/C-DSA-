#include<iostream>
#include<vector>

using namespace std;


//Optimal Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};


vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size(); // Size of nums
    vector<int> answer(
        size, 0); // Array of size equal to nums with all index storing 0.

    int totalProduct = 1,
        totalZero = 0; // first pass to get total number of zero &
                       // totalProduct of array exculde value zero
    for (int i = 0; i < size; i++)
    {
        if (nums[i] != 0)
            totalProduct *= nums[i];
        else
            totalZero++;
    } // VERIFIED

    if (totalZero >= 2)
        return answer;
    // if more than two zero simply return the initalized array values.

    // second pass to apply logical mathematics making sure if 1 zero than
    for (int i = 0; i < size; i++)
    {
        if (nums[i] != 0)
        {

            if (totalZero == 1)
                answer[i] = 0;
            else
                answer[i] = totalProduct / nums[i];
        }
        else
        {

            answer[i] = totalProduct;
        }
    }

    return answer;
}