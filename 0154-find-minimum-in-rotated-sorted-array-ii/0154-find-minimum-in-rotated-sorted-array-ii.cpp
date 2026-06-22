class Solution {
public:
    int findMin(vector<int>& nums) {
       int i = 0;
        int n = nums.size();
        int j = n-1;
        int mid = i +(j - i)/ 2;
        if(n == 1) return nums[i];
        if(n == 0) return 0;
        while(nums[i] == nums[j] && nums[j] == nums[mid]){ 
            if((j - i) <= 2){ break; }
            ++i ; 
            --j;}
        while(i < j){
            if(nums[i] < nums[j]) return nums[i];
            else if(nums[i] > nums[mid]) j = mid;
            else if(nums[mid] >= nums[j]) i = mid+1;
            else j = mid;
            mid = i  + (j -i) /2 ;
        }
        return nums[mid]; 
    }
};