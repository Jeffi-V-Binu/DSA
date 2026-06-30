class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3 , 0);
        int n = s.size();
        int result = 0;
        if(n < 3) return 0;
        int i = 0;
        int j = 0;
        ++freq[s[j] - 'a'];
        while(j < n){
            while((j < n)&&(!freq[0] || !freq[1] || !freq[2])){
                ++j;
                if(j < n)++freq[s[j] - 'a'];
            }
            while(freq[0] && freq[1] && freq[2]){
                result += (n - j);
                --freq[s[i] - 'a'];
                ++i;
            }
        }
        return result;
    }
};