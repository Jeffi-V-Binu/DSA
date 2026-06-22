class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size() - 1;
        while(j > 0 && nums[j]<=nums[j-1]){--j;}
        int m = 0;
        if(j == 0){
            reverse(nums.begin() , nums.end());}
        else{
            for(int k = j ; k < nums.size(); k++){
                if(nums[k]>nums[j-1]){m = k;}
            }
            int temp = nums[j-1];
            nums[j-1] = nums[m];
            nums[m] = temp;
            reverse(nums.begin() + j, nums.end());
    }}
};