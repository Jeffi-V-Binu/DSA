class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int j = 0;
        char flag = 1;
        while(j < n && s[j] == ' ') ++j;
        if(s[j] == '-'){
            flag = -1;
            ++j;
        }
        else if(s[j] == '+') ++j;
        int digit;
        while(j < n){
            if(s[j] >= '0' && s[j] <= '9')digit = s[j] - '0';
            else break;
            if(flag == 1){if(i > INT_MAX/10 || (i == INT_MAX/10 && digit > 7 )) return INT_MAX;}
            else if(i > INT_MAX/10 || (i == INT_MAX/10 && digit > 7 )) return INT_MIN;
            i = i * 10 + digit;
            ++j;
        }
        return i * flag;
    }
};