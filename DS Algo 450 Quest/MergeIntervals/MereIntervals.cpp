#include<iostream>
#include<vector>
#include <algorithm>
//[[1,3],[2,6],[8,10],[15,18]]
//[[1,6],[8,10],[15,18]]


std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    std::sort(intervals.begin() , intervals.end());
    std::vector<std::vector<int>> temp = {intervals[0]};
    int i = 0 ;
    int j = 1;

    while(j < intervals.size())
    {
        if(temp[i][0] < intervals[j][1] && intervals[j][0]< temp[i][1])
        {
            temp[i][0] = temp[i][0] <= intervals[j][0] ? temp[i][0] : intervals[j][0];
            temp[i][1] = temp[i][1] >= intervals[j][1] ? temp[i][1]: intervals[j][1];
            j++;
        }
        else
        {
            i++;
            temp.push_back(intervals[j]);
        }
    }

    return intervals;
}

int main()
{
    std::vector<std::vector<int>> arr = {{0,3},{2,6},{8,10},{0, 10}};
    std::vector<std::vector<int>> s = merge(arr);
    for(int i  = 0 ; i < s.size() ; i ++)
    {
        for(int j = 0 ; j < s[i].size() ; j++)
        {
            std::cout<<s[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}