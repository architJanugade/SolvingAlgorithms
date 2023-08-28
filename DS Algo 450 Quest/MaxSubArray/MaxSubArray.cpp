#include<iostream>
long long maxSubArray(int arr[] , int n)
{
    long long max = arr[0];
    long long sum =0;
    for(int i = 0 ; i < n ; i++)
    {
        // if(arr[i] > max)
        // {
        //     if(max < sum || sum < 0){
        //         max = arr[i];
        //         sum = 0;
        //     }
        // }
        // sum+= arr[i];
        //     if(sum > max)
        //     {
        //         max = sum;
        //     }
        sum += arr[i];
        if(sum < 0)
        {
            if(sum > max)
            {
                max = sum;
            }
            sum = 0;
        }
        else if(sum > max)
        {
            max = sum;
        }

        
    }
    return max;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<maxSubArray(arr , sizeof(arr)/sizeof(int));
}