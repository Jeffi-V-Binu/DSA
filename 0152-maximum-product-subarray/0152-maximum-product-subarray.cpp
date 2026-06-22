class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_v = nums[0];
        int negpro = nums[0];
        int n = nums.size();
        if(!n) return 0;
        int pro = nums[0];

        for(int i = 1; i < n ; ++i){
            int curr = nums[i];
            if(curr < 0){
                int temp = pro;
                pro = negpro;
                negpro = temp;
            }
            pro = max(curr, pro*curr);
            negpro = min(curr , negpro*curr);
            max_v = max(max_v , pro);
        }
        return max_v;
    }
};