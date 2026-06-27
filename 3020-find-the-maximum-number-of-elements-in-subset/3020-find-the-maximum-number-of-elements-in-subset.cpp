class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long track;
        const int maxval = 31623;
        int length = 0;
        int maxlen = 1;
        int mi = maxval;
        int ma = 0;
        int n = nums.size();
        int len1 = 0;
        bitset<maxval> frequency , freq2 , largsqs;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 1) ++len1;
            if(nums[i] < maxval){
                if(frequency[nums[i]] == 0){
                    frequency[nums[i]] = 1;
                }
                else{
                    freq2[nums[i]] = 1;
                    ma = max(ma , nums[i]);
                    mi = min(mi , nums[i]);
                }
            }
            else{
                int x = sqrt(nums[i]);
                if(x * x == nums[i]){
                    largsqs[x] = 1;
                }
            }
        }
        for(int i = mi ; i <= ma ; ++i){
            track = i;
            if(track == 1) continue;
            while(track < maxval && freq2[track]){
                length += 2;
                track *= track;
            }
            if(track < maxval && frequency[track]) ++length;
            else if(track >= maxval){
                int d = sqrt(track);
                if(largsqs[d]) ++length;
                else --length;
            }
            else --length;
            maxlen = max(maxlen , length);
            length = 0;
        }
        if(len1 % 2 == 0) --len1;
        maxlen = max(maxlen , len1);
        return maxlen;
    }
};