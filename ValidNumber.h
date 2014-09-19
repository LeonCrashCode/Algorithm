#ifndef ValidNumber_H
#define ValidNumber_H

class Solution {
public:
	bool isNumber(const char *s) {
		if(*s == '\0') return false;

		//all the state
		//0 begin
		//1 this state comes from state 0 if sign is accepted
		//2 this state comes from state 0 if digit is accepted and in this states, digit can expand
		//3 this state comes from state 0 if point is accepted

		//4 this state express a legual dimecial number
		//5 this state comes from state 4 if e/E is accepted
		//6 this state comes from state 5 if sign is accepted and follows e/E and in this state, digit can expand
		//7 this state comes from state 5 if there is no sign followed and digit is directly accepted, digit can expand
		//8 end

		//action
		//0 number
		//1 e E
		//2 .
		//3 space
		//4 - +

		enum ActionType{
			NUMBER,
			EXPONENT,
			POINT,
			SPACE,
			SIGN
		};

		int transfer[9][5] = {
			{ 2,-1, 3, 0, 1},
			{ 2,-1, 3,-1,-1},
			{ 2, 5, 4, 8,-1},
			{ 4,-1,-1,-1,-1},
			{ 4, 5,-1, 8,-1},
			{ 7,-1,-1,-1, 6},
			{ 7,-1,-1,-1,-1},
			{ 7,-1,-1, 8,-1},
			{-1,-1,-1, 8,-1}
		};
		int state = 0;
		while(*s!='\0')
		{
			if((*s >'9' || *s < '0') && *s!='e' && *s!='E' && *s!='.' && *s!=' ' && *s!='-' && *s!='+') return false;
			if(*s<= '9' && *s >= '0')
				state = transfer[state][NUMBER];
			else if(*s == 'e' || *s == 'E')
				state = transfer[state][EXPONENT];
			else if(*s == '.')
				state = transfer[state][POINT];
			else if(*s == ' ')
				state = transfer[state][SPACE];
			else if(*s == '-' || *s == '+')
				state = transfer[state][SIGN];
			++s;
			if(state == -1) return false; 
		}
		if(state == 4 || state == 8 || state == 2 || state == 7) 
			return true;
		return false;
	}
};
#endif