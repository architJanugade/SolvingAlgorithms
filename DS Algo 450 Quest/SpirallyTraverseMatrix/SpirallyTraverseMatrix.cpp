#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    int currentTrav = 0;
    int totalTrav = r*c;
    int firsti = c-1;
    int lastj = r-1;
    int i =0;
    int j = 0;
    vector<int> ans;
    while(currentTrav < totalTrav)
    {
        //currentTrav++;
        while(j < lastj)
        {
            ans.push_back(matrix[i][j]);
            j++;
        }
        lastj = j;
        while(i < firsti)
        {
            ans.push_back(matrix[i][j]);
            i++;
        }

    }
    
}

int main()
{

}

//1  2  3  4
//5  6  7  8
//9  10 11 12
//13 14 16 17