class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n);
        int val = 1;
        int val1 = 1;
        for(int i = 0 ; i < n ; ++i){
            int possible = 1;
            if(nums1[i] % 2 == 0 ){
                    nums2[i] = nums1[i];
                    possible *= 0;
                }
            else{
            for(int j = 0 ; j < n ; ++j){
                if(j == i ) continue;
                if((nums1[i] - nums1[j]) % 2 == 0){
                    nums2[i] = nums1[i] - nums1[j];
                    possible *= 0;
                    break;
                }
                else
                    possible *= 1;
            }}
            if(possible == 1) { val = 0; break;}
        }
        for(int i = 0 ; i < n ; ++i){
            int possible = 1;
            if(nums1[i] % 2 != 0 ){
                    nums2[i] = nums1[i];
                    possible *= 0;
                }
            else{
            for(int j = 0 ; j < n ; ++j){
                if(j == i ) continue;
                if((nums1[i] - nums1[j]) % 2 != 0){
                    nums2[i] = nums1[i] - nums1[j];
                    possible *= 0;
                    break;
                }
                else
                    possible *= 1;
            }}
            if(possible == 1) {val1 = 0; break; }
        }
        if(val || val1) return true;
        else return false;
    }
};