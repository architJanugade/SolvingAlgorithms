#include<iostream>

void swap(int * arr , int i  , int j)
{
    int temp = arr[i];
    arr[i ]= arr[j];
    arr[j] = temp;
}
void swapBetarrays(int * arr ,int * arr2, int i , int j)
{
    int temp = arr[i];
    arr[i] = arr2[j];
    arr2[j] = temp;
}

void goToOrriginalPosition(int * arr , int k)
{
    int l = k-1;
    if(arr[k]<arr[l])
    {
        swap(arr , k , k-1);
        goToOrriginalPosition(arr , l);
    }
}
void MergeArrays(int *arr , int* arr2 , int a , int b)
{
    int i = a;
    int j = b;
    if(j>=0){
    if(arr[i] > arr2[j])
    {
        swapBetarrays(arr , arr2 , i , j);
        goToOrriginalPosition(arr ,i);
        j--;
        MergeArrays(arr , arr2 , i , j);
    }
    else
    {
        j--;
        MergeArrays(arr , arr2 , i , j);
    }
    }


}
int main()
{
    int arr[] = {1,5, 9 , 10 , 15 , 20};
    int arr2[] = {2,3,8,13};
    int size1 = sizeof(arr)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);
    
    MergeArrays(arr , arr2 , size1-1 , size2 - 1);

    for(int i  = 0 ; i < size1 ;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i  = 0 ; i < size2 ;i++)
    {
        std::cout<<arr2[i]<<" ";
    }
}