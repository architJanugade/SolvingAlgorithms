#include <iostream>
#include <algorithm>
#include <vector>

long long int merge(long long arr[], long long l, long long m, long long r)
    {
        long long int count=0;
        long long int left=l;
        long long int right=m+1;
        std::vector<long long int>v;
        while(left<=m && right<=r)
        {
            if(arr[left]<=arr[right])
            {
                v.push_back(arr[left]);
                left++;
            }
            
            else{
                v.push_back(arr[right]);
                count+=(m-left+1);
                right++;
            }
        }
        
        while(left<=m)
        {
            v.push_back(arr[left]);
            left++;
        }
        
        while(right<=r)
        {
            v.push_back(arr[right]);
            right++;
        }
        
        for(int i=l;i<=r;i++)
        {
            arr[i] = v[i-l];
        }
        
        return count;
    }
    // public:
    long long int mergeSort(long long arr[], long long l, long long r)
    {
        long long int count=0;
        if(l>=r)
        {
            return count;
        }
        
        long long int mid = (l+r)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
        return count;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr,0,n-1);
    }
int main()
{
    long long arr[] = {2 , 4, 1, 3, 5};
    std::cout<< inversionCount(arr , sizeof(arr)/sizeof(long long));
}

//2,4,1,3,5
//1,2,3,4,5