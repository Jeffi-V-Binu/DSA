class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while(n != 0){
            nums.push_back(n%10);
            n /= 10;
        }
        n = nums.size();
        int i = -1;
        for(int j = 0; j < n - 1 ; ++j){
            if(nums[j] > nums[j+1]){
                i = j+1;
                break;
            }
        }
        if(i == -1) return -1;
        int temp;
        for(int k = i - 1 ; k >= 0 ; --k){
            if(nums[k] > nums[i]){
                temp = k;
            }
        }
        int val = nums[temp];
        nums[temp] = nums[i];
        nums[i] = val;
        long long res = 0;
        for(int l = n - 1; l >= i ; --l ){
            res = (res * 10) + nums[l];
            if(res > INT_MAX) return -1;
        }
        for(int l = 0 ; l < i ; ++l){
            res = (res * 10) + nums[l];
            if(res > INT_MAX) return -1;
        }
        
        return res;
    }
};