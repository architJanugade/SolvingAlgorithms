#include <iostream>
void swap(int * arr , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void MoveNegNumbers(int* arr , int size)
{
    int i =0;
    int j = size- 1;
    while(i < j)
    {
        if(arr[i] > 0  )
        {
            if(arr[j] < 0){
                swap(arr , i , j);
                i++;
                j--;
            }
            else
            {
                j--;
            }
        }
        if(arr[i] < 0)
            i++;
    }
    
}
int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    MoveNegNumbers(arr , sizeof(arr)/sizeof(int));
    for(int i = 0 ; i < sizeof(arr)/sizeof(int) ; i ++)
    {
        std::cout<<arr[i]<<" ";
    }


}