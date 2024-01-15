#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    int j =0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            k++;
            nums[j] = nums[i];
            j++;
        }
    }
    return k;
}

int main()
{
}