#include <iostream>

void swap(int * arr , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void RotateArray(int* arr , int n)
{
    int i  =0;
    int j = n-1;
    while(i != j)
    {
        swap(arr , i , j);
        i++;
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 4, 2, 1, 3};
    RotateArray(arr , sizeof(arr)/sizeof(int));
    for(int num : arr)
    {
        std::cout<<num<<" ";
    }
}