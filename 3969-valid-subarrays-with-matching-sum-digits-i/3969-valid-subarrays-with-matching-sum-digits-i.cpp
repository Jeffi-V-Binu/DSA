class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> sums(n , 0);
        int count = 0;
        sums[0] = nums[0];
        int a = nums[0] % 10;
        long long b = nums[0];
        while(b >= 10) b /= 10;
        if(a == x && b == x) ++count;
        for(int i = 1 ; i < n ; ++i){
            sums[i] = nums[i] + sums[i - 1];
            a = sums[i] % 10;
            b = sums[i];
            while(b >= 10) b /= 10;
            if(a == x && b == x) ++count;
        }
        for(int i = 0 ; i < n - 1 ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                long long sumss = (sums[j] -  sums[i]);
                a = sumss % 10;
                b = sumss;
                while(b >= 10) b /= 10;
                if(a == x && b == x) ++count;
            }
        }
        return count;
    }
};
