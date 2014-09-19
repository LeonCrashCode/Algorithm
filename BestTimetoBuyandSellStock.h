#ifndef BestTimetoBuyandSellStock_H
#define BestTimetoBuyandSellStock_H

#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if(prices.size()<=1) return 0;
		int cur_min = prices[0];
		int max_diverse = -10000000;
		for(int i = 1; i < prices.size(); i ++)
		{
			max_diverse = max(prices[i]-cur_min,max_diverse);
			cur_min = min(cur_min,prices[i]);
		}
		if(max_diverse<0) max_diverse = 0;
		return max_diverse;
	}
};
#endif