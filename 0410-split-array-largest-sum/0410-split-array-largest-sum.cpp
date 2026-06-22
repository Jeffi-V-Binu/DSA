class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0; 
        int maxval = 0;
        int n = nums.size();
        for(int i = 0; i < n ; ++i ){
            int v = nums[i];
            sum += v;
            if(v > maxval) maxval = v;
        }
        int mid = maxval + (sum - maxval)/2;
        while(maxval <= sum){
            int count = 1;
            int subsum = 0;
            for(int l = 0; l < n ; ++l){
                int m = nums[l];
                if(subsum + m <= mid) subsum += m;
                else{
                    subsum = m;
                    ++count;
                }
            }
            if(count > k) maxval = mid+1;
            else sum = mid - 1;
            mid = maxval + (sum - maxval)/2;
        }
        return maxval;
    }
};