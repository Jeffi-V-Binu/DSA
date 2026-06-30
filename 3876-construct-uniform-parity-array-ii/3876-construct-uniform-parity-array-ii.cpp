class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n < 2) return true;
        int smallnum = 1000000000;
        int oddc  = 0;
        int evenc = 0;
        for(const int& i: nums1){
            smallnum = min(smallnum , i);
            if(i%2 == 0) ++evenc;
            else ++oddc;
        }
        if(smallnum % 2 == 0 && oddc) return false;
        return true;
    }
};