#ifndef PermutationsIandII_H
#define PermutationsIandII_H
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size() == 0 || num.size() == 1)
        {
            result.push_back(num);
            return result;
        }
        
        sort(num.begin(),num.end());
        do
        {
            result.push_back(num);
        }while(next_permutation(num));
        return result;
    }
private:
    bool next_permutation(vector<int> &num) {
        int head = -1;
        for(int i = num.size()-1; i >= 1; i --)
            if(num[i]>num[i-1])
            {
                head = i-1;
                break;
            }
            
        if(head == -1)
            return false;
            
        int change = -1;
        for(int i = num.size()-1; i >=0; i --)
            if(num[i]>num[head])
            {
                change = i;
                break;
            }
        if(change!=-1)
            swap(num[head],num[change]);
        reverse(num.begin()+head+1,num.end());
        return true;
    }
};

#endif