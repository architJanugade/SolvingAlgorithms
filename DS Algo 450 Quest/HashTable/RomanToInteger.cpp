#include <iostream>
#include <map>
#include <queue>
using namespace std;

// int romanToInt( string s)
// {
//     map<string , int> symbolMap;
//     symbolMap.insert(pair<string,int>("I" , 1));
//     symbolMap.insert(pair<string,int>("V" , 5));
//     symbolMap.insert(pair<string,int>("X" , 10));
//     symbolMap.insert(pair<string,int>("L" , 50));
//     symbolMap.insert(pair<string,int>("C" , 100));
//     symbolMap.insert(pair<string,int>("D" , 500));
//     symbolMap.insert(pair<string,int>("M" , 1000));
//     symbolMap.insert(pair<string,int>("IX" , 9));
//     symbolMap.insert(pair<string,int>("IV" , 4));
//     symbolMap.insert(pair<string,int>("XL" , 40));
//     symbolMap.insert(pair<string,int>("XC" , 90));
//     symbolMap.insert(pair<string,int>("CD" , 400));
//     symbolMap.insert(pair<string,int>("CM" , 900));
    
//     queue<char> previousRoman;
//     previousRoman.push(s[0]);
//     int final = 0;
//     for(int i = 1 ; i < s.size() ; i++)
//     {
//         if(!previousRoman.empty())
//         {
//             string popped =string(1,previousRoman.front());
//             previousRoman.pop();
//             string combined = popped + s[i];
//             if(symbolMap.count(combined) == 1)
//             {
//                 final += symbolMap[combined];
//             }
//             else
//             {
//                 previousRoman.push(s[i]);
//                 final+= symbolMap[popped];
//             }
//         }
//         else
//         {
//             previousRoman.push(s[i]);
//         }        
//     }
//     while(!previousRoman.empty())
//     {
//         string popped = string(1, previousRoman.front());
//         final += symbolMap[popped];
//         previousRoman.pop();
//     }

//     return final;
// }


int romanToInt( string s)
{
    map<char , int> symbolMap;
    symbolMap.insert(pair<char,int>('I' , 1));
    symbolMap.insert(pair<char,int>('V' , 5));
    symbolMap.insert(pair<char,int>('X' , 10));
    symbolMap.insert(pair<char,int>('L' , 50));
    symbolMap.insert(pair<char,int>('C' , 100));
    symbolMap.insert(pair<char,int>('D' , 500));
    symbolMap.insert(pair<char,int>('M' , 1000));

    

    int finalInt = 0;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(symbolMap[s[i]]< symbolMap[s[i+1]] )
        {
            finalInt -= symbolMap[s[i]];
        }
        else
        {
            finalInt += symbolMap[s[i]];
        }
    }
    

    return finalInt;
}


int main()
{
    string s = "MCMXCIV";
    cout<<romanToInt(s);
}