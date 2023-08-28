#include<iostream>
#include<vector>

int duplicateNumber(std::vector<int>& nums)
{
    int total = 0;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        total += nums[i];
    }

    return total % nums.size();
}

int main()
{
    std::vector<int> arr = {1 ,3 ,4 ,2 ,2};
    std::cout<<duplicateNumber(arr);
}