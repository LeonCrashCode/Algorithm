#ifndef WildcardMatching_H
#define WildcardMatching_H

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star = NULL;
        const char *res = NULL;
        while(*s!='\0')
        {
            if(*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            if(*p == '*')
            {
                while(*p=='*') p++;
                star = p-1;
                res = s;
                continue;
            }
            if(star!=NULL)
            {
                p = star+1;
                s = res+1;
                res++;
                continue;
            }
            return false;
        }
        while(*p=='*')p++;
        if(*p!='\0') return false;
        return true;
    }
};

#endif