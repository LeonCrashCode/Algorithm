#include <iostream>
#include "SearchforaRange.h"
#include <vector>
using namespace std;

int main()
{
	int A[] = {1};
	Solution s;
	vector<int> result = s.searchRange(A,1,1);
	cout<<result[0]<<" "<<result[1]<<endl;
	system("pause");
	return 0;
}