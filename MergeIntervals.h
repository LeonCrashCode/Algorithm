#ifndef MergeIntervals_H
#define MergeIntervals_H

#include <vector>
#include "common.h"
using namespace std;

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        for(int i = 0; i < intervals.size(); i ++)
        {
            result = insert(result,intervals[i]);
        }
        return result;
    }
private:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if(intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }
        
        
        int start = -1;
        int end = -1;
        int minstart = newInterval.start;
        int maxend = newInterval.end;
        for(int i = 0; i < intervals.size(); i ++) {
            if(covered(newInterval,intervals[i]))
            {
                if(start == -1)
                {
                    start = i;
                    minstart = min(minstart,intervals[i].start);
                }
                end = i;
                maxend = max(maxend,intervals[i].end);
            }
            
        }
        
        if(start == -1 && end == -1)
        {
            if(intervals[0].start > maxend)
            {
                result.push_back(Interval(minstart,maxend));
                for(int i = 0; i < intervals.size(); i ++) result.push_back(intervals[i]);
            }
            else
            {
                bool flag = true;
                result.push_back(intervals[0]);
                for(int i = 1; i < intervals.size();)
                {
                    if(intervals[i].start > maxend && flag == true)
                    {
                        result.push_back(Interval(minstart,maxend));
                        flag = false;
                    }
                    else
                    {
                        result.push_back(intervals[i]);
                        i ++;
                    }
                }
                if(flag)
                {
                    result.push_back(Interval(minstart,maxend));
                }
            }
            return result;
        }
        
        bool flag = true;
        for(int i = 0; i < intervals.size(); i ++) {
            if(i<start || i > end) {
                result.push_back(intervals[i]);
            }
            else
            {
                if(flag){
                    result.push_back(Interval(minstart,maxend));
                    flag = false;
                }
            }
        }
        
        return result;
    }
    bool covered(Interval &a, Interval &b) {
        if(a.end<b.start) return false;
        if(a.start>b.end) return false;
        return true;
    }
};

#endif