#include <iostream>
#include <vector>
#include <string>
#include <utility>  

using namespace std; 

void swapElement(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapElement(arr[j], arr[j + 1]);
            }
        }
    }
}

// Brute Force
int largestElementBruteForce(const vector<int>& arr)
{
    vector<int> temp = arr;
    bubbleSort(temp);
    return temp.back();
}

// Optimal Solution
pair<int , int> largestElementOptimal(const vector<int>& arr)
{
    int maxSoFar = arr[0], index = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxSoFar)
        {
            index = i;
            maxSoFar = arr[i];
        }
    }
    return { maxSoFar , index };
}

int main()
{
    int size;
    cout << "Enter the size : ";
    cin >> size;

    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Which solution you want?\n1. BruteForce = 1\n2. Optimal = 2\n";
    int userinput;
    cin >> userinput;

    if (userinput == 1)
    {
        int ans = largestElementBruteForce(array);
        cout << "\nLargest Number : " << ans;
    }
    else if (userinput == 2)
    {
        pair<int,int> ans = largestElementOptimal(array);
        cout << "\nLargest Number : " << ans.first << " at index " << ans.second << "\n";
    }
    else
    {
        cout << "Invalid! Both case Trigger!";
        int ans = largestElementBruteForce(array);
        cout << "\nLargest Number : " << ans;
        pair<int,int> p = largestElementOptimal(array);
        cout << "\nLargest Number : " << p.first << " at index " << p.second << "\n";
    }

    return 0;
}