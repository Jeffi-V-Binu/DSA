class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long m = 0;
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == '%'){
                continue;
            }
            else if(s[i] == '*' ){
                if(m > 0 ) --m;
            }
            else if(s[i] == '#'){
                m*=2;
            }
            else{
                ++m;
            }
        }
        if(m <= k) return '.';
        for(int i = n - 1 ; i >= 0; --i){
            if(s[i] == '%'){
                k = (m - 1) - k;
            }
            else if(s[i] == '*'){
                ++m;
            }
            else if(s[i] == '#'){
                if(k + 1 > (m + 1) / 2){
                    k -= (m / 2);
                }
                m = (m + 1) / 2;
            }
            else{
                --m;
                if(m == k) return s[i];
            }
        }
        return '.';
    }
};