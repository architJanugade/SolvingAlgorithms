#include <iostream>
#include <set>

int doUnion(int a[] , int m , int b[] , int n)
{
    std::set<int> s;
    if(m > n){
    for (int i = 0; i < m; i++)
    {
        /* code */
        s.insert(a[i]);

        if(i < n)
        {
            s.insert(b[i]);
        }

    }
    }
    if(m<n)
    {
        for (int i = 0; i < n; i++)
        {
            /* code */
            s.insert(b[i]);

        if(i < m)
        {
            s.insert(a[i]);
        }
        }
        
    }
    return s.size();
}


int main()
{
    int a[] = {85 ,25, 1, 32, 54, 6};
    int b[] = {85, 2};
    std::cout<<doUnion(a , sizeof(a)/sizeof(int) , b , sizeof(b)/sizeof(int));
}