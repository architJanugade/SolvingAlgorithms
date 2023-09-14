#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int> res;
    int jCounter = c ;
    int iCounter = r -1;

    int totalj = 0;
    int totali = 0;
    int iLoop = 0;
    int jLoop = 0;
    int maxElements = r * c ;
    int currentElement = 0;
    int i =0 ;
    int j = -1;
    int jOffset = 1;
    int iOffset = 1;
    //res.push_back(matrix[i][j]);
    while(currentElement < maxElements)
    {
        while(totalj < jCounter)
        {
            j += jOffset;
            res.push_back(matrix[i][j]);
            totalj++;
            currentElement++;
        }        
        while(totali < iCounter )
        {
            i += iOffset;
            res.push_back(matrix[i][j]);
            totali++;
            currentElement++;
        }
        jCounter--;
        iCounter--;      
        totali = 0;
        totalj = 0;
        if(jOffset >0)
        {
            jOffset = -1;
        }
        else
        {
            jOffset = 1;
            
        
        }
        if(iOffset > 0)
        {
            iOffset = -1;
            
        }
        else
        {
            iOffset = 1;
            
        }
    }

    return res;    
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4} , {5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> res = spirallyTraverse(matrix  , 4 , 4);
    for (int i = 0; i < res.size(); i++)
    {
        
            cout <<  res[i]<<" ";
        
    }
    
    
}

//1  2  3  4
//5  6  7  8
//9  10 11 12
//13 14 15 16

