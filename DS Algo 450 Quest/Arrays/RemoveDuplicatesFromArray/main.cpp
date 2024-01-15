#include <iostream>
#include <vector>

using namespace std;



int removeDuplicates(vector<int> &nums)
{
    int k = 0;
    int* uniqueList = new int[nums.size()];
    int l = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i + 1;
        k++;
        uniqueList[l] = nums[i];
        l++;
        while (j < nums.size() && nums[j] == nums[i])
        {            
            j++;
            
        }
        i = j - 1;
    }
    
    int i = 0;
    while(i < k)
    {
        nums[i] = uniqueList[i];
        i++;
    }
    
    return k;
}

int main()
{
    vector<int> nums = {1,1,2};
    cout<<removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    
}

//0,0,1,1,1,2,2,3,3,4