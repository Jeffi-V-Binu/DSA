
static const int speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        int count = 0;
        unordered_map<int , int> sums;
        sums.reserve(m);
        sums[0]=1;
        int sum = 0;
        for(int i = 0 ; i < m ; ++i){
            sum += nums[i];
            if(sums.find(sum-k) != sums.end())
                count += sums[sum - k];
            sums[sum]++;
        }
         return count;
    }
};