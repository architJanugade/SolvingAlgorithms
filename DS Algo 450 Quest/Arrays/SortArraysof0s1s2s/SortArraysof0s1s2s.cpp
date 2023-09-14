#include <iostream>
#include <vector>

void swap(int * arr , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(int * arr , int size)
{
    int i  = 0 ;
    int j = size -1;
    int k = 0;

    while(j >= k)
    {
        if(arr[k] == 0)
        {
            swap(arr , k , i);
            k++;
            i++;
        }
        else if(arr[k] == 1)
        {
            k++;
        }
        else if(arr[k] == 2)
        {
            swap(arr , k , j);
            j--;
        }
    }
}
int main()
{
    int arr[]= { 0,2,1,2,0};
    sort012(arr , sizeof(arr)/sizeof(int));
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        std::cout<<arr[i] << " ";
    }
    

}


