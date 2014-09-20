#ifndef ImplementstrStr_H
#define ImplementstrStr_H

#endif
class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		const int nlen = strlen(needle);
		const int hlen = strlen(haystack);
		int next[nlen];
		get_next(next,needle,nlen);

		int i = 0;
		int j = 0;
		while(i<hlen && j <nlen)
		{
			if(j == -1 || haystack[i] == needle[j])
			{
				i ++;
				j ++;
			}
			else
			{
				j = next[j];
			}
		}
		if(j >= nlen)
		{
			return haystack+i-nlen;
		}
		else
		{
			return NULL;
		}

	}
private:
	void get_next(int next[],char *needle,int len)
	{
		next[0] = -1;
		int i = 0;
		int j = -1;
		while(i<len)
		{
			if(j == -1 || needle[i] == needle[j])
			{
				i ++;
				j ++;
				if(needle[i]!=needle[j])
				{
					next[i] = j;
				}
				else
				{
					next[i] = next[j];
				}
			}
			else
			{
				j = next[j];
			}
		}
	}
};