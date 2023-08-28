#include<iostream>
#include<vector>
#include <algorithm>
int getminIndex(std::vector<int>& nums , int s , int e)
{
    int min = s;
    for(int i = s ; i <= e ; i ++)
    {
        if(nums[i] < nums[min])
        {
            min = i;
        }
    }
    return min;
}

void nextPermutation(std::vector<int>& nums)
{
    int i  = nums.size()-1;
    if(nums.size() > 1){
    while(nums[i] <= nums[i-1] && i > 1)
    {
        i--;
        std::cout<<i<<" ";
    }
    i--;
    std::cout<<std::endl;
    if(i == 0 && nums[i] > nums[i+1])
    {
        std::reverse(nums.begin() , nums.end());
    }
    else
    {
         int k = getminIndex(nums , i + 1 , nums.size() - 1);
         std::cout<<k<<std::endl;
         std::swap(nums[i] , nums[k]);
         std::reverse(nums.begin() + i + 1 , nums.end());
        
    }
    }
    for (int j = 0; j < nums.size(); j++)
    {
            std::cout<<nums[j] << " ";
    }
    
}

int main()
{
    std::vector<int> arr = {1,3,2};
    nextPermutation(arr);
}