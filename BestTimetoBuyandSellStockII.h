#ifndef BestTimetoBuyandSellStockII_H
#define BestTimetoBuyandSellStockII_H
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {

		if(prices.size() < 2) return 0;

		vector<int> left(prices.size(),0);
		vector<int> right(prices.size(),0);

		int Min = prices[0];
		for(int i = 1; i < prices.size(); i ++)
		{
			Min = min(Min,prices[i]);
			left[i] = max(left[i-1],prices[i]-Min);
		}
		int Max = prices[prices.size()-1];
		for(int i = prices.size()-2; i >=0; i --)
		{
			Max = max(Max,prices[i]);
			right[i] = max(right[i+1],Max-prices[i]);
		}
		int result = -10000000;
		for(int i = 0; i < prices.size(); i ++)
		{
			result = max(result,left[i]+right[i]);
		}
		if(result < 0) result = 0;
		return result;
	}
};
#endif
