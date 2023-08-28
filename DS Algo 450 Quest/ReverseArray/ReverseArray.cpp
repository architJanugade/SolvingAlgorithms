#include <iostream>
#include <vector>

using namespace std;
void swap(int * arr , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void ReverseArray(int * arr , int size)
{
    int i = 0 ;
    int j = size-1;
    while(i != j)
    {
        swap(arr , i , j);
        i++;
    }
}



int main()
{
    int arr[] = {1,2,3 ,4 ,5 , 6 , 7, 8, 9};
    ReverseArray(arr , sizeof(arr)/ sizeof(int));
    for(int num : arr)
    {
        std::cout<<num<<" ";
    }


}