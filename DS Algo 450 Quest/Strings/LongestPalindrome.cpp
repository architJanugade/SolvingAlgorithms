#include <iostream>
#include <algorithm>

using namespace std;

string reverseStr(string S,int n, int i)
{
        
  if(n<=i){return S;}
  swap(S[i],S[n]);
  return reverseStr(S,n-1,i+1);

  return S;
 
}

bool isPalindrome(string S , int left , int right)
{
    string substring = S.substr(left,right + 1);
    string reverse =substring;
    reverse = reverseStr(reverse, right , left);
    if(reverse.compare(substring) == 0)
        return true;
    else
        return false;

}

string LongestPalindrome(string S)
{
    string longest = "";
    for(int i = 0 ; i < S.size(); i++)
    {
        for(int j = S.size()-1; j > i;j--)
        {
            if(isPalindrome(S , i , j))
            {
                if(longest.size() <= S.substr(i , j+1).size())
                    longest = S.substr( i , j+1);
            }
        }
    }
    
    
    
    return longest;
}


int main()
{
    string S = "aaabbaa";
    cout<<LongestPalindrome(S);
}