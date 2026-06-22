class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int k;
        for(int i  = 0 ; i < n ; ++i){
            k = nums[i] - i ;
            if(k > 1 || k < -1){return false;}
        }
        return true;
    }
};