#include <iostream>
#include <vector>

using namespace std;

void MinMax(int arr[] , int size)
{
    int min = arr[0];
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] >max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    std::cout<<min<<" "<<max;


}

int main()
{
    int arr[] = {3,5,4,9,1};
    MinMax(arr , sizeof(arr)/sizeof(int));

}

