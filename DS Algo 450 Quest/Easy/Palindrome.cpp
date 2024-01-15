#include <iostream>
#include <string>
using namespace std;

string reverseStr(string S,int n, int i)
{
        
  if(n<=i){return S;}
  swap(S[i],S[n]);
  return reverseStr(S,n-1,i+1);

  return S;
 
}
bool isPalindrome(int x)
{
    int n, digit, rev = 0;
    n = x;
    do
     {
         digit = x % 10;
         rev = (rev * 10) + digit;
         x = x / 10;
     } while (x != 0);
     return n==rev;
}

int main()
{
    int x = -121;
    cout<<isPalindrome(x);

}