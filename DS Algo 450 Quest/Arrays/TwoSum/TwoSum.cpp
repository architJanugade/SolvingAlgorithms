#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int FindIndex(vector<int> arr , int left , int right , int val )
{
    for(int i = left ; i < right ; i++)
    {
        if(arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

vector<int> TwoSum(vector<int> nums , int target)
{

    for(int i = 1 ; i < nums.size() ; i++)
    {
        int difference = target -nums[i] ;
        int index = FindIndex(nums , i+1 , nums.size() , difference);
        if(index != -1)
        {
            return {i , index};
        }
        
    }
    return {0,0};
}

int main()
{
    vector<int> nums = {3, 2, 4};

    vector<int> Twosum = TwoSum(nums , 6);
    for (int i = 0; i < Twosum.size(); i++)
    {
        cout<<Twosum[i]<<" ";
    }
    

}