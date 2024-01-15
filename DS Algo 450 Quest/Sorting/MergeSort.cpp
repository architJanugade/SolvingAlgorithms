#include <iostream>
using namespace std;

void mergeArrays(int *arr,  int left,int mid , int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = arr[left + i];
    }
    for(int j = 0 ; j < subArrayTwo ; j++)
        rightArray[j] = arr[mid + 1 + j];

    
    int indexOfSubArrayOne  = 0;
    int indexOfSubArrayTwo  = 0;   
    int indexOfMergedArray = left;

    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo  < subArrayTwo)
    {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo ];
            indexOfSubArrayTwo ++;
        }
        indexOfMergedArray++;
    }
    while(indexOfSubArrayOne < subArrayOne)
    {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while(indexOfSubArrayTwo  < subArrayTwo)
    {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo ];
        indexOfSubArrayTwo ++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;    
    
}

void mergeSort(int *arr, int l , int h)
{
    if(l >= h)
    {
        return;
    }
    int m = l + (h - l) / 2;
    mergeSort(arr  , l , m);
    mergeSort(arr  , m+1 , h);
    mergeArrays(arr ,l , m , h );

}

int main()
{
    int arr[] = {
        2,
        3,
        1,
        5,
        4,
        6,
        7,
        10,
        31,
    };
    mergeSort(arr,    0 , sizeof(arr)/sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << endl << arr[i] << " ";
    }
}   