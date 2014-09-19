#ifndef LengthofLastWord_H
#define LengthofLastWord_H

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int start = -1;
		int end = 0;
		int index = 0;
		bool pre_space = true;
		while(*s!='\0')
		{
			if(*s != ' ')
			{
				if(pre_space)
				{
					start = index;
					pre_space =false;
				}
			}
			else
			{
				if(pre_space==false)
				{
					end = index;
					pre_space = true;
				}
			}
			index+=1;
			++s;
		}
		if(start == -1) return 0;
		if(pre_space==false)
		{
			return index - start;
		}
		else
		{
			return end - start;
		}
	}
};

#endif