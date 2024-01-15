#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &nums, int k, int left, int right)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == k)
        {
            return mid;
        }
        if (nums[right] == k)
        {
            return right;
        }
        if (nums[left] == k)
        {
            return left;
        }
        
        if (k < nums[mid])
            return BinarySearch(nums, k, left, mid);
        else
        {
            return BinarySearch(nums, k, mid + 1, right);
        }
    }

    return -1;
}

void FindIndexOfSmallestElement(vector<int> &nums  , int left , int right , int* smallestIndex)
{
    if(left >= right)
    {
        return;
    }    
    if(nums[left]< nums[*smallestIndex])
    {
        *smallestIndex = left;
    }
    if(nums[right] < nums[*smallestIndex])
    {
        *smallestIndex = right;
    }
    int mid = left + (right - left)/2;
    FindIndexOfSmallestElement(nums , left, mid , smallestIndex);
    FindIndexOfSmallestElement(nums , mid + 1 , right,smallestIndex);
}

int search(vector<int> &nums, int target)
{
    int small = 0;
    FindIndexOfSmallestElement(nums , 0 , nums.size()-1 , &small);
    if(target < nums[nums.size()-1] && target >= nums[small])
    {
        return BinarySearch(nums , target , small , nums.size()-1);
    }
    else if(target < nums[small-1] && target > nums[0])
    {
        return BinarySearch(nums , target , 0 , small-1);
    }
    return -1;
}


int main()
{
    vector<int> arr = {1,3};
    int small = 0;
    
    cout << search(arr ,0 );
}