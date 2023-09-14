#include <iostream>
#include <algorithm>

int getMinDiff(int arr[], int n, int k) 
{   
    std::sort(arr , arr + n);
    int tempMin = arr[0];
    int tempMax = arr[n-1];
    
    int ans = tempMax- tempMin;


    for (int i = 1; i < n; i++)
    {
        if(arr[i] - k < 0)
            continue;

        tempMin = std::min(arr[0] + k , arr[i] -k);
        tempMax = std::max(arr[i] + k , arr[n-1] -k);

        ans = std::min(ans , tempMax - tempMin);

    }
    return ans;


}
int main()
{
    int arr[] = {5 ,5 ,8 ,6 ,4 ,10 ,3 ,8 ,9 ,10};
    std::cout<<getMinDiff(arr , sizeof(arr)/sizeof(int) , 5);
}