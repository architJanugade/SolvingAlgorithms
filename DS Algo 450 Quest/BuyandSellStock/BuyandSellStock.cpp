#include <iostream>
#include <vector>
#include<algorithm>

int min(std::vector<int>& arr , int _i ,  int j)
{
    int min = _i;
    for (int i = 0; i <= j; i++)
    {
        if(arr[i] <= arr[min])
        {
             min = i;
        }
    }
    return min;

}

int max(std::vector<int>& arr ,int _i , int j)
{
    int max = _i;
    for (int i = _i; i <= j; i++)
    {
        //std::cout<<"i: "<<arr[i]<<std::endl;
        if(arr[i] >= arr[max] )
        {
            max = i;
        }
    }
    return max;
    
}
int maxProfit(std::vector<int>& prices)
{
    int maxProfit = 0;
    int maxIndex = max(prices , 0 , prices.size() - 1);
    int minIdx = min(prices , 0 , maxIndex);
    while(maxIndex <= prices.size()-1)
    {
        maxIndex = max(prices , maxIndex + 1 , prices.size()-1);
        minIdx= min(prices ,minIdx , maxIndex );
        if(prices[maxIndex] - prices[minIdx] > maxProfit)
        {
            maxProfit = prices[maxIndex] - prices[minIdx];
        }
    }

    return maxProfit;
}
int main()
{
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout<<"hey what are you doing"<<std::endl;
    std::cout<<maxProfit(prices);
}