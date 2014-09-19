#ifndef DivideTwoIntegers_H
#define DivideTwoIntegers_H

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long i = 0;
		long long sum = 0;
		int flag = -1;
		if(dividend>0&&divisor>0) flag = 1;
		if(dividend<0&&divisor<0) flag = 1;

		long long div = dividend<0?-(long long)dividend:dividend;
		long long dis = divisor<0?-(long long)divisor:divisor;

		long long increase = 1;
		while(true)
		{
			if(sum+dis*increase >= div)
			{
				if(sum+dis*increase == div)
				{
					i+=increase;
					break;
				}
				if(increase == 1) break;
				else
				{
					increase = 1;
					continue;
				}
			}
			sum += dis*increase;
			i += increase;
			increase *= 2;
		}
		if(flag == -1) return -i;
		return i;
	}
};

#endif

