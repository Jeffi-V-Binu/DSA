class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long m = 0;
        for(const char a : s){
            if(a == '%'){
                continue;
            }
            else if(a == '*' ){
                if(m) --m;
            }
            else if(a == '#'){
                m*=2;
            }
            else{
                ++m;
            }
        }
        if(k + 1 > m) return '.';
        for(int i = n - 1 ; i >= 0; --i){
            char a = s[i];
            if(a == '%'){
                k = (m - 1) - k;
            }
            else if(a == '*'){
                ++m;
            }
            else if(a == '#'){
                if(k + 1 > (m + 1) / 2){
                    k -= (m / 2);
                }
                m = (m + 1) / 2;
            }
            else{
                if(m-1 == k) return s[i];
                --m;
            }
        }
        return '.';
    }
};