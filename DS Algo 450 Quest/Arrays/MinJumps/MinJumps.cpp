#include<iostream>
#include<algorithm>
int max(int * start , int * end)
{
    int jumps = 0;
    int max = *start+1;
    for(int *i = start + 1 ; i <= end ; i++)
    {
        if(max < *i)
        {
            max = *i;
        }
    }
    
    for(int * i = start + 1 ; i <= end ; i++)
    {
        jumps++;
        if(max == *i)
        {
            break;
        }
    }
    return jumps;
}


int minJumps(int arr[] , int n)
{
    int jumpGuy=0;
    int noOfJumps = 0;
    
    while(jumpGuy < n){

        if(jumpGuy + arr[jumpGuy] >= n)
        {
            int startJump = n - jumpGuy;
            //int jumps =max(&arr[jumpGuy] ,&arr[jumpGuy] + startJump );
            jumpGuy += startJump;
            //noOfJumps++;
        }
        else{
            int jumps =max(&arr[jumpGuy] ,&arr[jumpGuy] + arr[jumpGuy] );
            std::cout<<"per Jumps: "<<noOfJumps<<std::endl;
            jumpGuy += jumps;
        }
        if(noOfJumps+ 1 < n)
            noOfJumps ++;
        std::cout<<"perNo of Jumps: "<<noOfJumps<<std::endl;
    }

    return noOfJumps;
}



int main()
{
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
    std::cout<<minJumps(arr , sizeof(arr)/sizeof(int));
}