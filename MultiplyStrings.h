#ifndef MultiplyStrings_H
#define MultiplyStrings_H

#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size()) swap(num1,num2);
        
        string result="";
        for(int i = num2.size()-1; i >=0; i --)
        {
            string tmp = multiply_one(num1,num2[i]-'0');
            for(int j = 0; j < num2.size()-1-i; j ++)
                tmp+='0';
            result = plus(result,tmp);
        }
        
        string true_result = "";
        bool flag = false;
        for(int i = 0; i < result.size(); i ++)
        {
            
            if(result[i] == '0')
            {
                if(flag == false)
                    continue;
                else
                    true_result += result[i];
            }
            else
            {
                flag = true;
                true_result += result[i];
            }
        }
        if(true_result.size() == 0) return "0";
        return true_result;
    }
private:
    string plus(string num1, string num2) {
        if(num1.size() == 0)
            return num2;
        if(num2.size() == 0)
            return num1;
        int i = num1.size()-1;
        int j = num2.size()-1;
        
        string result = "";
        int add = 0;
        while(i>=0 && j>=0)
        {
            result.insert(result.begin(),((num1[i]-'0'+num2[j]-'0'+add)%10)+'0');
            add = (num1[i]-'0'+num2[j]-'0'+add)/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            result.insert(result.begin(),((num1[i]-'0'+add)%10)+'0');
            add = (num1[i]-'0'+add)/10;
            i --;
        }
        while(j>=0)
        {
            result.insert(result.begin(),((num2[j]-'0'+add)%10)+'0');
            add = (num2[j]-'0'+add)/10;
            j --;
        }
        if(add>0)
        {
            result.insert(result.begin(),'1');
        }
        return result;
    }
    string multiply_one(string num1, int c) {
        int add = 0;
        string result = "";
        for(int i = num1.size()-1; i >= 0; i --)
        {
            result.insert(result.begin(),(((num1[i]-'0')*c+add)%10)+'0');
            add = ((num1[i]-'0')*c+add)/10;
        }
        if(add>0)
        {
            result.insert(result.begin(),add+'0');
        }
        return result;
    }
    
};

#endif